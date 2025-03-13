#ifndef RINGBUFFERQUEUE_H
#define RINGBUFFERQUEUE_H

#include <vector>

#include "Bigram.h"
#include "Deque.h"

class RingBufferQueue : public Deque
{
public:
  RingBufferQueue();

public:
  int push(const Bigram& bigram) override;
  int pop() override;
  void view() override;

private:
  int expand();

private:
  std::vector<Bigram> queue;
  Bigram* begin;
  Bigram* end;
  Bigram* front;
  Bigram* back;
  int size = 0;
};

#endif // RINGBUFFERQUEUE_H
