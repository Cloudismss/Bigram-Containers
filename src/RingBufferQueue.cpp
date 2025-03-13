#include "RingBufferQueue.h"

#include <iostream>

#include "Globals.h"

#include "Bigram.h"

RingBufferQueue::RingBufferQueue()
{
  // Preallocate underlying array
  queue.reserve(MAX);
  begin = &queue[0];
  end = begin + queue.capacity() - 1;
  front = begin;
  back = begin;
}

int RingBufferQueue::push(const Bigram& bigram)
{
  // Reallocate underlying array if necessary - add 1 to size for empty pop slot
  if ((queue.size() + 1) % MAX == 0)
    expand();

  // Add 1 to back to skip empty pop slot
  if (queue.size() == 0 || back + 1 == end)
    back = begin;
  else
    ++back;

  const int position = back - begin;
  queue.emplace(queue.begin() + position, bigram);

  std::cout << "bigram \"" << *back << "\" successfully pushed to back\n\n";

  return SUCCESS;
}

int RingBufferQueue::pop()
{
  // TODO! Push after pop on a non-empty vector is inserting in the wrong location

  // Underflow handling
  if (queue.size() < 1)
  {
    std::cerr << "Popping would cause underflow\n\n";
    return FAIL;
  }

  // Copy front for display purposes
  const auto copy = *front;
  
  // Move front value to back and pop it
  const int frontPosition = front - begin;
  const int backPosition = back - begin;
  queue[frontPosition] = std::move(backPosition);
  queue.pop_back();

  // Move front
  if (queue.size() == 0 || front + 1 == end)
    front = begin;
  else
    ++front;

  std::cout << "bigram \"" << copy << "\" popped from the front\n\n";

  return SUCCESS;
}

void RingBufferQueue::view()
{
  std::cout << "\n";

  if (queue.size() < 1)
    std::cerr << "Queue is empty\n";

  // Print the queue
  const int position = front - begin;
  auto current = front;
  for (int i = 0; i != queue.size(); ++i)
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
  // Copy queue vector to move values to beginning
  const auto copy = queue;
  queue.clear();

  // Copy values from copy to queue starting at index 0
  const int position = front - begin;
  auto current = front;
  for (int i = 0; i != copy.size(); ++i)
  {
    queue.push_back(*current);
    if (current + 1 == end)
      current = begin;
    else
      ++current;
  }

  // Increase capacity
  queue.reserve(queue.capacity() + MAX);

  // Reassign pointers to newly allocated array
  begin = &queue[0];
  end = begin + queue.capacity() - 1;
  front = begin;
  back = begin + queue.size() - 1;

  return SUCCESS;
}
