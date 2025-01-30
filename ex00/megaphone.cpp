/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:06:52 by jdhallen          #+#    #+#             */
/*   Updated: 2025/01/30 12:30:35 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	int	i = 1;
	int	j = 0;
	
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			std::cout << (char)std::toupper(argv[i][j]);
			j++;
		}
		i++;
		if (i < argc)
			std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}