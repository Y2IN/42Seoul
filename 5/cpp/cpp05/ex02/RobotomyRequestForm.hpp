/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 00:51:18 by yje               #+#    #+#             */
/*   Updated: 2023/03/20 01:41:41 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm {
    private :
        std::string _target;

    public :
        RobotomyRequestForm();
        RobotomyRequestForm& operator=(const RobotomyRequestForm &);
        RobotomyRequestForm(std::string _target);
        RobotomyRequestForm(const RobotomyRequestForm&);
        ~RobotomyRequestForm();

        void	execute(Bureaucrat const &executor) const;
};

#endif