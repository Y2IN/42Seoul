/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:20:46 by yje               #+#    #+#             */
/*   Updated: 2023/02/16 16:06:08 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_H__
# define ZOMBIE_H__

#include <string>

class Zombie {
    private:
        std::string _name;
    public:
		Zombie(void);
        Zombie(std::string name);
        ~Zombie();
        void announce(void);
		void setName(std::string name);
};
Zombie* zombieHorde( int N, std::string name );
#endif
