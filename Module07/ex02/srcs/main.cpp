/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:05:03 by mcloarec          #+#    #+#             */
/*   Updated: 2023/03/06 16:28:58 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include "../includes/Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

	Array<char> letters(5);
	letters[0] = 'a';
	letters[1] = 'b';
	letters[2] = 'c';
	letters[3] = 'd';
	letters[4] = 'e';

	std::cout << letters[3] << std::endl;
	std::cout << letters[0] << std::endl;

	try
	{
		letters[5] = 'f';
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    return 0;
}
