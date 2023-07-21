/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:08:50 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/18 15:13:18 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	__PresidentialPardonForm__
# define	__PresidentialPardonForm__

# include "AForm.hpp"
# include <string>
# include <exception>


class PresidentialPardonForm : public AForm
{
private:
	std::string _target;

	PresidentialPardonForm(void);
public:
	PresidentialPardonForm(std::string const& target);
	PresidentialPardonForm(PresidentialPardonForm const& scform);
	virtual PresidentialPardonForm&	operator=(PresidentialPardonForm const& scform);

	std::string	get_target() const;
	void	execute(Bureaucrat const& bureaucrat) const;
	

};

std::ostream& operator<<(std::ostream& os, PresidentialPardonForm const& scform);

#endif