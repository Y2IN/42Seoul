#include "Base.hpp"
// void leaks() { system("leaks Base"); }
int main() {
    // atexit(leaks);
    Base* b_ptr = generate();

    identify(b_ptr);
    identify(*b_ptr);

    delete b_ptr;

    return 0;
}