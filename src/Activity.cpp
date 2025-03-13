#include "Activity.h"

#include <iostream>
#include <string>

#include "Globals.h"

#include "Bigram.h"
#include "Deque.h"

enum userSelection
{
  PUSH,
  POP,
  VIEW,
};

int isAlphabetic(const std::string &input)
{
  // Check for non-alphabet characters
  for (auto character : input)
  {
    if (!((character > 64 && character < 91) || (character > 96 && character < 123)))
    {
      std::cerr << "Invalid character(s) entered\n\n";
      return FAIL;
    }
  }

  return SUCCESS;
}

int toLower(std::string &input)
{
  // Convert to lowercase
  for (int i = 0; i < input.size(); ++i)
    if (input[i] < 97)
      input[i] += 32;

  return SUCCESS;
}

int activity(Deque &deque)
{
  bool loop = true;
  do
  {  
    std::string activity;
    int activitySelection = collectActivity(activity);

    if (activitySelection == QUIT)
      return QUIT;
    
    if (activitySelection == FAIL)
      continue;

    switch (activitySelection)
    {
      case PUSH:
      {
        std::string bigramSelection;
        if (collectBigram(bigramSelection) == SUCCESS)
        {
          Bigram bigram(bigramSelection);
          deque.push(bigram);
        }
        break;
      }
      case POP:
      {
        deque.pop();
        break;
      }
      case VIEW:
      {
        deque.view();
        break;
      }
    }
  } while (loop);

  return FAIL;
}

int collectActivity(std::string &activity)
{
  std::cout << "Please enter a selection\n"
            << "Available options: 'push', 'pop', 'view', or 'quit': ";
  std::getline(std::cin, activity);

  if (isAlphabetic(activity) == FAIL)
    return FAIL;

  if (toLower(activity) == FAIL)
    return FAIL;

  if (activity == "push")
    return PUSH;
  else if (activity == "pop")
    return POP;
  else if (activity == "view")
    return VIEW;
  else if (activity == "quit")
    return QUIT;
  else
  {
    std::cerr << "That was not a valid selection!\n\n";
    return FAIL;
  }
}

int collectBigram(std::string &bigramSelection)
{
  std::cout << "Please enter a bigram to push onto the stack, or enter 'quit': ";
  std::getline(std::cin, bigramSelection);

  std::string copy = bigramSelection;

  if (isAlphabetic(copy) == FAIL)
    return FAIL;

  if (toLower(copy) == FAIL)
    return FAIL;
    
  if (copy == "quit")
    return QUIT;

  if (bigramSelection.size() != 2)
  {
    std::cerr << "Incorrect amount of characters to be classified as a bigram\n\n";
    return FAIL;
  }

  return SUCCESS;
}
