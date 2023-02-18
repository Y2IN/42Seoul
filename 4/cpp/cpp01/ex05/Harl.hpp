/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:31:33 by yje               #+#    #+#             */
/*   Updated: 2023/02/18 14:53:44 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HARL_H_
# define HARL_H_

#include <iostream>
#include <string>

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:
		void complain(std::string level);
};

#endif
