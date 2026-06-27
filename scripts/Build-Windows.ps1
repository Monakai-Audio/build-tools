<#
.SYNOPSIS
    Configure and build a CMake project on Windows 11 using Visual Studio 2022.

.PARAMETER ProjectDir
    Path to the CMake project source directory.

.PARAMETER BuildDir
    Name of the build directory (created inside ProjectDir).

.PARAMETER Configuration
    Build configuration: Debug or Release.

.PARAMETER Generator
    CMake generator to use.
#>
[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)]
    [string]$ProjectDir,

    [string]$BuildDir = "build",

    [ValidateSet("Debug", "Release")]
    [string]$Configuration = "Release",

    [string]$Generator = "Visual Studio 17 2022"
)

$ErrorActionPreference = "Stop"

$ProjectDir = Resolve-Path $ProjectDir
$BuildPath = Join-Path $ProjectDir $BuildDir

Write-Host "Configuring project at $ProjectDir ..."
cmake -S $ProjectDir -B $BuildPath -G "$Generator" -A x64

Write-Host "Building $Configuration ..."
cmake --build $BuildPath --config $Configuration --parallel 4

Write-Host "Build complete. Outputs are in $BuildPath."
