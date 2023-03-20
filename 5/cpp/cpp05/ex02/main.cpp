/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 01:28:33 by yje               #+#    #+#             */
/*   Updated: 2023/03/20 10:48:00 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// void leaks() { system("leaks a.out"); }

void shrubberyTest(Bureaucrat b1, Bureaucrat b4) {
  std::cout << "ShrubberyCreateForm test" << std::endl;
  AForm* f1 = new ShrubberyCreationForm("Christmas");
  AForm* f2 = new ShrubberyCreationForm("Tree");

  std::cout << std::endl;
  std::cout << *f1 << *f2 << std::endl;
  std::cout << std::endl;
  std::cout << "Grade 140, can sign Shrubbery?" << std::endl;
  b4.signForm(*f1);
  std::cout << std::endl;
  std::cout << "Grade 140, can execute Shrubbery?" << std::endl;
  b4.executeForm(*f1);
  std::cout << std::endl;
  std::cout << "Not signed, can execute Shrubbery?" << std::endl;
  b1.executeForm(*f2);
  std::cout << std::endl;
  std::cout << "Signed, can execute Shrubbery?" << std::endl;
  b1.signForm(*f2);
  b1.executeForm(*f2);

  delete f1;
  delete f2;
}

void robotomyTest(Bureaucrat b1, Bureaucrat b3) {
  std::cout << "RobotomyRequestForm test" << std::endl;
  AForm* f1 = new RobotomyRequestForm("f1");
  AForm* f2 = new RobotomyRequestForm("f2");

  std::cout << std::endl;
  std::cout << *f1 << *f2 << std::endl; 
  std::cout << std::endl;
  std::cout << "Grade 70, can sign Robotomy?" << std::endl;
  b3.signForm(*f1);
  std::cout << std::endl;
  std::cout << "Grade 70, can execute Robotomy?" << std::endl;
  b3.executeForm(*f1);
  std::cout << std::endl;
  std::cout << "Not signed, can execute Robotomy?" << std::endl;
  b1.executeForm(*f2);
  std::cout << std::endl;
  std::cout << "Signed, can execute Robotomy?" << std::endl;
  b1.signForm(*f2);
  b1.executeForm(*f2);

  delete f1;
  delete f2;
}

void presidentialTest(Bureaucrat b1, Bureaucrat b2) {
  std::cout << "PresidentialPardonForm test" << std::endl;
  AForm* f1 = new PresidentialPardonForm("f1");
  AForm* f2 = new PresidentialPardonForm("f2");

  std::cout << std::endl;
  std::cout << *f1 << *f2 << std::endl; 
  std::cout << std::endl;
  std::cout << "can sign Pardon Form?" << std::endl;
  b2.signForm(*f1);
  std::cout << std::endl;
  std::cout << "can execute Pardon Form?" << std::endl;
  b2.executeForm(*f1);
  std::cout << std::endl;
  std::cout << "Not signed, can execute Pardon?" << std::endl;
  b1.executeForm(*f2);
  std::cout << std::endl;
  std::cout << "Signed, can execute Pardon?" << std::endl;
  b1.signForm(*f2);
  b1.executeForm(*f2);

  delete f1;
  delete f2;
}

int main(void) {
  Bureaucrat b1("Admin", 1);
  Bureaucrat b2("yje", 15);
  Bureaucrat b3("yein", 70);
  Bureaucrat b4("111111", 140);

  std::cout << b1 << b2 << b3 << b4 << std::endl;
  shrubberyTest(b1, b4);
  std::cout << std::endl;
  robotomyTest(b1, b3);
  std::cout << std::endl;
  presidentialTest(b1, b2);
  // atexit(leaks);
  return 0;
}
