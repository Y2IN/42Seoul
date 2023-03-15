/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:58:15 by yje               #+#    #+#             */
/*   Updated: 2023/03/15 19:58:22 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H_
# define ICE_H_

#include "AMateria.hpp"

class Ice : public AMateria {
	public :
		Ice();
		Ice(const Ice&);
		Ice& operator=(const Ice&);
		~Ice();
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
