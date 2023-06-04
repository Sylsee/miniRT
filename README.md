# MiniRT

## Introduction

MiniRT is a ray tracer coded in C, normed and humble but functional. Ray tracing is a method for rendering 3-dimensional computer-generated images, developed for the first time in 1968. It is more computationally expensive than the commonly used "Rasterization" method, but it produces a much higher degree of visual realism. The main goal of miniRT is to prove that you can implement any mathematics or physics formulas without being a mathematician. We will only implement the most basic ray tracing features here.

![Ray Tracing Example](saves/bonus/2_lights.bmp)

## Installation

To install MiniRT, follow these steps:

1. Clone the repository:

   ```
   git clone --recursive https://github.com/Sylsee/miniRT.git
   ```

   If you've already cloned the repository without the `--recursive` flag, you can initialize and update the submodules with:

   ```
   git submodule update --init --recursive
   ```

2. Compile the project using the Makefile:

   ```
   make
   ```

## Usage

To use MiniRT, you have several options:

1. To generate an image:

   ```
   ./miniRT [file].rt
   ```

2. To save the generated image:

   ```
   ./miniRT [file].rt --save
   ```

3. To generate a video:

   ```
   ./miniRT [file].rt --video [directory]
   ```

## Capabilities

MiniRT comes with a wide range of features that allow for complex scene rendering:

- **Object Selection**: Select objects and apply desired changes.

- **Light Management**: Handle ambient light, spotlights, and shadows.

- **Object**: Handle spheres, planes, and cylinders.

- **Status and Progress Bar**: Monitor the rendering process with a progress bar.

- **Scene Interactions**: Interact with the scene in real-time.

- **Multicam**: Switch between multiple camera views.

- **Screen Capture**: Capture the current view as an image.

- **Video Generation**: Generate a video by rendering a sequence of images.

- **Multithreading**: Speed up rendering by using multiple threads.

- **Reflection and Refraction**: Simulate realistic light reflection and refraction.

- **Fresnel Effect**: Simulate the Fresnel effect, which changes the amount of reflection based on the viewing angle.

- **Antialiasing**: Smooth out jagged edges with antialiasing.

- **Specular Light**: Simulate the bright spot of light that appears on shiny objects.

- **Reflection on Objects**: Reflect other objects in shiny surfaces.

- **Multi Spots and Colored Light**: Use multiple spotlights and colored lights.

## Controls

- **Escape** and red cross to quit
- **WASD** to move camera or light
- **Caps** to change camera mode (translate or rotate)
- **Tab** to change camera or light selection
- **Space** and **Shift** to go up and down
- **EQ** to switch camera and light
- **V** to start/stop video mode
- **Arrow key**, **O** and **P** to move selected object
- **Ctrl** to change object mode
- **HJKL** to change object properties

## License

MiniRT is licensed under the [LICENSE](LICENSE).

## Contact

If you want to contact me you can reach me at spoliart@student.42.fr.
