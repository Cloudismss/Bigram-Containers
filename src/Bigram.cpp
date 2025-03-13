#include "Bigram.h"

Bigram::Bigram(const std::string& bigram)
{
  this->first = bigram[0];
  this->last = bigram[1];
}

Bigram::Bigram(const Bigram& source)
{
  this->first = source.first;
  this->last = source.last;
}

Bigram& Bigram::operator=(const Bigram& source)
{
  this->first = source.first;
  this->last = source.last;
  return *this;
}

Bigram& Bigram::operator=(const char character)
{
  this->first = character;
  this->last = character;
  return *this;
}

std::ostream& operator<<(std::ostream& out, const Bigram& bigram)
{
  out << bigram.first << bigram.last;
  return out;
}
