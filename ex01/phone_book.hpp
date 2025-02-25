/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:56:10 by jdhallen          #+#    #+#             */
/*   Updated: 2025/02/25 14:55:01 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include <iostream>
# include <sstream>
# include <iomanip>
# include <cctype>
# include <cstdlib>

class Contact {
private :
	std::string phone_number;
	std::string darkest_secret;
public :
	std::string first_name;
	std::string last_name;
	std::string nickname;
	
	void changeContact() {
		std::cout << "Enter first name: ";
		std::getline(std::cin, first_name);
		std::cout << "Enter last name: ";
		std::getline(std::cin, last_name);
		std::cout << "Enter nickname: ";
		std::getline(std::cin, nickname);
		std::cout << "Enter phone_number: ";
		std::getline(std::cin, phone_number);
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, darkest_secret);
		// std::cout << std::endl;	
	}
	
	void display() const {
		std::cout << "First name: " << first_name << std::endl;
		std::cout << "Last name: " << last_name << std::endl;
		std::cout << "Nickname: " << nickname << std::endl;
		std::cout << "Phone number: " << phone_number << std::endl;
		std::cout << "Darkest secret: " << darkest_secret << std::endl;
	}

	void display2() const {
		std::cout << "First name" << " | ";
		std::cout << "Last name " << " | ";
		std::cout << "Nickname  " << " | ";
		std::cout << "Phone nbr " << " | ";
		std::cout << "Secret    " << std::endl;
		std::cout << std::setw(10) << first_name;
		std::cout << " | ";
		std::cout << std::setw(10) <<  last_name;
		std::cout << " | ";
		std::cout << std::setw(10) <<  nickname;
		std::cout << " | ";
		std::cout << std::setw(10) <<  phone_number;
		std::cout << " | ";
		std::cout << std::setw(10) <<  darkest_secret;
		std::cout << std::endl;
	}
};

class PhoneBook {
public :
	Contact contact[8];
	int contactCount;

    PhoneBook() : contactCount(0) {}

	void addContact(const Contact& newContact){
		contact[contactCount % 8] = newContact;
	}
	
	void displayPhoneBook(){
		for (int i = 0; i < 8; i++)
			contact[i].display();
	}
};

#endif