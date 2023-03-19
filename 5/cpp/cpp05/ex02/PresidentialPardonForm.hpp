/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 00:54:17 by yje               #+#    #+#             */
/*   Updated: 2023/03/20 01:41:45 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm {
    private :
        std::string _target;
    public :
        PresidentialPardonForm();
        PresidentialPardonForm& operator=(const PresidentialPardonForm&);
        PresidentialPardonForm(std::string);
        PresidentialPardonForm(const PresidentialPardonForm&);
        ~PresidentialPardonForm();

        void	execute(Bureaucrat const &executor) const;

};

#endif