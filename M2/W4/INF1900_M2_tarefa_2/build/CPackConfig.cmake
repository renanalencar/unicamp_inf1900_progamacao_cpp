# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BINARY_7Z "OFF")
set(CPACK_BINARY_IFW "OFF")
set(CPACK_BINARY_INNOSETUP "OFF")
set(CPACK_BINARY_NSIS "ON")
set(CPACK_BINARY_NUGET "OFF")
set(CPACK_BINARY_WIX "OFF")
set(CPACK_BINARY_ZIP "OFF")
set(CPACK_BUILD_SOURCE_DIRS "C:/Users/renan/source/repos/unicamp_inf1900_progamacao_cpp/M2/W4/INF1900_M2_tarefa_2;C:/Users/renan/source/repos/unicamp_inf1900_progamacao_cpp/M2/W4/INF1900_M2_tarefa_2/build")
set(CPACK_CMAKE_GENERATOR "MinGW Makefiles")
set(CPACK_COMPONENTS_ALL "")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "C:/Program Files/CMake/share/cmake-3.27/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "jewel_collector built using CMake")
set(CPACK_GENERATOR "NSIS")
set(CPACK_INNOSETUP_ARCHITECTURE "x64")
set(CPACK_INSTALL_CMAKE_PROJECTS "C:/Users/renan/source/repos/unicamp_inf1900_progamacao_cpp/M2/W4/INF1900_M2_tarefa_2/build;jewel_collector;ALL;/")
set(CPACK_INSTALL_PREFIX "C:/Program Files (x86)/jewel_collector")
set(CPACK_MODULE_PATH "")
set(CPACK_NSIS_DISPLAY_NAME "jewel_collector 1.0.0")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES64")
set(CPACK_NSIS_PACKAGE_NAME "jewel_collector 1.0.0")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OBJCOPY_EXECUTABLE "C:/ProgramData/chocolatey/bin/objcopy.exe")
set(CPACK_OBJDUMP_EXECUTABLE "C:/ProgramData/chocolatey/bin/objdump.exe")
set(CPACK_OUTPUT_CONFIG_FILE "C:/Users/renan/source/repos/unicamp_inf1900_progamacao_cpp/M2/W4/INF1900_M2_tarefa_2/build/CPackConfig.cmake")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "C:/Program Files/CMake/share/cmake-3.27/Templates/CPack.GenericDescription.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "jewel_collector built using CMake")
set(CPACK_PACKAGE_FILE_NAME "jewel_collector-1.0.0-win64")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "jewel_collector 1.0.0")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "jewel_collector 1.0.0")
set(CPACK_PACKAGE_NAME "jewel_collector")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "Humanity")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PROJECT_NAME "jewel_collector")
set(CPACK_PROJECT_VERSION "1.0.0")
set(CPACK_READELF_EXECUTABLE "C:/ProgramData/chocolatey/bin/readelf.exe")
set(CPACK_RESOURCE_FILE_LICENSE "C:/Program Files/CMake/share/cmake-3.27/Templates/CPack.GenericLicense.txt")
set(CPACK_RESOURCE_FILE_README "C:/Program Files/CMake/share/cmake-3.27/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "C:/Program Files/CMake/share/cmake-3.27/Templates/CPack.GenericWelcome.txt")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_7Z "ON")
set(CPACK_SOURCE_GENERATOR "7Z;ZIP")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "C:/Users/renan/source/repos/unicamp_inf1900_progamacao_cpp/M2/W4/INF1900_M2_tarefa_2/build/CPackSourceConfig.cmake")
set(CPACK_SOURCE_ZIP "ON")
set(CPACK_SYSTEM_NAME "win64")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "win64")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "C:/Users/renan/source/repos/unicamp_inf1900_progamacao_cpp/M2/W4/INF1900_M2_tarefa_2/build/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
