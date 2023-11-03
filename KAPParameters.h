/*
  ==============================================================================

    KAPParameters.h
    Created: 19 Aug 2022 11:12:48am
    Author:  Benjamin Park

  ==============================================================================
*/

#pragma once

enum KAPParameter {
    kParameter_InputGain = 0,
    kParameter_DelayTime,
    kParameter_DelayFeedback,
    kParameter_DelayWetDry,
    kParameter_DelayType,
    kParameter_OutputGain,
    kParameter_ModulationRate,
    kParameter_ModulationDepth,
    kParameter_TotalNumParameters,
};

static String KAPParameterID [kParameter_TotalNumParameters] = {
    "InputGain",
    "Time",
    "Feedback",
    "WetDry",
    "Type",
    "OutputGain",
    "ModulationRate",
    "ModulationDepth",
};
