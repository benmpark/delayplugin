/*
  ==============================================================================

    KAPCenterPanel.cpp
    Created: 18 Aug 2022 2:54:55pm
    Author:  Benjamin Park

  ==============================================================================
*/

#include "KAPCenterPanel.h"

KAPCenterPanel::KAPCenterPanel(KadenzeAudioPluginAudioProcessor* inProcessor) : KAPPanelBase(inProcessor) {
    setSize(CENTER_PANEL_WIDTH, CENTER_PANEL_HEIGHT);
    
    mCenterPanelMenuBar = std::make_unique<KAPCenterPanelMenuBar>(inProcessor);
    mCenterPanelMenuBar->setTopLeftPosition(0, 0);
    mCenterPanelMenuBar->addFxTypeComboBoxListener(mKAPFxPanel.get());
    addAndMakeVisible(mCenterPanelMenuBar.get());
    
    mKAPFxPanel = std::make_unique<KAPFxPanel>(inProcessor);
    mKAPFxPanel->setTopLeftPosition(0, CENTER_PANEL_MENU_BAR_HEIGHT);
    addAndMakeVisible(mKAPFxPanel.get());
    
}

KAPCenterPanel::~KAPCenterPanel() {
    mCenterPanelMenuBar->removeFxTypeComboBoxListener(mKAPFxPanel.get());
}

void KAPCenterPanel::paint(Graphics& g) {
    KAPPanelBase::paint(g);
    
    g.setColour(juce::Colour::fromHSV (COLOR_HUE, LIGHT_SATURATION, LIGHT_BRIGHTNESS, ALPHA));
    g.fillAll();
    g.setColour(Colours::black);
    g.drawRect(0, 0, getWidth(), getHeight());
}
