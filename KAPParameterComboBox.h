/*
  ==============================================================================

    KAPParameterComboBox.h
    Created: 19 Aug 2022 11:57:30am
    Author:  Benjamin Park

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class KAPParameterComboBox : public ComboBox {
    
public:
    KAPParameterComboBox(AudioProcessorValueTreeState& stateToControl, const String& parameterID);
    ~KAPParameterComboBox();
    
private:
    
    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KAPParameterComboBox);
    
};
