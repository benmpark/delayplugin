/*
  ==============================================================================

    KAP_LFO.cpp
    Created: 4 Aug 2022 4:45:16pm
    Author:  Benjamin Park

  ==============================================================================
*/

#include "KAPLFO.h"
#include "JuceHeader.h"

KAPLfo::KAPLfo() {
    reset();
}

KAPLfo::~KAPLfo() {
    
}

void KAPLfo::reset() {
    mPhase = 0.0f;
    zeromem(mBuffer, sizeof(float) * maxBufferDelaySize);

}

void KAPLfo::setSampleRate(double inSampleRate) {
    mSampleRate = inSampleRate;
}

void KAPLfo::process(float inRate, float inDepth, int inNumSamples) {
    const float rate = jmap(inRate, 0.0f, 1.0f, 0.01f, 10.0f);
    
    for(int i = 0; i < inNumSamples; i++) {
        mPhase += (rate / mSampleRate);
    
        if(mPhase > 1.0f) {
            mPhase -= 1.0f;
        }
        
        const float lfoPosition = sinf(mPhase * k2PI * inDepth);
        mBuffer[i] = lfoPosition;
    }
}

float* KAPLfo::getBuffer() {
    return mBuffer;
}
