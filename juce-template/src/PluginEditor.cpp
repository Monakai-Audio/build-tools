#include "PluginEditor.h"

MonakaiTemplateEditor::MonakaiTemplateEditor(MonakaiTemplateProcessor& p)
    : AudioProcessorEditor(&p), processor(p)
{
    gainSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    gainSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(gainSlider);

    setSize(400, 300);
}

void MonakaiTemplateEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::darkgrey);
    g.setColour(juce::Colours::white);
    g.setFont(15.0f);
    g.drawFittedText("Monakai Template Plugin", getLocalBounds(),
                     juce::Justification::centredTop, 1);
}

void MonakaiTemplateEditor::resized()
{
    gainSlider.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 50, 100, 100);
}
