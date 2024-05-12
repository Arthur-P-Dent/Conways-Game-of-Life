# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/ConwaysGOL_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ConwaysGOL_autogen.dir/ParseCache.txt"
  "ConwaysGOL_autogen"
  )
endif()
