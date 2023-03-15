/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:50:26 by yje               #+#    #+#             */
/*   Updated: 2023/03/15 20:01:34 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CURE_H_
# define CURE_H_

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure&);
		Cure& operator=(const Cure&);
		~Cure();
		AMateria* clone() const;
		void use(ICharacter& target);
};
#endif
