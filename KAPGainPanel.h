/*
  ==============================================================================

    KAPGainPanel.h
    Created: 18 Aug 2022 2:55:22pm
    Author:  Benjamin Park

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"
#include "KAPParameterSlider.h"
#include "KAPVuMeter.h"

class KAPGainPanel : public KAPPanelBase {
    
public:
    
    KAPGainPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPGainPanel();
    
    void paint(Graphics& g) override;
    
    void setParameterID(int inParameterID);
    
private:
    
    std::unique_ptr<KAPParameterSlider> mSlider;
    std::unique_ptr<KAPVuMeter> mVuMeter;

    
};
