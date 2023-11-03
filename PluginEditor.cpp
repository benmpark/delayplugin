/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
KadenzeDelayAudioProcessorEditor::KadenzeDelayAudioProcessorEditor (KadenzeDelayAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (450, 300);
        
        auto& params = processor.getParameters();
        
        juce::AudioParameterFloat* dryWetParameter = (juce::AudioParameterFloat*)params.getUnchecked(0);
        
        mDryWetSlider.setBounds(25, 50, 100, 140);
        mDryWetSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
        mDryWetSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, true, 100, 20);
        mDryWetSlider.setNumDecimalPlacesToDisplay(2);
        mDryWetSlider.setRange(dryWetParameter->range.start, dryWetParameter->range.end);
        mDryWetSlider.setValue(*dryWetParameter);
        mDryWetSlider.setNumDecimalPlacesToDisplay(2);
        addAndMakeVisible(mDryWetSlider);
        
        addAndMakeVisible(dryWetLabel);
        dryWetLabel.setFont(juce::Font (14.0, juce::Font::bold));
        dryWetLabel.setText ("Dry/Wet", juce::dontSendNotification);
        dryWetLabel.setColour (juce::Label::textColourId, juce::Colours::white);
        dryWetLabel.setJustificationType (juce::Justification::centred);
        dryWetLabel.attachToComponent(&mDryWetSlider, false);

        mDryWetSlider.onValueChange = [this, dryWetParameter] {*dryWetParameter = mDryWetSlider.getValue();};
        mDryWetSlider.onDragStart = [dryWetParameter] {dryWetParameter->beginChangeGesture();};
        mDryWetSlider.onDragEnd = [dryWetParameter] {dryWetParameter->endChangeGesture();};
        
        juce::AudioParameterFloat* feedbackParameter = (juce::AudioParameterFloat*)params.getUnchecked(1);
        
        mFeedbackSlider.setBounds(175, 50, 100, 140);
        mFeedbackSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
        mFeedbackSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, true, 100, 20);
        mFeedbackSlider.setNumDecimalPlacesToDisplay(2);
        mFeedbackSlider.setRange(feedbackParameter->range.start, feedbackParameter->range.end);
        mFeedbackSlider.setValue(*feedbackParameter);
        mFeedbackSlider.setNumDecimalPlacesToDisplay(2);
        addAndMakeVisible(mFeedbackSlider);
        
        addAndMakeVisible(feedbackLabel);
        feedbackLabel.setFont(juce::Font (14.0, juce::Font::bold));
        feedbackLabel.setText ("Feedback", juce::dontSendNotification);
        feedbackLabel.setColour (juce::Label::textColourId, juce::Colours::white);
        feedbackLabel.setJustificationType (juce::Justification::centred);
        feedbackLabel.attachToComponent(&mFeedbackSlider, false);
        
        mFeedbackSlider.onValueChange = [this, feedbackParameter] {*feedbackParameter = mFeedbackSlider.getValue();};
        mFeedbackSlider.onDragStart = [feedbackParameter] {feedbackParameter->beginChangeGesture();};
        mFeedbackSlider.onDragEnd = [feedbackParameter] {feedbackParameter->endChangeGesture();};
        
        juce::AudioParameterFloat* delayTimeParameter = (juce::AudioParameterFloat*)params.getUnchecked(2);
        
        mTimeSlider.setBounds(325, 50, 100, 140);
        mTimeSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
        mTimeSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, true, 100, 20);
        mTimeSlider.setNumDecimalPlacesToDisplay(2);
        mTimeSlider.setRange(delayTimeParameter->range.start, delayTimeParameter->range.end);
        mTimeSlider.setValue(*delayTimeParameter);
        mTimeSlider.setNumDecimalPlacesToDisplay(2);
        addAndMakeVisible(mTimeSlider);
        
        addAndMakeVisible(delayLabel);
        delayLabel.setFont(juce::Font (14.0, juce::Font::bold));
        delayLabel.setText ("Delay (s)", juce::dontSendNotification);
        delayLabel.setColour (juce::Label::textColourId, juce::Colours::white);
        delayLabel.setJustificationType (juce::Justification::centred);
        delayLabel.attachToComponent(&mTimeSlider, false);
        
        mTimeSlider.onValueChange = [this, delayTimeParameter] {*delayTimeParameter = mTimeSlider.getValue();};
        mTimeSlider.onDragStart = [delayTimeParameter] {delayTimeParameter->beginChangeGesture();};
        mTimeSlider.onDragEnd = [delayTimeParameter] {delayTimeParameter->endChangeGesture();};
}

KadenzeDelayAudioProcessorEditor::~KadenzeDelayAudioProcessorEditor()
{
}

//==============================================================================
void KadenzeDelayAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::greenyellow);
    g.setFont (20.0);
    g.drawMultiLineText("You may delay, but time will not.\n--Benjamin Franklin", 0, 250, 450, juce::Justification::centred, 3.0f);
}

void KadenzeDelayAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
