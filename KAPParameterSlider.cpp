/*
  ==============================================================================

    KAPParameterSlider.cpp
    Created: 19 Aug 2022 11:57:16am
    Author:  Benjamin Park

  ==============================================================================
*/

#include "KAPParameterSlider.h"
#include "KAPInterfaceDefines.h"

KAPParameterSlider::KAPParameterSlider(AudioProcessorValueTreeState& stateToControl, const String& parameterID) : juce::Slider(parameterID) {
    setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
    setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 0, 0);
    setRange(0.0f, 1.0f, 0.001f);
    
    mAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(stateToControl, parameterID, *this);
}

KAPParameterSlider::~KAPParameterSlider() {
    
}
