/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:51:24 by yje               #+#    #+#             */
/*   Updated: 2023/03/14 20:59:02 by yje              ###   ########.fr       */
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
		virtual ~Cat();
		void	makeSound() const;
		void	printBrain();
		void	setBrain(std::string);
};

#endif
