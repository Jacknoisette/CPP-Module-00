/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:06:19 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/24 18:36:46 by jdhallen         ###   ########.fr       */
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

void	ft_printf_case(std::string temp)
{
	if (temp.length() > 10)
		temp = temp.substr(0, 9) + ".";
	std::cout << std::right << std::setw(10) << temp << "|";
}

void	ft_printf_row(PhoneBook *phonebook, int row)
{
	std::string str;
	std::stringstream ss;
	
    ss << row;
    str = ss.str();
	std::cout << "|";
	ft_printf_case(str);
	ft_printf_case(phonebook->contact[row].first_name);
	ft_printf_case(phonebook->contact[row].last_name);
	ft_printf_case(phonebook->contact[row].nickname);
	std::cout << std::endl;	
}

void	ft_printf_search(PhoneBook *phonebook)
{
	std::cout << "\033[4m";
	std::cout << std::right << std::setw(12) << "";
	std::cout << std::right << std::setw(11) << "";
	std::cout << std::right << std::setw(11) << "";
	std::cout << std::right << std::setw(11) << "";
	std::cout << std::endl;	
	std::cout << "|";
	ft_printf_case("id");
	ft_printf_case("first_name");
	ft_printf_case("last_name");
	ft_printf_case("nickname");
	std::cout << std::endl;	
	for (int row = 0; row < 8; row++)
		ft_printf_row(phonebook, row);
	std::cout << "\033[0m";
}

void	search_func(PhoneBook *phonebook)
{
	std::string	str;
	int			result;
	
	ft_printf_search(phonebook);
	std::getline(std::cin, str);
	if (!str.empty() && std::find_if(str.begin(), str.end(), [](char c) { return !std::isdigit(c); }) == str.end())
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