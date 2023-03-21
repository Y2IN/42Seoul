#include "Serializer.hpp"

/*
* A default constructor
*/
Serializer::Serializer() {
}

/*
* A copy constructor
*/
Serializer::Serializer(const Serializer& ref) {
  *this = ref;
}

/*
* A assignment operator overload
*/
Serializer&	Serializer::operator=(const Serializer& ref) {
  if (this != &ref) {
    /* insert */
    *this = ref;
  }
  return *this;
}

/*
* A destructor
*/
Serializer::~Serializer() {
}
// reinterpret_cast<new_type>(expression)
// 임의의 포인터 타입끼리 변환을 허용하는 캐스트 연산자
// 또한 정수형을 포인터로 바꾸기 가능
uintptr_t Serializer::serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

// uintptr_t : unsigned integer parameter
Data* Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data *>(raw);
}
