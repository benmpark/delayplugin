/*
  ==============================================================================

    KAPCenterPanel.h
    Created: 18 Aug 2022 2:54:55pm
    Author:  Benjamin Park

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"
#include "KAPCenterPanelMenuBar.h"
#include "KAPFxPanel.h"

class KAPCenterPanel : public KAPPanelBase {

public:
    
    KAPCenterPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPCenterPanel();
    
    void paint(Graphics& g) override;
    
private:
    
    std::unique_ptr<KAPCenterPanelMenuBar> mCenterPanelMenuBar;
    std::unique_ptr<KAPFxPanel> mKAPFxPanel;
};
