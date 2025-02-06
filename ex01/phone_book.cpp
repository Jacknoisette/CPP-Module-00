/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:06:19 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/06 16:40:44 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

void	add_func(PhoneBook *phonebook)
{
	Contact	new_contact;
	
	new_contact.changeContact();
	phonebook->addContact(new_contact);
	phonebook->contactCount++;
}

void	search_func(PhoneBook *phonebook)
{
	std::string	str;
	int			result;
	
	std::getline(std::cin, str);
	result = atoi(str.c_str());
	if (result < 8 && result > -1)
		phonebook->contact[result].display();
	else
		std::cout << "PhoneBook is not able to have this input" << std::endl;
}

int main(void)
{
	PhoneBook	phonebook;
	std::string	str;
	// std::string	add = "ADD";
	// std::string search = "SEARCH";
	// std::string exit = "EXIT";
	// int 	count;
	
	phonebook.contactCount = 0;
	while (1)
	{
		std::getline(std::cin, str);
		if (str == "ADD")
			add_func(&phonebook);
		if (str == "SEARCH")
			search_func(&phonebook);
		if (str == "EXIT")
			break ;
	}
}