/*
  ==============================================================================

    KAPInterfaceDefines.h
    Created: 18 Aug 2022 3:11:33pm
    Author:  Benjamin Park

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

#define MAIN_PANEL_WIDTH                750
#define MAIN_PANEL_HEIGHT               300

#define TOP_PANEL_WIDTH                 MAIN_PANEL_WIDTH
#define TOP_PANEL_HEIGHT                50

#define GAIN_PANEL_WIDTH                125
#define GAIN_PANEL_HEIGHT               MAIN_PANEL_HEIGHT - TOP_PANEL_HEIGHT

#define CENTER_PANEL_WIDTH              MAIN_PANEL_WIDTH - 2 * GAIN_PANEL_WIDTH
#define CENTER_PANEL_HEIGHT             GAIN_PANEL_HEIGHT

#define CENTER_PANEL_MENU_BAR_WIDTH     CENTER_PANEL_WIDTH
#define CENTER_PANEL_MENU_BAR_HEIGHT    40

#define FX_PANEL_WIDTH                  CENTER_PANEL_WIDTH
#define FX_PANEL_HEIGHT                 CENTER_PANEL_HEIGHT - CENTER_PANEL_MENU_BAR_HEIGHT

#define COLOR_HUE                       0.50f

#define DARK_SATURATION                 1.00f
#define DARK_BRIGHTNESS                 0.55f

#define MEDIUM_SATURATION               0.51f
#define MEDIUM_BRIGHTNESS               0.50f

#define LIGHT_SATURATION                0.03f
#define LIGHT_BRIGHTNESS                1.00f

#define ALPHA                           1.00f

#define SLIDER_TEXT_BOX_WIDTH           50
#define SLIDER_TEXT_BOX_HEIGHT          20

const Colour KAPColour_1 = Colour(105, 105, 105);
const Colour KAPColour_2 = Colour(0, 0, 0).withAlpha(0.0f);
const Colour KAPColour_3 = Colour(0, 0, 0).withAlpha(0.3f);
const Colour KAPColour_4 = Colour(0, 0, 0).withAlpha(0.6f);
const Colour KAPColour_5 = Colour(105, 105, 105).withAlpha(0.3f);
const Colour KAPColour_6 = Colour(0, 0, 0).withAlpha(0.8f);
const Colour KAPColour_7 = Colour(125, 125, 125);

const Font font_1 ("Helvetica Neue", 12.0f, Font::bold);
const Font font_2 ("Helvetica Neue", 22.0f, Font::bold);
const Font font_3 ("Helvetica Neue", 48.0f, Font::bold);
