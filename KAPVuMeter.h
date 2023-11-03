/*
  ==============================================================================

    KAPVuMeter.h
    Created: 22 Aug 2022 8:11:02pm
    Author:  Benjamin Park

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"

class KAPVuMeter : public Component, public Timer {
  
public:
    
    KAPVuMeter(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPVuMeter();
    
    void paint(Graphics& g) override;
    
    void timerCallback() override;
    
    void setParameterID(int inParameterID);
    
private:
    
    int mParameterID;
    
    float mCh0Level;
    float mCh1Level;
    
    KadenzeAudioPluginAudioProcessor* mProcessor;

};
