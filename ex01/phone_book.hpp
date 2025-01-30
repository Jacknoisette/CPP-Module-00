/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:56:10 by jdhallen          #+#    #+#             */
/*   Updated: 2025/01/30 14:05:29 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <iostream>
#include <cctype>

class Contact {
private :
	std::string first_name
	std::string last_name
	std::string nickname
	std::string phone_number
	std::string darkest_secret

public :
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
		std::getline(std::cin, darkest secret);
	}
	
	void display() const {
		std::cout << "First name: " << first_name << std::endl;
		std::cout << "Last name: " << last_name << std::endl;
		std::cout << "Nickname: " << nickname << std::endl;
		std::cout << "Phone number: " << phone_number << std::endl;
		std::cout << "Darkest secret: " << darkest_secret << std::endl;
	}
}

class PhoneBook {
public :
	Contact contact[8];
	int contactCount;

    PhoneBook() : contactCount(0) {}\

	void addContact(const Contact& newContact){
		contact[contactCount % 8] = newContact;
	}
	
	void displayPhoneBook(){
		for (int i = 0; i < 8; i++)
			contact[i].display();
	}
}
#endif