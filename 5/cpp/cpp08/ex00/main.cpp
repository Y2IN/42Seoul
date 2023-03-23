#include "easyfind.hpp"

int main(){
	try{
		std::vector<int> v;
        for (int i = 0; i < 10; ++i) 
            v.push_back(i);
		std::cout << *easyfind(v, 3) <<std::endl; //* 연산자를 오버로딩해서 마치 포인터 처럼 동작하게 만든 것입니다
        }   
	catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
	try{
        std::list<int> lst;
        for (int i = 0; i < 10; ++i) {
            lst.push_back(i);
		}
        std::cout << *easyfind(lst, 9) <<std::endl;
    }
		catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
    try{
        std::deque<int> dq;
        for (int i = 0; i < 10; ++i) {
        dq.push_back(i);
		}
        std::cout << *easyfind(dq, 5) <<std::endl;
    }
		catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
    try{
		std::list<int> lst;
        for (int i = 0; i < 10; ++i) {
            lst.push_back(i);
            std::cout << *easyfind(lst, -1) <<std::endl;
		    std::cout << *easyfind(lst, 7) <<std::endl;
		}
    }
		catch (std::exception &e){
			std::cout << e.what() << std::endl;
	}
}