# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\NelderMeadGUI_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\NelderMeadGUI_autogen.dir\\ParseCache.txt"
  "NelderMeadGUI_autogen"
  )
endif()
