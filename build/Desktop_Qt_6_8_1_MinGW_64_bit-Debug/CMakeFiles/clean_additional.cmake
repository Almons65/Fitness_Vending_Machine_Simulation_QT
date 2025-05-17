# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\FitnessVen_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\FitnessVen_autogen.dir\\ParseCache.txt"
  "FitnessVen_autogen"
  )
endif()
