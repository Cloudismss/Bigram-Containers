#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "Bigram.h"
#include "Deque.h"

class ArrayStack : public Deque
{
public:
  int push(const Bigram& bigram) override;
  int pop() override;
  void view() override;

private:
  int size = 0;
  Bigram stack[MAX];
  Bigram* top = nullptr;
};

#endif // ARRAYSTACK_H
