/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:31:15 by yje               #+#    #+#             */
/*   Updated: 2023/02/18 15:00:51 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
	Harl harl;

	std::cout << "DEBUG : " ;
	harl.complain("DEBUG");
	std::cout << "INFO : " ;
	harl.complain("INFO");
	std::cout << "WARNING : " ;
	harl.complain("WARNING");
	std::cout << "ERROR : " ;
	harl.complain("ERROR");

}
