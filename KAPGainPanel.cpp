/*
  ==============================================================================

    KAPGainPanel.cpp
    Created: 18 Aug 2022 2:55:22pm
    Author:  Benjamin Park

  ==============================================================================
*/

#include "KAPGainPanel.h"
#include "KAPParameters.h"
#include "KAPHelperFunctions.h"

KAPGainPanel::KAPGainPanel(KadenzeAudioPluginAudioProcessor* inProcessor) : KAPPanelBase(inProcessor) {
    setSize(GAIN_PANEL_WIDTH, GAIN_PANEL_HEIGHT);
    
    const int meter_width = 64;
    
    mVuMeter = std::make_unique<KAPVuMeter>(mProcessor);
    mVuMeter->setBounds(getWidth() * 0.5 - meter_width * 0.5, getHeight() * 0.55 - meter_width * 0.5, meter_width, getHeight() * 0.45);
    addAndMakeVisible(mVuMeter.get());
    
}

KAPGainPanel::~KAPGainPanel() {
    
}

void KAPGainPanel::paint(Graphics& g) {
    KAPPanelBase::paint(g);
    
    if(mSlider) {
        paintComponentLabel(g, mSlider.get());
    }
}

void KAPGainPanel::setParameterID(int inParameterID) {
    mSlider = std::make_unique<KAPParameterSlider>(mProcessor->parameters, KAPParameterID[inParameterID]);
    
    const int slider_size = 60;
    
    mSlider->setBounds(getWidth() * 0.5 - slider_size * 0.5, getHeight() * 0.2 - slider_size * 0.5 - 10, slider_size, slider_size);
    addAndMakeVisible(mSlider.get());
    
    mVuMeter->setParameterID(inParameterID);
}
