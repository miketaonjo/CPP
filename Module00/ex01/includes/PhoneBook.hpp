/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:25:55 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/05 15:17:12 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class	PhoneBook
{
	public:
		PhoneBook(void);
		void	AddContact(void);
		void	PrintContact(void);

	private:
		Contact	contacts[9];
		int		nb_contact;
		int		index;
};

#endif
