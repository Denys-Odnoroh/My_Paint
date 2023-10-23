# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\MyPaint_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MyPaint_autogen.dir\\ParseCache.txt"
  "MyPaint_autogen"
  )
endif()
