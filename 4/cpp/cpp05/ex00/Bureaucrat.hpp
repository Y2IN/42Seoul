/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:40:30 by yje               #+#    #+#             */
/*   Updated: 2023/03/17 14:19:15 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H_
#define BUREAUCRAT_H_

#include<iostream>
#include <string>

class Bureaucrat {
	private:
		const std::string _name;
		// And a grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade).
		int _grade;
	public:
		Bureaucrat(); //A default constructor
		Bureaucrat(std::string name, int grade); //A copy constructor
		Bureaucrat& operator=(const Bureaucrat&); //A assignment operator overload
		~Bureaucrat(); //A destructor
		const std::string& getName();
		const int& getGrade() const;
};
	class GradeTooHighException : public std::exception{
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception{
		public:
			const char* what() const throw();
	};
#endif
