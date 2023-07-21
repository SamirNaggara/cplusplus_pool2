/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:02:43 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/18 17:13:18 by snaggara         ###   ########.fr       */
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

	std::ostream&			print(std::ostream& os) const;

	std::string	get_target() const;
	void	execute(Bureaucrat const& bureaucrat) const;
	

};


#endif