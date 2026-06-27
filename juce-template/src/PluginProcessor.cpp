#include "PluginProcessor.h"
#include "PluginEditor.h"

MonakaiTemplateProcessor::MonakaiTemplateProcessor()
    : AudioProcessor(BusesProperties()
                         .withInput("Input", juce::AudioChannelSet::stereo(), true)
                         .withOutput("Output", juce::AudioChannelSet::stereo(), true))
{
}

MonakaiTemplateProcessor::~MonakaiTemplateProcessor() = default;

void MonakaiTemplateProcessor::prepareToPlay(double /*sampleRate*/, int /*samplesPerBlock*/)
{
}

void MonakaiTemplateProcessor::releaseResources()
{
}

bool MonakaiTemplateProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;

    return !layouts.getMainInputChannelSet().isDisabled();
}

void MonakaiTemplateProcessor::processBlock(juce::AudioBuffer<float>& buffer,
                                            juce::MidiBuffer& /*midiMessages*/)
{
    juce::ScopedNoDenormals noDenormals;

    for (int channel = 0; channel < buffer.getNumChannels(); ++channel)
    {
        auto* channelData = buffer.getWritePointer(channel);

        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            // Pass-through: no proprietary DSP.
            channelData[sample] = channelData[sample];
        }
    }
}

juce::AudioProcessorEditor* MonakaiTemplateProcessor::createEditor()
{
    return new MonakaiTemplateEditor(*this);
}

bool MonakaiTemplateProcessor::hasEditor() const
{
    return true;
}

const juce::String MonakaiTemplateProcessor::getName() const
{
    return "Monakai Template Plugin";
}

bool MonakaiTemplateProcessor::acceptsMidi() const
{
    return true;
}

bool MonakaiTemplateProcessor::producesMidi() const
{
    return false;
}

bool MonakaiTemplateProcessor::isMidiEffect() const
{
    return false;
}

double MonakaiTemplateProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MonakaiTemplateProcessor::getNumPrograms()
{
    return 1;
}

int MonakaiTemplateProcessor::getCurrentProgram()
{
    return 0;
}

void MonakaiTemplateProcessor::setCurrentProgram(int /*index*/)
{
}

const juce::String MonakaiTemplateProcessor::getProgramName(int /*index*/)
{
    return {};
}

void MonakaiTemplateProcessor::changeProgramName(int /*index*/, const juce::String& /*newName*/)
{
}

void MonakaiTemplateProcessor::getStateInformation(juce::MemoryBlock& /*destData*/)
{
}

void MonakaiTemplateProcessor::setStateInformation(const void* /*data*/, int /*sizeInBytes*/)
{
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MonakaiTemplateProcessor();
}
