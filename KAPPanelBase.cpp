/*
  ==============================================================================

    KAPPanelBase.cpp
    Created: 18 Aug 2022 2:54:36pm
    Author:  Benjamin Park

  ==============================================================================
*/

#include "KAPPanelBase.h"
#include "KAPInterfaceDefines.h"

KAPPanelBase::KAPPanelBase(KadenzeAudioPluginAudioProcessor* inProcessor) : mProcessor(inProcessor) {
    
}
                                                                                       
KAPPanelBase::~KAPPanelBase() {
    
}

void KAPPanelBase::mouseEnter (const MouseEvent& event) {
    repaint();
}

void KAPPanelBase::mouseExit (const MouseEvent& event) {
    repaint();
}

void KAPPanelBase::paint(Graphics& g) {
    /*
    g.setGradientFill(ColourGradient(juce::Colour::fromHSV (COLOR_HUE, DARK_SATURATION, DARK_BRIGHTNESS, ALPHA), 0, 0, juce::Colour::fromHSV (COLOR_HUE, LIGHT_SATURATION, LIGHT_BRIGHTNESS, ALPHA), getWidth(), getHeight(), false));
    g.fillAll();
    g.setColour(Colours::black);
    g.drawRect(0, 0, getWidth(), getHeight());
    */
    
    if(isMouseOver()) {
        // g.setColour(KAPColour_4);
        // g.fillAll();
    } else {
        
    }
}
