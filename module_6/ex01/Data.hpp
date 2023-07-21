/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:40:24 by snaggara          #+#    #+#             */
/*   Updated: 2023/07/21 14:11:37 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DATA__
# define __DATA__

# include <string>

class Data
{
public:
	Data(std::string const sentence);
	Data(Data const& data);
	std::string m_sentence;
	
	~Data();
	Data&	operator=(Data const& data);
};

#endif