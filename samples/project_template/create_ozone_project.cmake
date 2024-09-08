# File: create_ozone_project.cmake

# Function to create the .jdebug file in the Ozone folder
function(create_jdebug_file)
    set(OZONE_DIR "${CMAKE_BINARY_DIR}/../Ozone")
    set(JDEBUG_FILE "${OZONE_DIR}/project_ozone.jdebug")

    file(MAKE_DIRECTORY ${OZONE_DIR})

    set(JDEBUG_CONTENT "
        void OnProjectLoad (void) {
          Project.SetDevice (\"LM3S1165\")\;
          Project.SetHostIF (\"USB\", \"\")\;
          Project.SetTargetIF (\"JTAG\")\;
          Project.SetTIFSpeed (\"4 MHz\")\;
          Project.AddPathSubstitute (\"${OZONE_DIR}\", \"$(ProjectDir)\")\;
          Project.AddPathSubstitute (\"${OZONE_DIR}\", \"$(ProjectDir)\")\;
          Project.AddSvdFile (\"$(InstallDir)/Config/CPU/Cortex-M3.svd\")\;
          File.Open (\"${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}.elf\")\;
        }

        void AfterTargetReset (void) {
          _SetupTarget()\;
        }

        void AfterTargetDownload (void) {
          _SetupTarget()\;
        }

        void _SetupTarget(void) {
          unsigned int SP\;
          unsigned int PC\;
          unsigned int VectorTableAddr\;

          VectorTableAddr = Elf.GetBaseAddr()\;
          SP = Target.ReadU32(VectorTableAddr)\;
          if (SP != 0xFFFFFFFF) {
            Target.SetReg(\"SP\", SP)\;
          }
          PC = Elf.GetEntryPointPC()\;
          if (PC != 0xFFFFFFFF) {
            Target.SetReg(\"PC\", PC)\;
          } else {
            Util.Error(\"Project script error: failed to set up entry point PC\", 1)\;
          }
        }
    ")

    file(WRITE ${JDEBUG_FILE} ${JDEBUG_CONTENT})
endfunction()