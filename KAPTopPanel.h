/*
  ==============================================================================

    KAPTopPanel.h
    Created: 18 Aug 2022 2:55:56pm
    Author:  Benjamin Park

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"

class KAPTopPanel : public KAPPanelBase {
    
public:
    
    KAPTopPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPTopPanel();
    
    void paint(Graphics& g) override;
    
    //void buttonClicked(Button*) override;
    
    //void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override;
    
private:
    
    void displaySaveAsPopup();
    
    void updatePresetComboBox();
    
    std::unique_ptr<ComboBox> mPresetDisplay;
    std::unique_ptr<TextButton> mNewPreset, mSavePreset, mSaveAsPreset;
    
};
