#ifndef RINGBUFFERQUEUE_H
#define RINGBUFFERQUEUE_H

#include <vector>

#include "Bigram.h"
#include "Deque.h"

class RingBufferQueue : public Deque
{
public:
  int push(const Bigram& bigram) override;
  int pop() override;
  void view() override;

private:
  std::vector<Bigram> queue;
  Bigram* front = nullptr;
  Bigram* back = nullptr;
};

#endif // RINGBUFFERQUEUE_H
