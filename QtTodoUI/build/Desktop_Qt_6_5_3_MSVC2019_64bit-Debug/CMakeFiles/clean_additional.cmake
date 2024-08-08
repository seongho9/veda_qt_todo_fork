# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QtTodoUI_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QtTodoUI_autogen.dir\\ParseCache.txt"
  "QtTodoUI_autogen"
  )
endif()
