/*
  ==============================================================================

    KAP_Gain.h
    Created: 4 Aug 2022 4:45:27pm
    Author:  Benjamin Park

  ==============================================================================
*/

#pragma once

class KAPGain {

public:

    KAPGain();
    ~KAPGain();
    
    void process(float* inAudio, float inGain, float* outAudio, int inNumSamplesToRender);
    
    float getMeterLevel();
    
private:
    
    float mOutputSmoothed;
};
