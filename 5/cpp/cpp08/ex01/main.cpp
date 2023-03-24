#include "Span.hpp"

int main()
{
    Span sp = Span(12290);

    sp.addNumber(6);
    sp.addNumber(8);
    sp.addNumber(20);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    try
    {
        sp.addNumber(235);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    sp.print();
    try
    {
        for (int i = 0; i<11; i++) {
            sp.expandInSize();
            std::cout << "size = " << sp.getCurrentSize() << std::endl;
        }
        sp.addNumber(10000);
        sp.addNumber(0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    return 0;
}
