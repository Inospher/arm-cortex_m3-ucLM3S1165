# Include the CMake file containing the function
include(${CMAKE_SOURCE_DIR}/create_ozone_project.cmake)

cmake_minimum_required(VERSION 3.6)

# Define the build system
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Define the C standard version
set(CMAKE_C_STANDARD 99)

# Path to the installation of the GNU Arm Embedded Toolchain
# For downloads, visit: https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads
set(ARM_TOOLCHAIN_PATH "B:/Program Files (x86)/GNU Arm Embedded Toolchain/10 2021.10/bin")

# Check if the specified toolchain path exists
if(NOT EXISTS "${ARM_TOOLCHAIN_PATH}")
    message(STATUS "--------------------------------------------------------------------------------")
    message(STATUS "The specified toolchain path does not exist.")
    message(STATUS "Please update the path in the CMakeLists.txt file according to your environment.")
    message(STATUS "Not found at: ${ARM_TOOLCHAIN_PATH}")
    message(STATUS "--------------------------------------------------------------------------------")
    message(FATAL_ERROR "ARM GNU Toolchain not found at: ${ARM_TOOLCHAIN_PATH}")
endif()

# Path to the project SDK (StellarisWare)
set(STELLARISWARE_SDK_PATH "${CMAKE_SOURCE_DIR}/../../sdk")

# Check if the specified StellarisWare SDK path exists
if(NOT EXISTS "${STELLARISWARE_SDK_PATH}")
    message(STATUS "--------------------------------------------------------------------------------")
    message(STATUS "The specified StellarisWare SDK path does not exist.")
    message(STATUS "Please update the path in the CMakeLists.txt file according to your environment.")
    message(STATUS "Not found at: ${STELLARISWARE_SDK_PATH}")
    message(STATUS "--------------------------------------------------------------------------------")
    message(FATAL_ERROR "Stellaris SDK not found at: ${STELLARISWARE_SDK_PATH}")
endif()

set(DRIVER_LIB_PATH "${STELLARISWARE_SDK_PATH}/driverlib/gcc")
set(GRAPHICS_LIB_PATH "${STELLARISWARE_SDK_PATH}/grlib/gcc")

# Configure the C compiler
set(CMAKE_C_COMPILER "${ARM_TOOLCHAIN_PATH}/arm-none-eabi-gcc.exe")

# C and ASM compilation flags
set(CMAKE_C_FLAGS "-mcpu=cortex-m3 -mthumb -march=armv7-m -mfloat-abi=soft -ffunction-sections -fdata-sections -g -O0 -std=c99")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -g -O0 -fverbose-asm -v")

set(CMAKE_ASM_FLAGS "-mcpu=cortex-m3 -mthumb -march=armv7-m -mfloat-abi=soft -ffunction-sections -fdata-sections -g -O0")
#set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -Wa,-adhln")

# Linker flags
set(CMAKE_EXE_LINKER_FLAGS "-Wl,-Map=output.map -nostartfiles -nodefaultlibs -nostdlib -lgcc -T${CMAKE_SOURCE_DIR}/linker_script.ld")

# Call the function to create the .jdebug file
create_jdebug_file()

# Project name
project(project_ucLM3S1165 C)

# Include header directories
include_directories(
        "${STELLARISWARE_SDK_PATH}/boot_loader"
        "${STELLARISWARE_SDK_PATH}"
)

# Add the executable
add_executable(
        project_ucLM3S1165
        main.c
        startup_gcc.c
)

# Set target properties
set_target_properties(
        project_ucLM3S1165
        PROPERTIES SUFFIX ".elf"
)

# Link the required libraries
target_link_libraries(project_ucLM3S1165
        "${DRIVER_LIB_PATH}/libdriver.a"
)

