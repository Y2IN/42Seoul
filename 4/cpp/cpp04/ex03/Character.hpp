/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:12:01 by yje               #+#    #+#             */
/*   Updated: 2023/03/16 22:22:40 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H_
#define CHARACTER_H_

# include"ICharacter.hpp"

class Character: public ICharacter {
	private :
		std::string _name;
		AMateria* _inventory[4];
		int         _floorSize;    
	    AMateria*   _floor[10];


	public :
		Character();
		Character(std::string const& name);
		Character(const Character&);
		Character& operator=(const Character&);
		~Character();
		std::string const &getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		AMateria const *getMateriaByIdx(int idx) const;
		void floor(int idx);
		void cleanFloor();
};

#endif
