# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Tree-Visualizer_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Tree-Visualizer_autogen.dir/ParseCache.txt"
  "Tree-Visualizer_autogen"
  )
endif()
