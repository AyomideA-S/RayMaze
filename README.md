# RayMaze

RayMaze is a 3D maze game built from scratch in C using the SDL2 library. It utilizes raycasting to render a pseudo-3D environment from a 2D map, inspired by classic games like Wolfenstein 3D. Features include texture mapping, player movement, and collision detection.

## Windows Development Setup (C & SDL2)

This project uses a modern 64-bit Windows toolchain. To compile and run this project locally, we use **MSYS2** (specifically the UCRT64 environment) to manage our C compiler and SDL2 dependencies.

Follow these steps to set up your environment:

### Step 1: Install MSYS2

1. Download the MSYS2 installer from [msys2.org](https://www.msys2.org/).
2. Run the installer and keep the default installation directory (usually `C:\msys64`).
3. Once installed, open the **MSYS2 UCRT64** terminal from your Start menu. *(Note: It is crucial to use the UCRT64 terminal, not MinGW64 or MSYS, to ensure modern 64-bit compatibility).*

### Step 2: Install the Compiler and SDL2

MSYS2 includes a package manager called `pacman`. This makes installing dependencies incredibly simple and prevents 32-bit/64-bit architecture mismatches.

Run the following command in your MSYS2 UCRT64 terminal to install the GCC compiler and the SDL2 development libraries:

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-SDL2
```

Type `Y` when prompted to confirm the installation.

### Step 3: Add MSYS2 to your System PATH

To compile from standard Windows terminals (like PowerShell or VS Code), you need to add the UCRT64 binary folder to your System PATH.

1. Open the Windows Start Menu, type "Environment Variables", and click **Edit the system environment variables**.
2. Click the **Environment Variables** button.
3. Under "System variables", find **Path** and click **Edit**.
4. Click **New** and add: `C:\msys64\ucrt64\bin`
5. Click OK to save. **Restart any open terminal windows** for the changes to take effect.

### Step 4: Project Structure

This project is organized to keep source code separate from compiled binaries. Ensure your directory looks like this:

```text
RayMaze/
├── assets/         # Textures, audio, and level data
├── bin/            # The compiled executable and required .dll files go here
├── include/        # .h header files
├── src/            # .c / .cpp source files
├── Makefile        # Build instructions
└── README.md       
```

### Step 5: Compiling the Project

Navigate to the root directory of the project (`RayMaze/`) in your terminal. Because we use a Makefile, compiling is as simple as running:

```bash
make
```

This will automatically compile all `.c` files in the `src/` directory and output the final `RayMaze.exe` into the `bin/` folder. To clean up compiled files, you can run `make clean`.

### Step 6: Distributing the Game (SDL2.dll)

Because you added MSYS2 to your System PATH, the game will run perfectly on your machine. However, if you want to send your compiled game to someone else, they will need the `SDL2.dll` file.

1. Navigate to `C:\msys64\ucrt64\bin`.
2. Locate the `SDL2.dll` file.
3. Copy this file and paste it directly into your project's `bin/` folder, right next to your compiled `RayMaze.exe` before zipping it up.
