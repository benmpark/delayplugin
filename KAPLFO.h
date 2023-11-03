/*
  ==============================================================================

    KAP_LFO.h
    Created: 4 Aug 2022 4:45:16pm
    Author:  Benjamin Park

  ==============================================================================
*/

#pragma once

#include "KAPAudioHelpers.h"

class KAPLfo {
    
public:
    
    KAPLfo();
    ~KAPLfo();
    
    void reset();
    
    void setSampleRate(double inSampleRate);
    
    void process(float inRate, float inDepth, int inNumSamples);
    
    float* getBuffer();
    
private:
    
    double mSampleRate;
    
    float mPhase;
    
    float mBuffer[maxBufferDelaySize];
    
};
