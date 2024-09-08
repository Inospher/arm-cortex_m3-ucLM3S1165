# Projeto ucLM3S1165

[Versão em Português](README-ptBR.md)

**Description:**
Template project for CLion, focused on firmware development for the LM3S1165 microcontroller, without using Texas Instruments development boards.

**Repository:**
[https://github.com/Inospher/ucLM3S1165.git](https://github.com/Inospher/ucLM3S1165.git)

**Project Purpose:**

This repository provides a project template and examples based on this template, aimed at developing firmware for applications using the LM3S1165 microcontroller. This project does not use the Texas Instruments development board (formerly Stellaris); instead, it focuses on using the microcontroller on breadboards, specifically developed PCBs, or recycled boards that use the LM3S1165.

**Project Structure:**

The project is organized simply to facilitate development:

- **'samples' folder**: Contains example projects, including a base template that can be used as a starting point for new developments.
- **'SDK' folder**: Includes a reduced version of the StellarisWare SDK, focusing exclusively on the libraries and resources needed for the LM3S1165 microcontroller. Parts of the SDK related to development boards and graphic libraries were removed to keep the project lean and targeted.

**Development Environment Setup:**

**Required Tools:**
1. CLion 2024.2.1.
2. GNU Arm Embedded Toolchain: Available at [Arm GNU Toolchain Downloads](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads).
3. Ozone (SEGGER J-Link Debugger): Required for debugging and firmware programming on the microcontroller via the J-TAG interface. Download at [Ozone Downloads](https://www.segger.com/downloads/jlink/#Ozone).
4. J-Link Interface: A J-Link interface is mandatory for communication between Ozone and the microcontroller. More information about available models can be found at [J-Link Models](https://www.segger.com/products/debug-probes/j-link/models/j-link-base/).

**Setup Steps:**
1. **Clone the Repository:**
   - `git clone https://github.com/Inospher/ucLM3S1165.git`
2. **Open the Project in CLion:**
   - Open CLion and select the project directory.
3. **Build the Project:**
   - Build the project in CLion. This will compile the code and generate the `.elf` file in the `cmake-build-debug` directory.
4. **Generate Ozone Project:**
   - Upon compiling the project in CLion for the first time, the `CMakeLists.txt` script will automatically generate an Ozone project in the `Ozone` directory.
5. **Debugging and Programming the Microcontroller:**
   - Open the generated Ozone project.
   - Connect the J-Link interface to the LM3S1165 microcontroller.
   - Use Ozone to program the `.elf` file onto the microcontroller and start debugging.

**Directory Structure after Opening in CLion and First Build:**
- **ucLM3S1165/**
  - **samples**: Example projects and base template.
  - **SDK**: Reduced content of the StellarisWare SDK.
  - **cmake-build-debug**: Build output directory.
  - **Ozone**: Project generated for Ozone.