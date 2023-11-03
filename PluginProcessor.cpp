/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "KAPParameters.h"

AudioProcessorValueTreeState::ParameterLayout createParameterLayout()
{
    std::vector<std::unique_ptr<AudioParameterFloat>> params;
    
    for(int i = 0; i < kParameter_TotalNumParameters; i++){
        
        /*params.push_back(std::make_unique<AudioParameterFloat>(KAPParameterID[i],
                                                               KAPParameterLabel[i],
                                                               NormalisableRange<float> (0.0f, 1.0f),
                                                               KAPParameterDefaultValue[i]));*/
    }
    
    return { params.begin(), params.end() };
}

//==============================================================================
KadenzeAudioPluginAudioProcessor::KadenzeAudioPluginAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ),
        parameters(*this, nullptr, juce::Identifier("KAP"), createParameterLayout())
#endif
{
    //initializeParameters();
    
    initializeDSP();
    
    mPresetManager = std::make_unique<KAPPresetManager>(this);
}

KadenzeAudioPluginAudioProcessor::~KadenzeAudioPluginAudioProcessor()
{
}

//==============================================================================
const juce::String KadenzeAudioPluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool KadenzeAudioPluginAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool KadenzeAudioPluginAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool KadenzeAudioPluginAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double KadenzeAudioPluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int KadenzeAudioPluginAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int KadenzeAudioPluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void KadenzeAudioPluginAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String KadenzeAudioPluginAudioProcessor::getProgramName (int index)
{
    return {};
}

void KadenzeAudioPluginAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void KadenzeAudioPluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    for (int i = 0; i < 2; i++) {
        mDelay[i]->setSampleRate(sampleRate);
        mLfo[i]->setSampleRate(sampleRate);
    }
}

void KadenzeAudioPluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
    
    for (int i = 0; i < 2; i++) {
        mDelay[i]->reset();
        mLfo[i]->reset();
    }
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool KadenzeAudioPluginAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void KadenzeAudioPluginAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        const int numSamplesToRender = buffer.getNumSamples();

        //mInputGain[channel]->KAPGain::process(channelData, getParameter(kParameter_InputGain), channelData, buffer.getNumSamples());
        mInputGain[channel]->process(channelData, *parameters.getRawParameterValue(KAPParameterID[kParameter_InputGain]), channelData, numSamplesToRender);
        
        //float rate = (channel==0) ? 0 : getParameter(kParameter_ModulationRate);
        
        //mLfo[channel]->process(rate, getParameter(kParameter_ModulationDepth), buffer.getNumSamples());
        
        float rate = 0;
        
        if(channel==1) {
            rate = *parameters.getRawParameterValue(KAPParameterID[kParameter_ModulationRate]);
        }
        
        mLfo[channel]->process(rate, *parameters.getRawParameterValue(KAPParameterID[kParameter_ModulationDepth]), numSamplesToRender);
        
        //mDelay[channel]->KAPDelay::process(channelData, getParameter(kParameter_DelayTime), getParameter(kParameter_DelayFeedback), getParameter(kParameter_DelayWetDry), mLfo[channel]->getBuffer(), channelData, buffer.getNumSamples());
        mDelay[channel]->process(channelData, *parameters.getRawParameterValue(KAPParameterID[kParameter_DelayTime]), *parameters.getRawParameterValue(KAPParameterID[kParameter_DelayFeedback]), *parameters.getRawParameterValue(KAPParameterID[kParameter_DelayWetDry]), *parameters.getRawParameterValue(KAPParameterID[kParameter_DelayType]), mLfo[channel]->getBuffer(), channelData, numSamplesToRender);
        
        
        //mOutputGain[channel]->KAPGain::process(channelData, getParameter(kParameter_OutputGain), channelData, buffer.getNumSamples());
        mOutputGain[channel]->process(channelData, *parameters.getRawParameterValue(KAPParameterID[kParameter_OutputGain]), channelData, numSamplesToRender);
    }
}

//==============================================================================
bool KadenzeAudioPluginAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* KadenzeAudioPluginAudioProcessor::createEditor()
{
    return new KadenzeAudioPluginAudioProcessorEditor (*this);
}

//==============================================================================
void KadenzeAudioPluginAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    
    XmlElement preset("KAP_StateInfo");
    XmlElement* presetBody = new XmlElement("KAP_Preset");
    
    mPresetManager->getXmlForPreset(presetBody);
    preset.addChildElement(presetBody);
    copyXmlToBinary(preset, destData);
}

void KadenzeAudioPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    
    const auto xmlState = getXmlFromBinary(data, sizeInBytes);
    
    jassert (xmlState.get() != nullptr);
    
    for(auto* subchild : xmlState->getChildIterator()){
        mPresetManager->loadPresetForXml(subchild);
    }
}

KAPPresetManager* KadenzeAudioPluginAudioProcessor::getPresetManager()
{
    return mPresetManager.get();
}

float KadenzeAudioPluginAudioProcessor::getInputGainMeterLevel(int inChannel) {
    const float normalizeddB = dBToNormalizedGain(mInputGain[inChannel]->getMeterLevel());
    
    return normalizeddB;
}

float KadenzeAudioPluginAudioProcessor::getOutputGainMeterLevel(int inChannel) {
    const float normalizeddB = dBToNormalizedGain(mOutputGain[inChannel]->getMeterLevel());

    return normalizeddB;
}

void KadenzeAudioPluginAudioProcessor::initializeDSP() {
    for (int i = 0; i < 2; i++) {
        mInputGain[i] = std::make_unique<KAPGain>();
        mOutputGain[i] = std::make_unique<KAPGain>();
        mDelay[i] = std::make_unique<KAPDelay>();
        mLfo[i] = std::make_unique<KAPLfo>();
    }
}

void KadenzeAudioPluginAudioProcessor::initializeParameters() {
    /*for(int i = 0; i < kParameter_TotalNumParameters; i++) {
        parameters.createAndAddParameter(KAPParameterID[i], KAPParameterID[i], KAPParameterID[i], NormalisableRange<float>(0.0f, 1.0f), 0.5f, nullptr, nullptr);
    }*/
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new KadenzeAudioPluginAudioProcessor();
}
