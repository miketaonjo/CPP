/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:27:30 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/09 12:02:14 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain &obj);
		Brain& operator=(const Brain &obj);
		~Brain(void);
		std::string getIdeas(int n) const;
		void setIdeas(std::string s, int n);

	private:
		std::string ideas[100];
};

#endif
