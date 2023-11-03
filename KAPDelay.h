/*
  ==============================================================================

    KAP_Delay.h
    Created: 4 Aug 2022 4:45:45pm
    Author:  Benjamin Park

  ==============================================================================
*/

#pragma once

#include "KAPAudioHelpers.h"

enum KAPDelayType {
    kKAPDelayType_Delay = 0,
    kKAPDelayType_Chorus
};

class KAPDelay {
  
public:
    
    KAPDelay();
    ~KAPDelay();
    
    void setSampleRate(double inSampleRate);
    
    void reset();
    
    void process(float* inAudio, float inTime, float inFeedback, float inWetDry, float inType, float* inModulationBuffer, float* outAudio, int inNumSamplesToRender);
    
private:
    
    double getInterpolatedSample(float inDelayTimeInSampes); // Internal
    
    double mSampleRate;
    double mBuffer[maxBufferDelaySize];
    double mFeedbackSample;
    
    float mTimeSmoothed;
    
    int mDelayIndex;
    
};
