/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:14:11 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/18 14:32:48 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	__ShrubberyCreationForm__
# define	__ShrubberyCreationForm__

# include "AForm.hpp"
# include <string>


class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;

	ShrubberyCreationForm(void);
public:
	ShrubberyCreationForm(std::string const& target);
	ShrubberyCreationForm(ShrubberyCreationForm const& scform);
	virtual ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& scform);

	std::string	get_target() const;
	void	execute(Bureaucrat const& bureaucrat) const;
	

};

std::ostream& operator<<(std::ostream& os, ShrubberyCreationForm const& scform);

#define ASCII_TREE \
"          .     .  .      +     .      .          .\n" \
"     .       .      .     #       .           .\n" \
"        .      .         ###            .      .      .\n" \
"      .      .   \"#:. .:##\"##:. .:#\"  .      .\n" \
"          .      . \"####\"###\"####\"  .\n" \
"       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n" \
"  .             \"#########\"#########\"        .        .\n" \
"        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n" \
"     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n" \
"                .\"##\"#####\"#####\"##\"           .      .\n" \
"    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n" \
"      .     \"#######\"##\"#####\"##\"#######\"      .     .\n" \
"    .    .     \"#####\"\"#######\"\"#####\"    .      .\n" \
"            .     \"      000      \"    .     .\n" \
"       .         .   .   000     .        .       .\n" \
"........................O000O...................................\n"
#endif