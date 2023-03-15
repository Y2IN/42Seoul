/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:51:24 by yje               #+#    #+#             */
/*   Updated: 2023/03/15 17:47:35 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H_
#define CAT_H_

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain *brain;
	public :
		Cat();
		Cat(const Cat& cat);
		Cat(const Brain& origin);
		Cat& operator=(const Cat& cat);
		~Cat();
		void	makeSound() const;
		void	printBrain();
		void	setBrain(std::string);
};

#endif
