# Cross-Platform Build Guide

This guide explains how to build JUCE-based Monakai Audio projects on Windows
11, Ubuntu, and macOS using the helpers in this repository.

> **Proprietary notice:** DSP algorithms and premium content remain proprietary
> to Monakai Audio.

## Windows 11

1. Install **Visual Studio 2022** with the **Desktop development with C++**
   workload.
2. Install **CMake** 3.22 or newer.
3. Open a PowerShell prompt and run:
   ```powershell
   .\scripts\Build-Windows.ps1 -ProjectDir ".\juce-template" -Configuration Release
   ```

## Ubuntu 22.04+

1. Install the build toolchain and JUCE dependencies:
   ```bash
   sudo apt-get update
   sudo apt-get install -y build-essential cmake git \
     libasound2-dev libjack-jackd2-dev ladspa-sdk libcurl4-openssl-dev \
     libfreetype6-dev libx11-dev libxcomposite-dev libxcursor-dev \
     libxext-dev libxinerama-dev libxrandr-dev libxrender-dev \
     libwebkit2gtk-4.1-dev libglu1-mesa-dev mesa-common-dev
   ```
2. Configure and build:
   ```bash
   cd juce-template
   cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
   cmake --build build --parallel 4
   ```

## macOS 13+

1. Install Xcode and the command-line tools.
2. Configure and build:
   ```bash
   cd juce-template
   cmake -S . -B build -G Xcode -DCMAKE_BUILD_TYPE=Release
   cmake --build build --config Release --parallel 4
   ```

## Using the cache configs

Each config file sets a consistent generator, compiler, and C++ standard. Use
`-C` during the first configure step:

```bash
cmake -S . -B build -C /path/to/build-tools/configs/ubuntu-gcc.cmake
```
