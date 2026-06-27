# Fetch or reuse a local copy of the JUCE framework.
#
# If JUCE_SOURCE_DIR is already defined, this module does nothing and lets the
# consumer supply JUCE. Otherwise, it downloads the official JUCE repository via
# FetchContent.

if(NOT DEFINED JUCE_SOURCE_DIR)
    include(FetchContent)
    FetchContent_Declare(
        JUCE
        GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
        GIT_TAG        7.0.12
        GIT_SHALLOW    TRUE
    )
    FetchContent_MakeAvailable(JUCE)
endif()
