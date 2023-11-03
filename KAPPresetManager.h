/*
  ==============================================================================

    KAPPresetManager.h
    Created: 22 Aug 2022 11:33:14am
    Author:  Benjamin Park

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

#define PRESET_FILE_EXTENSION ".kpf"

class KAPPresetManager {
  
public:
    
    KAPPresetManager(AudioProcessor* inProcessor);
    ~KAPPresetManager();
    
    void getXmlForPreset(XmlElement* inElement);
    
    void loadPresetForXml(XmlElement* inElement);
    
    int getNumberOfPresets();
    
    String getPresetName(int inPresetIndex);
    
    void createNewPreset();
    void savePreset();
    void saveAsPreset(String inPresetName);
    void loadPreset(int inPresetIndex);
    
    bool getIsCurrentPresetSaved();
    
    String getCurrentPresetName();
    
    
private:
    
    void storeLocalPreset();
    
    bool mCurrentPresetIsSaved;
    
    File mCurrentlyLoadedPreset;
    
    Array<File> mLocalPresets;
    
    String mCurrentPresetName;
    String mPresetDirectory;
    
    XmlElement* mCurrentPresetXml;
    
    AudioProcessor* mProcessor;
    
};
