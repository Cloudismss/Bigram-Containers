#include "RingBufferQueue.h"

#include <iostream>

#include "Globals.h"

#include "Bigram.h"

RingBufferQueue::RingBufferQueue()
{
  // Preallocate underlying array
  queue.reserve(MAX);

  // Fill elements
  for (int i = 0; i != queue.capacity(); ++i)
  {
    const Bigram fill;
    queue.push_back(fill);
  }

  // Initialize pointers
  begin = &queue[0];
  end = begin + queue.capacity() - 1;
  front = begin;
  back = begin;
}

int RingBufferQueue::push(const Bigram& bigram)
{
  // Reallocate underlying array if necessary
  if (size % MAX == 0 && size != 0)
    expand();

  if (size == 0 || back == end)
    back = begin;
  else
    ++back;

  *back = bigram;
  ++size;

  std::cout << "bigram \"" << *back << "\" successfully pushed to back\n\n";

  return SUCCESS;
}

int RingBufferQueue::pop()
{
  // Underflow handling
  if (size < 1)
  {
    std::cerr << "Popping would cause underflow\n\n";
    return FAIL;
  }

  // Copy front for display purposes
  const auto copy = *front;
  
  *front = '\0';
  --size;

  // Move front
  if (size == 0 || front == end)
    front = begin;
  else
    ++front;

  std::cout << "bigram \"" << copy << "\" popped from the front\n\n";

  return SUCCESS;
}

void RingBufferQueue::view()
{
  std::cout << "\n";

  if (size < 1)
    std::cerr << "Queue is empty\n";

  // Print the queue
  const int position = front - begin;
  auto current = front;
  for (int i = 0; i != size; ++i)
  {
    std::cout << i << ": " << *current << "\n";
    if (begin + position + 1 == end)
      current = begin;
    else
      ++current;
  }

  std::cout << "\n";
}

int RingBufferQueue::expand()
{
  if (queue.capacity() > size)
    return SUCCESS;

  // Copy queue vector to move values to beginning
  std::vector<Bigram> copy = queue;
  const int frontPosition = front - begin;
  const int endPosition = end - begin;
  
  // Increase capacity
  queue.clear();
  queue.reserve(queue.capacity() + MAX);

  // Reassign pointers to newly allocated array
  begin = &queue[0];
  end = begin + queue.capacity() - 1;
  front = begin;
  back = begin + size - 1;
  size = 0;

  // Fill elements
  for (auto it = queue.begin(); it != queue.end(); ++it)
  {
    const Bigram fill;
    queue.push_back(fill);
  }

  // Copy values from copy to queue starting at index 0
  auto current = &copy[0] + frontPosition;
  for (int i = 0; i != copy.size(); ++i)
  {
    queue[i] = *current;
    ++size;
    if (current == &copy[0] + endPosition)
      current = &copy[0];
    else
      ++current;
  }

  return SUCCESS;
}
