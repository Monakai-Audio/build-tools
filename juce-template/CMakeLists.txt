cmake_minimum_required(VERSION 3.22)
project(MonakaiTemplatePlugin VERSION 1.0.0 LANGUAGES CXX)

# When this template is copied out of the build-tools repo, update the path
# below to point to your local build-tools/cmake directory.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")

include(MonakaiBuildUtils)
include(FindJUCE)

juce_add_plugin(MonakaiTemplatePlugin
    COMPANY_NAME "Monakai Audio"
    COMPANY_EMAIL "hello@monakaiaudio.com"
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT TRUE
    NEEDS_MIDI_OUTPUT FALSE
    PLUGIN_MANUFACTURER_CODE Mnki
    PLUGIN_CODE Tmpl
    FORMATS VST3 Standalone
    PRODUCT_NAME "Monakai Template Plugin"
)

target_sources(MonakaiTemplatePlugin
    PRIVATE
        src/PluginProcessor.cpp
        src/PluginEditor.cpp
)

monakai_set_cxx_standard(MonakaiTemplatePlugin)
monakai_enable_warnings(MonakaiTemplatePlugin)
monakai_configure_juce_plugin(MonakaiTemplatePlugin)

target_link_libraries(MonakaiTemplatePlugin
    PRIVATE
        juce::juce_audio_utils
        juce::juce_dsp
)
