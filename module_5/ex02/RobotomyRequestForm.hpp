/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:02:43 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/18 15:24:59 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	__RobotomyRequestForm__
# define	__RobotomyRequestForm__

# include "AForm.hpp"
# include <string>
# include <exception>


class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
	RobotomyRequestForm(void);
public:
	RobotomyRequestForm(std::string const& target);
	RobotomyRequestForm(RobotomyRequestForm const& scform);
	virtual RobotomyRequestForm&	operator=(RobotomyRequestForm const& scform);

	std::string	get_target() const;
	void	execute(Bureaucrat const& bureaucrat) const;
	

};

std::ostream& operator<<(std::ostream& os, RobotomyRequestForm const& scform);

#endif