/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duarte33 <duarte33@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:15:09 by duarte33          #+#    #+#             */
/*   Updated: 2023/07/12 18:23:19 by duarte33         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* Replica da funcao strcmp, 'const std::string& str1' e uma referencia para um 
objeto e nao um pointer. Referencias permitem mandar os objetos sem criar copias
deles e duplicar recursos. */
int ft_strcmp(const std::string& str1, const std::string& str2) {
    size_t len1 = str1.length();
    size_t len2 = str2.length();
    size_t minLen = std::min(len1, len2);

    for (size_t i = 0; i < minLen; ++i) {
        if (str1[i] < str2[i])
            return -1;
        else if (str1[i] > str2[i])
            return 1;
    }
    if (len1 < len2)
        return -1;
    else if (len1 > len2)
        return 1;
    return 0;
}

int main(void)
{
	PhoneBook myBook;
	std::string input;

	while (1)
	{
		input = readLine("Enter a command: ");
		if ((ft_strcmp(input, "ADD") == 0))
			myBook.AddContact();
		else if (ft_strcmp(input, "SEARCH") == 0)
			myBook.ShowContacts();
		else if ((ft_strcmp(input, "EXIT") == 0))
			break;
	}
}