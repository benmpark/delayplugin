/*
  ==============================================================================

    KAPTopPanel.cpp
    Created: 18 Aug 2022 2:55:56pm
    Author:  Benjamin Park

  ==============================================================================
*/

#include "KAPTopPanel.h"

KAPTopPanel::KAPTopPanel(KadenzeAudioPluginAudioProcessor* inProcessor) : KAPPanelBase(inProcessor) {
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    
    int button_x = 15;
    int button_y = 10;
    int button_w = 55;
    int button_h = 25;
    
    mNewPreset = std::make_unique<TextButton>("NEW");
    mNewPreset->setBounds(button_x, button_y, button_w, button_h);
    mNewPreset->onClick = [this]{
        mProcessor->getPresetManager()->createNewPreset();
        updatePresetComboBox();
    };
    addAndMakeVisible(mNewPreset.get());
    button_x += button_w;
    
    mSavePreset = std::make_unique<TextButton>("SAVE");
    mSavePreset->setBounds(button_x, button_y, button_w, button_h);
    mSavePreset->onClick = [this]{
        if(mProcessor->getPresetManager()->getIsCurrentPresetSaved()){
            mProcessor->getPresetManager()->savePreset();
        } else {
            displaySaveAsPopup();
        }
        updatePresetComboBox();
    };
    addAndMakeVisible(mSavePreset.get());
    button_x = button_x + button_w;
    
    mSaveAsPreset = std::make_unique<TextButton>("SAVE AS");
    mSaveAsPreset->setBounds(button_x, button_y, button_w, button_h);
    mSaveAsPreset->onClick = [this]{
        displaySaveAsPopup();
        updatePresetComboBox();
    };
    addAndMakeVisible(mSaveAsPreset.get());

    
    const int comboBox_w = 200;
    const int comboBox_x = TOP_PANEL_WIDTH * 0.5 - comboBox_w * 0.5;
    
    mPresetDisplay = std::make_unique<ComboBox>();
    mPresetDisplay->setBounds(comboBox_x, button_y, comboBox_w, button_h);
    mSaveAsPreset->onClick = [this]{
        displaySaveAsPopup();
        updatePresetComboBox();
    };
    addAndMakeVisible(mPresetDisplay.get());
    
    updatePresetComboBox();
}

KAPTopPanel::~KAPTopPanel() {
    
}

void KAPTopPanel::paint(Graphics& g) {
    KAPPanelBase::paint(g);
    
    /*
    g.setColour(juce::Colour::fromHSV (COLOR_HUE, DARK_SATURATION, DARK_BRIGHTNESS, ALPHA));
    g.fillAll();
    g.setColour(juce::Colour::fromHSV (COLOR_HUE, LIGHT_SATURATION, LIGHT_BRIGHTNESS, ALPHA));
    */
    
    g.setColour(KAPColour_1);
    g.setFont(font_2);
    
    const int label_w = 220;
    
    g.drawFittedText("GO with the LFO", TOP_PANEL_WIDTH - label_w, 0, label_w, getHeight(), Justification::centredRight, 1);
    
}


/*void KAPTopPanel::comboBoxChanged(ComboBox* comboBoxThatHasChanged) {
    
}*/

void KAPTopPanel::displaySaveAsPopup() {
    KAPPresetManager* presetManager = mProcessor->getPresetManager();
    String currentPresetName = presetManager->getCurrentPresetName();
    
    if(presetManager->getIsCurrentPresetSaved()){
        currentPresetName = currentPresetName + "_2";
    }
    
    AlertWindow window ("Save As","Please enter a name for your preset.", AlertWindow::NoIcon);
    window.centreAroundComponent(this, getWidth(), getHeight());
    window.addTextEditor("presetName", currentPresetName, "preset name:");
    window.addButton("Confirm", 1);
    window.addButton("Cancel", 0);
    
    /** confirm has been clicked, and we exit modal loop*/
    if(window.runModalLoop() != 0){
        String presetName = window.getTextEditor("presetName")->getText();
        presetManager->saveAsPreset(presetName);
        
        updatePresetComboBox();
    }
}

void KAPTopPanel::updatePresetComboBox() {
    KAPPresetManager* presetManager = mProcessor->getPresetManager();
    String presetName = presetManager->getCurrentPresetName();
    
    mPresetDisplay->clear(dontSendNotification);
        
    const int numPresets = presetManager->getNumberOfPresets();
    for(int i = 0; i < numPresets; i++){
        mPresetDisplay->addItem(presetManager->getPresetName(i), (i+1));
    }
    
    mPresetDisplay->setText(presetName, dontSendNotification);}


