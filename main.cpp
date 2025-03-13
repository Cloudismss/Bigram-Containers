#include <iostream>

#include "Globals.h"

#include "Activity.h"
#include "ArrayStack.h"
#include "RingBufferQueue.h"
#include "VectorStack.h"

int main()
{
  bool loop = true;
  do
  {  
    std::cout << "Which type of activity would you like to operate on?\n"
              << "1. Stack - Fixed Size Activity\n"
              << "2. Stack - Dynamic Size Activity\n"
              << "3. Queue Activity\n"
              << "4. Quit\n"
              << "\n";

    int selection = 0;
    std::cin >> selection;
    std::cin.ignore();
    std::cout << "\n";

    switch (selection)
    {
      case 1:
      {
        std::cout << "Fixed Size Stack Activity\n\n";
        ArrayStack stack;
        if (activity(stack) == FAIL)
          std::cerr << "Fixed size stack activity failed\n\n";
        std::cout << "\n";
        break;
      }
      case 2:
      {
        std::cout << "Dynamic Size Stack Activity\n\n";
        VectorStack stack;
        if (activity(stack) == FAIL)
          std::cerr << "Dynamic size stack activity failed\n\n";
        std::cout << "\n";
        break;
      }
      case 3:
      {
        std::cout << "Queue Activity\n\n";
        RingBufferQueue queue;
        if (activity(queue) == FAIL)
          std::cerr << "Queue activity failed\n\n";
        std::cout << "\n";
        break;
      }
      case 4:
      {
        return SUCCESS;
        break;
      }
      default:
      {
        std::cerr << "Invalid selection\n\n";
      }
    }
  } while (loop);
}
