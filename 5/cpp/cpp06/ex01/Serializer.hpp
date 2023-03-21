#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>

typedef struct s_data{
  unsigned int a;
} Data;

class Serializer
{
public:
  ~Serializer();
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
private:
  Serializer();
  Serializer(const Serializer &);
  Serializer& operator=(const Serializer &);

};

#endif