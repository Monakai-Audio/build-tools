# Monakai Audio Build Tools

![CI](https://github.com/monakai-audio/build-tools/actions/workflows/ci.yml/badge.svg)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](./LICENSE)

Shared CMake build scripts, JUCE project templates, cross-platform compilation
configurations, and PowerShell build helpers for Monakai Audio open-source
projects.

> **Proprietary notice:** DSP algorithms and premium content remain proprietary
> to Monakai Audio. This repository only contains build infrastructure and
> project templates.

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Repository structure](#repository-structure)
- [Contributing](#contributing)
- [Security](#security)
- [License](#license)

## Features

- CMake 3.22+ helper modules
- JUCE 7+ audio plug-in template (VST3 + Standalone)
- Tool-chain configs for Windows 11 / Visual Studio 2022, Ubuntu / GCC, and
  macOS / Xcode
- `Build-Windows.ps1` build helper
- Cross-platform build guide and troubleshooting documentation

## Requirements

- CMake 3.22 or newer
- JUCE 7 or newer (fetched automatically by the template)
- One of:
  - Windows 11 + Visual Studio 2022
  - Ubuntu 22.04+ + GCC
  - macOS 13+ + Xcode

## Installation

```bash
git clone https://github.com/monakai-audio/build-tools.git
cd build-tools
```

No build step is required for this repository; it is consumed as a CMake module
collection and template source.

## Usage

### Using the JUCE plug-in template

```bash
# Copy the template to a new project
cp -R juce-template ../my-plugin
cd ../my-plugin

# Configure with the appropriate cross-platform config
cmake -S . -B build -C /path/to/build-tools/configs/windows-vs2022.cmake

# Build
cmake --build build --config Release
```

### Windows PowerShell helper

```powershell
# From the repository root on Windows 11
.\scripts\Build-Windows.ps1 -ProjectDir ".\juce-template" `
    -BuildDir "build" -Configuration Release
```

### CMake helper modules

```cmake
list(APPEND CMAKE_MODULE_PATH "/path/to/build-tools/cmake")
include(MonakaiBuildUtils)
monakai_set_cxx_standard(MyTarget)
monakai_enable_warnings(MyTarget)
```

## Repository structure

```
build-tools/
├── cmake/                  # Reusable CMake modules
├── configs/                # Platform-specific cache configs
├── juce-template/          # Minimal JUCE audio plug-in template
├── scripts/                # Build automation scripts
├── docs/                   # Build and troubleshooting guides
├── .github/workflows/      # CI verification
├── LICENSE
├── README.md
├── CODE_OF_CONDUCT.md
└── SECURITY.md
```

## Contributing

Contributions focused on build-system improvements, new platform support, and
documentation are welcome. Please see the [Contributing Guide](docs/contributing.md)
and our [Code of Conduct](./CODE_OF_CONDUCT.md).

## Security

See [SECURITY.md](./SECURITY.md).

## License

This repository is licensed under the [MIT License](./LICENSE).
