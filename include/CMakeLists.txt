set(Includes
  # Globals
  Globals.h

  # User interface
  Activity.h

  # Bigram class
  Bigram.h

  # Data structures
  Deque.h
  ArrayStack.h
  VectorStack.h
  RingBufferQueue.h
)

add_library(include INTERFACE ${Includes})
