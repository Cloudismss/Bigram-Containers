#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>

#include "Deque.h"

int isAlphabetic(const std::string &input);
int toLower(std::string &input);
int activity(Deque &deque);
int collectActivity(std::string &activity);
int collectBigram(std::string &input);

#endif // ACTIVITY_H
