cmake_minimum_required(VERSION 3.22)

# Set a modern C++ standard on a target.
function(monakai_set_cxx_standard target)
    target_compile_features(${target} PUBLIC cxx_std_17)
    set_target_properties(${target} PROPERTIES CXX_EXTENSIONS OFF)
endfunction()

# Enable sensible compiler warnings without treating them as errors.
function(monakai_enable_warnings target)
    if(MSVC)
        target_compile_options(${target} PRIVATE /W4 /WX-)
    else()
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endfunction()

# Apply common JUCE plug-in compile definitions and recommended flags.
function(monakai_configure_juce_plugin target)
    target_compile_definitions(${target} PRIVATE
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
    )
    target_link_libraries(${target} PRIVATE
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
    )
endfunction()
