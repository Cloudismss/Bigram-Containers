#ifndef DEQUE_H
#define DEQUE_H

#include "Bigram.h"

class Deque
{
public:
  virtual ~Deque() { }

public:
  virtual int push(const Bigram& bigram) = 0;
  virtual int pop() = 0;
  virtual void view() = 0;

protected:
  const static int MAX = 6;
};

#endif // DEQUE_H
