/*
  ==============================================================================

    KAPHelperFunctions.h
    Created: 19 Aug 2022 2:22:05pm
    Author:  Benjamin Park

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "KAPInterfaceDefines.h"

inline void paintComponentLabel(Graphics& g, Component* inComponent) {
    const int x = inComponent->getX() - (inComponent->getWidth() * 0.25f);
    const int y = inComponent->getY() + inComponent->getHeight();
    const int w = inComponent->getWidth() * 1.5f;
    const int h = SLIDER_TEXT_BOX_HEIGHT;
    
    const float cornerSize = 3.0f;
    
    const String label = inComponent->getName();
    
    g.setColour(KAPColour_3);
    g.fillRoundedRectangle(x, y, w, h, cornerSize);
    
    g.setColour(KAPColour_1);
    g.setFont(font_1);
    
    g.drawFittedText(label, x, y, w, h, Justification::centred, 1);
}
