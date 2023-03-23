// #include <iostream>
// #include "Array.hpp"

// #define MAX_VAL 750

#include "Array.hpp"
#include <iostream>
#include <string>

void leaks()
{
    system("leaks Array");
}

int main() {
    atexit (leaks);
    

    std::cout << "------  test string  ------" << std::endl;
	Array<std::string> b(3);

	b[0] = "42seoul";
	b[1] = "cpp";
    b[2] = "hi";

	std::cout << "b[0] : " << b[0] << std::endl;
	std::cout << "b size : " << b.size() << std::endl;

    Array<std::string> arr(5);
    arr[0] = "42";
    arr[1] = "Seoul";
    arr[2] = "cpp";
    arr[3] = "module";
    arr[4] = "07";
    std::cout << "size : " << arr.size() << std::endl;
    std::cout << "stringArray : ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "------  test int  ------" << std::endl;

    Array<int> intArray(10);
    for (int i = 0; i < 10; ++i) {
        intArray[i] = i;
    }
    std::cout << "size : " << intArray.size() << std::endl;
    std::cout << "array : ";
    for (int i = 0; i < 10; ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "------  test char  ------" << std::endl;
    Array<char> charArray(10);
    for (int i = 0; i < 10; ++i) {
        charArray[i] = 'A' + i;
    }
    std::cout << "size : " << charArray.size() << std::endl;
    std::cout << "array : ";
    for (int i = 0; i < 10; ++i) {
        std::cout << charArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "----- exception test ------" << std::endl;
    try {
        std::cout << "intArray[10] = 10 -> ";
        intArray[10] = 10;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << "intArray[-1] = 10 -> ";
        intArray[-1] = 10;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

// int main(int, char**)
// {
//     atexit(leaks);
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }

//     //SCOPE -> 복사 확인
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }