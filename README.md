# Cub3D

## Overview
Cub3D is a 3D rendering engine built using the Raycasting technique. It is inspired by Wolfenstein 3D and serves as an introduction to graphics programming in the 42 curriculum.

- **Objective:** Implement a basic 3D game engine using a 2D map as input.
- **Key Features:**
  - Raycasting for 3D rendering.
  - Movement mechanics (player movement and rotation).
  - Interaction with a basic map format.

## Features
- **3D Rendering:**
  - Raycasting-based visuals for walls and textures.
- **Player Controls:**
  - Movement: Forward, backward, left, and right.
  - Rotation: Look around the map using arrow keys.
- **Map Handling:**
  - Custom map parser.
  - Map validation for proper gameplay.

## Requirements
- **Operating System:** Linux or macOS (may work on Windows with adjustments).
- **Dependencies:**
  - `MinilibX` for graphics rendering.
  - GCC or Clang for compilation.

## Installation and Execution
### Clone the Repository
```bash
git clone [repository URL]
cd cub3D

# Build
make

# Run
./cub3D map/test.cub or map/test1.cub or map/test2.cub