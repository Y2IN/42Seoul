/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:31:38 by yje               #+#    #+#             */
/*   Updated: 2023/02/16 17:32:27 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H_
#define HUMANB_H_

#include "Weapon.hpp"
#include <string>

class HumanB {
  private:
    std::string _name;
    Weapon *_type;

  public:
    HumanB( const std::string &name );
    ~HumanB();
    void attack( void ) const;
    void setWeapon( Weapon *type );
};

#endif
