#ifndef BIGRAM_H
#define BIGRAM_H

#include <iostream>
#include <string>

class Bigram
{
public:
  Bigram() { }
  ~Bigram() { }

public:
  Bigram(const std::string& bigram);
  Bigram(const Bigram& source);

public:
  Bigram& operator=(const Bigram& source);
  Bigram& operator=(const char character);
  friend std::ostream& operator<<(std::ostream& out, const Bigram& bigram);

private:
  char first;
  char last;
};

#endif // BIGRAM_H
