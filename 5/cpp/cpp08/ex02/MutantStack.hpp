#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
  class MutantStack : public std::stack<T> {
    public:
      MutantStack() {};
      MutantStack(const MutantStack& origin) {
        *this = origin;
      };
      MutantStack& operator=(const MutantStack& origin) {
        *this = origin;
        return *this;
      }
      ~MutantStack() {};

      typedef typename MutantStack<T>::stack::container_type::iterator iterator;
      iterator begin()
        {return this->c.begin();}
      iterator end()
        {return this->c.end();}

      typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
      reverse_iterator rbegin() {return this->c.rbegin();}
      reverse_iterator rend() {return this->c.rend();}
  };

#endif
