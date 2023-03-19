/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:07:00 by yje               #+#    #+#             */
/*   Updated: 2023/03/19 22:42:46 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form {
	private :
		const std::string _name;
		bool _beSigned;
		const int _signGrade;
		const int _executeGrade;
        Form();

	public :
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form&);
		Form &operator=(const Form &);
		~Form();

		std::string	getName() const;
		bool getBeSigned() const;
        int getSignGrade() const;
		int getExecuteGrade() const;
		std::string getisSignd() const;

		void	beSigned(const Bureaucrat&);

		class GradeTooHighException: public std::exception {
			public :
				const char	*what() const throw();
		};

		class GradeTooLowException: public std::exception {
			public :
				const char	*what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, const Form &form);

#endif