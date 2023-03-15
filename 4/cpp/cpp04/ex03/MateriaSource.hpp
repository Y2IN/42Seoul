/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:02:10 by yje               #+#    #+#             */
/*   Updated: 2023/03/15 20:09:42 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H_
# define MATERIASOURCE_H_

# include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource {
	private :
			AMateria* _amateria[4];

	public :
			MateriaSource();
			MateriaSource(const MateriaSource &);
			MateriaSource &operator=(const MateriaSource &);
			~MateriaSource();
			AMateria	*createMateria(std::string const & type);
			void	learnMateria(AMateria *);
			AMateria	*getMateria(int idx) const;
};

#endif
