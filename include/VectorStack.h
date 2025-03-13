#ifndef VECTORSTACK_H
#define VECTORSTACK_H

#include <vector>

#include "Bigram.h"
#include "Deque.h"

class VectorStack : public Deque
{
public:
  VectorStack();

public:
  int push(const Bigram& bigram) override;
  int pop() override;
  void view() override;

private:
  std::vector<Bigram> stack;
  Bigram* top;
};

#endif // VECTORSTACK_H
