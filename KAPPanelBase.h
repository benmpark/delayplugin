/*
  ==============================================================================

    KAPPanelBase.h
    Created: 18 Aug 2022 2:54:36pm
    Author:  Benjamin Park

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "KAPInterfaceDefines.h"

class KAPPanelBase : public Component {
    
public:
    
    KAPPanelBase(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPPanelBase();
    
    void mouseEnter (const MouseEvent& event) override;

    void mouseExit (const MouseEvent& event) override;
    
    void paint(Graphics& g) override;
    
protected:
    
    KadenzeAudioPluginAudioProcessor* mProcessor;
    
};
