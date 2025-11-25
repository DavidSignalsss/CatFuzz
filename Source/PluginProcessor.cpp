#include "PluginProcessor.h"
#include "PluginEditor.h"

CatFuzzAudioProcessor::CatFuzzAudioProcessor()
{
}

CatFuzzAudioProcessor::~CatFuzzAudioProcessor()
{
}

const juce::String CatFuzzAudioProcessor::getName() const
{
    return "CatFuzz";
}

bool CatFuzzAudioProcessor::acceptsMidi() const
{
    return false;
}

bool CatFuzzAudioProcessor::producesMidi() const
{
    return false;
}

bool CatFuzzAudioProcessor::isMidiEffect() const
{
    return false;
}

double CatFuzzAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int CatFuzzAudioProcessor::getNumPrograms()
{
    return 1;
}

int CatFuzzAudioProcessor::getCurrentProgram()
{
    return 0;
}

void CatFuzzAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String CatFuzzAudioProcessor::getProgramName (int index)
{
    return {};
}

void CatFuzzAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

void CatFuzzAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
}

void CatFuzzAudioProcessor::releaseResources()
{
}

bool CatFuzzAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    return true;
}

void CatFuzzAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    // EFECTO FUZZ SIMPLE PERO FUNCIONAL
    for (int channel = 0; channel < buffer.getNumChannels(); ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            float input = channelData[sample];
            
            // FUZZ BÁSICO - ¡FUNCIONA!
            float distorted = input * (fuzzAmount * 20.0f + 1.0f);
            
            // Clipping suave
            distorted = std::tanh(distorted);
            
            // Control de tono simple
            if (toneAmount > 0.5f) {
                distorted *= (1.0f + (toneAmount - 0.5f) * 2.0f); // Más brillo
            } else {
                distorted *= (toneAmount * 2.0f); // Más grave
            }
            
            // Volumen
            channelData[sample] = distorted * (volumeAmount * 2.0f);
        }
    }
}

bool CatFuzzAudioProcessor::hasEditor() const
{
    return true;
}

juce::AudioProcessorEditor* CatFuzzAudioProcessor::createEditor()
{
    return new CatFuzzAudioProcessorEditor (*this);
}

void CatFuzzAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
}

void CatFuzzAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new CatFuzzAudioProcessor();
}