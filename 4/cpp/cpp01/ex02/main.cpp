/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:12:38 by yje               #+#    #+#             */
/*   Updated: 2023/02/16 16:47:21 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str; //참조자 str 변수의 다른 이름으로 str과 같은 메모리 공간 참조

	std::cout << "display address of string" << std::endl;
	std::cout << "str : " << &str << std::endl;
	std::cout << "stringPTR : " << stringPTR << std::endl;
	std::cout << "stringREF : " << &stringREF << std::endl;

	std::cout << "display value of string" << std::endl;
	std::cout << "str : " << str << std::endl;
	std::cout << "stringPTR : " << *stringPTR << std::endl;
	std::cout << "stringREF : " << stringREF << std::endl;

}


