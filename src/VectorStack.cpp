#include "VectorStack.h"

#include <iostream>

#include "Globals.h"

#include "Bigram.h"

VectorStack::VectorStack()
{
  // Preallocate underlying array
  stack.reserve(MAX);
}

int VectorStack::push(const Bigram& bigram)
{
  // Reallocate underlying array if necessary
  if (stack.size() % MAX == 0)
    stack.reserve(stack.capacity() + MAX);

  stack.push_back(bigram);

  // Assign top based on whether or not a reallocation occurred
  if (stack.size() % MAX == 1)
    top = &stack[0] + stack.size() - 1;
  else
    ++top;

  std::cout << "bigram \"" << *top << "\" successfully pushed in index " << stack.size() - 1 << "\n\n";

  return SUCCESS;
}

int VectorStack::pop()
{
  // Underflow handling
  if (stack.size() < 1)
  {
    std::cerr << "Popping would cause underflow\n\n";
    return FAIL;
  }

  // Copy top for display purposes
  const Bigram copy = *top;

  --top;
  stack.pop_back();

  if (stack.size() == 0)
    top = nullptr;

  std::cout << "bigram \"" << copy << "\" in index " << stack.size() << " successfully popped\n\n";

  return SUCCESS;
}

void VectorStack::view()
{
  std::cout << "\n";

  if (stack.size() < 1)
    std::cerr << "Stack is empty\n";

  // Print stack in reverse for visual effect
  int i = stack.size() - 1;
  for (auto it = stack.rbegin(); it != stack.rend(); ++it)
    std::cout << i-- << ": " << *it << "\n";

  std::cout << "\n";
}
