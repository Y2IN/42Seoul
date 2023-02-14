/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:00:16 by yje               #+#    #+#             */
/*   Updated: 2023/02/14 17:08:56 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_H__
# define ZOMBIE_H__

#include <string>
#include <iostream>

class Zombie {
    private:
        std::string _name;

    public:
        Zombie(std::string name);
        ~Zombie();
        void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
