/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:28:54 by yje               #+#    #+#             */
/*   Updated: 2023/02/16 17:42:31 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H_
#define HUMANA_H_

#include "Weapon.hpp"
#include <string>

class HumanA {
  private:
    std::string _name;
    Weapon &_type;

  public:
    HumanA(const std::string name, Weapon *type);
    ~HumanA();
    void attack(void) const;
};

#endif
