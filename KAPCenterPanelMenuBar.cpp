/*
  ==============================================================================

    KAPCenterPanelMenuBar.cpp
    Created: 18 Aug 2022 2:55:05pm
    Author:  Benjamin Park

  ==============================================================================
*/

#include "KAPCenterPanelMenuBar.h"
#include "KAPParameters.h"

KAPCenterPanelMenuBar::KAPCenterPanelMenuBar(KadenzeAudioPluginAudioProcessor* inProcessor) : KAPPanelBase(inProcessor) {
    setSize(CENTER_PANEL_MENU_BAR_WIDTH, CENTER_PANEL_MENU_BAR_HEIGHT);
    
    const int comboBox_width = 100;
    const int comboBox_height = CENTER_PANEL_MENU_BAR_HEIGHT;
    
    const StringArray fxTypes = StringArray{"delay", "chorus"};
    
    int value = *inProcessor->parameters.getRawParameterValue(KAPParameterID[kParameter_DelayType]);
    
    mFxTypeComboBox = std::make_unique<KAPParameterComboBox>(mProcessor->parameters, KAPParameterID[kParameter_DelayType]);
    mFxTypeComboBox->addItemList(fxTypes, 1);
    mFxTypeComboBox->setSelectedItemIndex(value, dontSendNotification);
    mFxTypeComboBox->setBounds(CENTER_PANEL_MENU_BAR_WIDTH - comboBox_width, 0, comboBox_width, comboBox_height);
    addAndMakeVisible(mFxTypeComboBox.get());
    
    /*
    mFxTypeComboBox->setBounds(getWidth() - width, 0, width, getHeight());
    mFxTypeComboBox->addItem("DELAY", 1);
    mFxTypeComboBox->addItem("CHORUS", 2);
    // mFxTypeComboBox->setSelectedItemIndex((int)mProcessor->parameters.getRawParameterValue(KAPParameterID[kParameter_DelayType]), dontSendNotification);
    mFxTypeComboBox->setSelectedItemIndex((int)kParameter_DelayType, dontSendNotification);
    addAndMakeVisible(mFxTypeComboBox.get());*/
}

KAPCenterPanelMenuBar::~KAPCenterPanelMenuBar() {
    
}

void KAPCenterPanelMenuBar::addFxTypeComboBoxListener(ComboBox::Listener* inListener) {
    mFxTypeComboBox->addListener(inListener);
}

void KAPCenterPanelMenuBar::removeFxTypeComboBoxListener(ComboBox::Listener* inListener) {
    mFxTypeComboBox->removeListener(inListener);
}

void KAPCenterPanelMenuBar::paint(Graphics& g) {
    KAPPanelBase::paint(g);
    
    g.setColour(juce::Colour::fromHSV (COLOR_HUE, MEDIUM_SATURATION, MEDIUM_BRIGHTNESS, ALPHA));
    g.fillAll();
    g.setColour(Colours::black);
    g.drawRect(0, 0, getWidth(), getHeight());
}

