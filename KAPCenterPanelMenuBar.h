/*
  ==============================================================================

    KAPCenterPanelMenuBar.h
    Created: 18 Aug 2022 2:55:05pm
    Author:  Benjamin Park

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"
#include "KAPParameterComboBox.h"

class KAPCenterPanelMenuBar : public KAPPanelBase {

public:
    
    KAPCenterPanelMenuBar(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPCenterPanelMenuBar();
    
    void addFxTypeComboBoxListener(ComboBox::Listener* inListener);
    void removeFxTypeComboBoxListener(ComboBox::Listener* inListener);
    
    void paint(Graphics& g) override;
    
private:
    
    std::unique_ptr<KAPParameterComboBox> mFxTypeComboBox;
    
};
