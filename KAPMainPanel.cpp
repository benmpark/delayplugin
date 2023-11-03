/*
  ==============================================================================

    KAPMainPanel.cpp
    Created: 18 Aug 2022 2:54:45pm
    Author:  Benjamin Park

  ==============================================================================
*/

#include "KAPMainPanel.h"
#include "KAPParameters.h"

KAPMainPanel::KAPMainPanel(KadenzeAudioPluginAudioProcessor* inProcessor) : KAPPanelBase(inProcessor) {
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    mTopPanel = std::make_unique<KAPTopPanel>(inProcessor);
    mTopPanel->setTopLeftPosition(0, 0);
    addAndMakeVisible(mTopPanel.get());
    
    mInputGainPanel = std::make_unique<KAPGainPanel>(inProcessor);
    mInputGainPanel->setTopLeftPosition(0, TOP_PANEL_HEIGHT);
    mInputGainPanel->setParameterID(kParameter_InputGain);
    addAndMakeVisible(mInputGainPanel.get());
    
    mOutputGainPanel = std::make_unique<KAPGainPanel>(inProcessor);
    mOutputGainPanel->setTopLeftPosition(MAIN_PANEL_WIDTH - GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    mOutputGainPanel->setParameterID(kParameter_OutputGain);
    addAndMakeVisible(mOutputGainPanel.get());
    
    mCenterPanel = std::make_unique<KAPCenterPanel>(inProcessor);
    mCenterPanel->setTopLeftPosition(GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    addAndMakeVisible(mCenterPanel.get());
}

KAPMainPanel::~KAPMainPanel() {
    
}
