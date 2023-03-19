/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 00:15:59 by yje               #+#    #+#             */
/*   Updated: 2023/03/19 00:50:21 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int main()
{
	{
		std::cout << "--------test1--------" << std::endl;
		try
		{
			Bureaucrat test("test", 1);
			Bureaucrat test2("test2", 150);
			std::cout << test << std::endl;
			std::cout << test2 << std::endl;
			test.incrementGrade(); // 예외 발생
			test2.decrementGrade();
            // std::cout << test << std::endl;
			// std::cout << test2 << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "--------test2--------" << std::endl;
		try
		{
			Bureaucrat test("test", 1);
			Bureaucrat test2("test2", 150);
			std::cout << test << std::endl;
			std::cout << test2 << std::endl;
			test.decrementGrade();
			test2.incrementGrade();
			std::cout << test << std::endl;
			std::cout << test2 << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << "--------test3--------" << std::endl;
		try
		{
			Bureaucrat test2("test2", 151);
			Bureaucrat test("test", 0); // 예외 발생
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
    {
        std::cout << "--------test4--------" << std::endl;
		try
		{
			Bureaucrat test("test", 0); // 예외 발생
			Bureaucrat test2("test2", 151);
            test.decrementGrade();
			test2.incrementGrade();
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
    }
}