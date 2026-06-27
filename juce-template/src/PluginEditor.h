#pragma once

#include "PluginProcessor.h"

class MonakaiTemplateEditor : public juce::AudioProcessorEditor
{
public:
    explicit MonakaiTemplateEditor(MonakaiTemplateProcessor& processor);

    void paint(juce::Graphics& g) override;
    void resized() override;

private:
    MonakaiTemplateProcessor& processor;
    juce::Slider gainSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MonakaiTemplateEditor)
};
