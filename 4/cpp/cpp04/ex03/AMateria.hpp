/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:09:04 by yje               #+#    #+#             */
/*   Updated: 2023/03/15 21:15:20 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H_
#define AMATERIA_H_

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected :
		std::string _type;
	public :
		// A default constructor
		AMateria();
		// 형변환이 일어나지 않도록 제한하는 키워드 -> explicit
		explicit AMateria(std::string const& type);
		// A copy constructor
		AMateria(const AMateria &);
		// A assignment operator overload
		AMateria& operator=(const AMateria &);
		// A destructor
		virtual ~AMateria();
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
