/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:40:30 by yje               #+#    #+#             */
/*   Updated: 2023/03/20 01:31:03 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H_
#define BUREAUCRAT_H_

#include<iostream>
#include <string>

class AForm;

class Bureaucrat {
	private:
		const std::string _name;
		// And a grade that ranges from 1 (highest possible grade) to 150 (lowest possible grade).
		int _grade;
	public:
		Bureaucrat& operator=(const Bureaucrat&); //A assignment operator overload
		Bureaucrat(); //A default constructor
		Bureaucrat(std::string name, int grade); //A copy constructor
		Bureaucrat(const Bureaucrat&);
		~Bureaucrat(); //A destructor
		std::string getName() const;
		int getGrade() const;
		void	incrementGrade();
		void	decrementGrade();
		void	signForm(AForm &form);
		void	executeForm(AForm const &form);

		
		class GradeTooHighException : public std::exception{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				const char *what() const throw();
		};
};
std::ostream& operator <<(std::ostream& outputStream, const Bureaucrat& obj);
#endif
