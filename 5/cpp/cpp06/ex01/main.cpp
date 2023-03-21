#include "Serializer.hpp"

int main(){
  
    Data d;
    d.a = 10;
	uintptr_t p1 = Serializer::serialize(&d);
	Data*	ptr = Serializer::deserialize(p1);

	std::cout << &d << std::endl;
	std::cout << p1 << std::endl;
	std::cout << ptr << std::endl;
  std::cout << ptr->a << std::endl;


    return 0;
}