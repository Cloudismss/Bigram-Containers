#include "ArrayStack.h"

#include <iostream>

#include "Globals.h"

#include "Bigram.h"

int ArrayStack::push(const Bigram& bigram)
{
  // Overflow handling
  if (size > MAX - 1)
  {
    std::cerr << "\nPushing would cause overflow\n\n";
    return FAIL;
  }

  if (size == 0)
    top = &stack[0];
  else
    ++top;
  
  *top = bigram;
  ++size;
  
  std::cout << "bigram \"" << *top << "\" successfully pushed in index " << size - 1 << "\n\n"; 

  return SUCCESS;
}

int ArrayStack::pop()
{
  // Underflow handling
  if (size < 1)
  {
    std::cerr << "Popping would cause underflow\n\n";
    return FAIL;
  }

  // Copy Bigram in top for output statement
  const Bigram copy = *top;

  *top = '\0';
  --top;
  --size;

  std::cout << "bigram \"" << copy << "\" in index " << size << " successfully popped\n\n";

  return SUCCESS;
}

void ArrayStack::view()
{
  std::cout << "\n";

  if (size < 1)
    std::cerr << "Stack is empty\n";

  // Print stack in reverse for visual effect
  for (int i = size - 1; i > -1; --i)
    std::cout << i << ": " << stack[i] << "\n";

  std::cout << "\n";
}
