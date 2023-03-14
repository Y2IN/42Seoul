/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:51:24 by yje               #+#    #+#             */
/*   Updated: 2023/03/14 14:21:17 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H_
#define CAT_H_

#include "Animal.hpp"

class Cat : public Animal {
	public :
		Cat();
		Cat(const Cat&);
		Cat& operator=(const Cat&);
		~Cat();
		void	makeSound() const;
};

#endif
