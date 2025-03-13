set(Sources
  # User interface
  Activity.cpp

  # Bigram class
  Bigram.cpp

  # Data structures
  ArrayStack.cpp
  VectorStack.cpp
  RingBufferQueue.cpp
)

set(Dirs
  "../include"
)

add_library(src ${Sources})
target_include_directories(src PUBLIC ${Dirs})
