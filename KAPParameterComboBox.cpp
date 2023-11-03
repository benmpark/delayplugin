/*
  ==============================================================================

    KAPParameterComboBox.cpp
    Created: 19 Aug 2022 11:57:30am
    Author:  Benjamin Park

  ==============================================================================
*/

#include "KAPParameterComboBox.h"

KAPParameterComboBox::KAPParameterComboBox(AudioProcessorValueTreeState& stateToControl, const String& parameterID) : juce::ComboBox(parameterID) {
    mAttachment = std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment>(stateToControl, parameterID, *this);
}

KAPParameterComboBox::~KAPParameterComboBox() {
    
}
