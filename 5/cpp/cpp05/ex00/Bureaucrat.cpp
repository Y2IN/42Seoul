/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:57:50 by yje               #+#    #+#             */
/*   Updated: 2023/03/19 00:43:24 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(1) {
}

Bureaucrat::Bureaucrat(std::string name, int grade)
    : _name(name), _grade(grade) {
    if (grade <= 0)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat& origin) {
	this->_grade = origin._grade;
	return *this;
}

Bureaucrat::~Bureaucrat(){    
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void	Bureaucrat::incrementGrade(){
    if(this->_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void	Bureaucrat::decrementGrade(){
    if(this->_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade High";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade Low";
}

std::ostream& operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
	std::cout << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}