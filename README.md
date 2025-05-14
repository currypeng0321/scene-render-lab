# Dynamic 3D Environment Simulation

## Table of Contents
- [Project Overview](#project-overview)
- [Technologies Used](#technologies-used)
- [Project Structure](#project-structure)
- [Installation and Setup](#installation-and-setup)
- [Features](#features)
  - [Lighting and Material Modeling](#lighting-and-material-modeling)
  - [Real-Time Weather System](#real-time-weather-system)
  - [Real-Time Water and Seabed Simulation](#real-time-water-and-seabed-simulation)
- [Demo Scenario](#demo-scenario)

## Project Overview
This project aims to create a dynamic 3D environment with realistic lighting, weather effects, and water simulation. The key tasks are divided into three main sections:
1. **Lighting and material modeling** for environmental objects
2. **Real-time weather system** implementation
3. **Real-time water surface and seabed simulation**

## Technologies Used
- **C++**: Core programming language.
- **OpenGL**: Used for real-time rendering.
- **GLFW**: Window management.
- **GLM**: Mathematical operations (vector/matrix).
- **GLAD**: OpenGL function loading.
- **ImGui**: User interface.
- **CUDA**: GPU-based computation for volumetric rendering.
- **stb**: Image loading.

## Project Structure
- `src/`: Source code files for the 3D environment, weather system, water simulation, and more.
- `include/`: Header files for reusable components like lighting, materials, and rendering techniques.
- `shaders/`: GLSL shader files for lighting, water effects, and weather system rendering.
- `assets/`: Textures, models (lighthouse, rocks, plants), and other resources used in the scene.

## Installation and Setup

### Prerequisites

To compile and run this project, ensure that the following tools and dependencies are installed on your system:

- **CUDA 11.8**: This project requires CUDA 11.8 for GPU-based volumetric rendering. We recommend using this specific version due to stability concerns with newer versions. You can download CUDA 11.8 from the official NVIDIA website: [CUDA 11.8 Download Archive](https://developer.nvidia.com/cuda-11-8-0-download-archive?target_os=Windows&target_arch=x86_64&target_version=11&target_type=exe_local).
- **Visual Studio**: This project is configured for Visual Studio 2019, but it can be adapted for Visual Studio 2022. Ensure that the appropriate C++ development tools and CUDA toolkit integrations are installed in Visual Studio.
- **CMake**: Ensure you have CMake installed to configure and generate the project build files.

### Setup Steps

#### 1. Download and Install CUDA 11.8

Follow the instructions on the [NVIDIA website](https://developer.nvidia.com/cuda-11-8-0-download-archive?target_os=Windows&target_arch=x86_64&target_version=11&target_type=exe_local) to install CUDA 11.8. Ensure that the installation path is correctly set up, typically:

```plaintext
C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.8
```

#### 2. Clone the Repository

Clone the project repository to your local machine:

```bash
git clone https://github.com/typicalspider98/CGRA350.git
cd CGRA350
```

#### 3. Create the Build Directory

In the root directory of the project, create a `build` folder:

```bash
mkdir build
cd build
```

#### 4. Run CMake

Use CMake to configure the project. The example below is for Visual Studio 2019 with CUDA 11.8. If you are using a different version of Visual Studio, modify the `-G` option accordingly:

```bash
cmake -G "Visual Studio 16 2019" -A x64 .. -T cuda="C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.8" -D RTX30XX=ON -D GUI=ON
```

- **Note**: The CUDA path is the default installation path. If you installed CUDA in a different location, update the path accordingly.
- **Visual Studio Version**: If you are using Visual Studio 2022, modify the command as follows:

```bash
cmake -G "Visual Studio 17 2022" -A x64 .. -T cuda="C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.8" -D RTX30XX=ON -D GUI=ON
```

### Build the Project

Once CMake finishes configuring the project, you will find several files in the `build` folder, such as:

```bash
ALL_BUILD.vcxproj          CGRA350.vcxproj.user     ZERO_CHECK.vcxproj.filters
ALL_BUILD.vcxproj.filters  CMakeCache.txt           cmake_install.cmake
CGRA350/                   CMakeFiles/              imgui.ini
CGRA350.dir/               Debug/                   libs/
CGRA350.sln                INSTALL.vcxproj          x64/
CGRA350.vcxproj            INSTALL.vcxproj.filters
CGRA350.vcxproj.filters    ZERO_CHECK.vcxproj
```

#### 5. Open the Solution

Navigate to the `build` directory and double-click on the `CGRA350.sln` file to open the project in Visual Studio.

#### 6. Select Build Configuration

In Visual Studio, choose the appropriate build configuration such as `Release` or `Debug` from the toolbar.

#### 7. Compile the Project

After selecting the configuration, proceed to build the project by clicking on the **Build** menu and selecting **Build Solution**. This will compile the project and generate the necessary executable files.

### Run the Project

Once the build is successful, you can run the executable directly from Visual Studio, or navigate to the `Debug` (or `Release`) folder inside the `build` directory to run the compiled program.


## Features

### Lighting and Material Modeling
This feature includes:
- Realistic lighting effects on both water surfaces and environmental objects.
- Dynamic lighting adjustments based on time of day.
- Material transitions that adapt lighting effects on objects like the lighthouse and rocks.

### Real-Time Weather System
Implemented features include:
- Volumetric rendering for cloud simulation.
- Particle system to simulate rain.
- Real-time dynamic shaders for wet ground after rain.
- Weather-based scene adjustments, including color grading and light scattering.

### Real-Time Water and Seabed Simulation
This system incorporates:
- **Gerstner Waves** for real-time water surface dynamics.
- **Perlin Noise** for random ripples and natural surface variations.
- **Normal Mapping** for enhancing water surface details.
- Procedural generation of the seabed with **Perlin Noise** for realistic sand textures and variations.

## Demo Scenario
In the final demo, we showcase:
- Real-time environmental interactions including lighting changes based on time of day.
- Dynamic weather effects such as rain, clouds, and ground wetness.
- Seamless transitions between beach and water environments with detailed water and seabed simulations.
- An interactive scene with user controls for toggling between weather effects, water simulations, and material adjustments.

