#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class CatFuzzAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                     private juce::Slider::Listener
{
public:
    CatFuzzAudioProcessorEditor (CatFuzzAudioProcessor&);
    ~CatFuzzAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    CatFuzzAudioProcessor& audioProcessor;

    juce::Slider fuzzSlider;
    juce::Slider toneSlider;
    juce::Slider volumeSlider;

    void sliderValueChanged (juce::Slider* slider) override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CatFuzzAudioProcessorEditor)
};