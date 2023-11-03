/*
  ==============================================================================

    KAPParameterSlider.h
    Created: 19 Aug 2022 11:57:16am
    Author:  Benjamin Park

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class KAPParameterSlider : public Slider {
    
public:
    
    KAPParameterSlider(AudioProcessorValueTreeState& stateToControl, const String& parameterID);
    ~KAPParameterSlider();
    
private:
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KAPParameterSlider);
    
};
