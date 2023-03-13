/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:21:54 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/21 14:12:20 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base *generate(void)
{
	Base *tmp = NULL;
	srand(time(NULL));
	int i = rand() % 3;

	switch(i)
	{
		case 0:
			tmp = new A();
			break;
		case 1:
			tmp = new B();
			break;
		case 2:
			tmp = new C();
			break;
		default:
			break;
	}
	// if (rand() % 3 == 0)
	// 	tmp = new A();
	// else if (rand() % 3 == 1)
	// 	tmp = new B();
	// else
	// 	tmp = new C();
	return (tmp);
}

void identify(Base *p)
{
	A *test1 = dynamic_cast<A *>(p);
	if (test1 == NULL)
		std::cout << "Unsuccessful conversion" << std::endl;
	else
	{
		std::cout << "Pointer's type : A" << std::endl;
		return ;
	}
	B *test2 = dynamic_cast<B *>(p);
	if (test2 == NULL)
		std::cout << "Unsuccessful conversion" << std::endl;
	else
	{
		std::cout << "Pointer's type : B" << std::endl;
		return ;
	}
	C *test3 = dynamic_cast<C *>(p);
	if (test3 == NULL)
		std::cout << "Unsuccessful conversion" << std::endl;
	else
	{
		std::cout << "Pointer's type : C" << std::endl;
		return ;
	}
}

void identify(Base &p)
{
	try
	{
		A &test1 = dynamic_cast<A &>(p);
		std::cout << "Type is A" << std::endl;
		static_cast<void>(test1);
		return ;
	}
	catch (std::exception &e)
	{
		std::cerr << "Unsuccessful conversion : " << e.what() << std::endl;
	}
	try
	{
		B &test2 = dynamic_cast<B &>(p);
		std::cout << "Type is B" << std::endl;
		static_cast<void>(test2);
		return ;
	}
	catch (std::exception &e)
	{
		std::cerr << "Unsuccessful conversion : " << e.what() << std::endl;
	}
	try
	{
		C &test3 = dynamic_cast<C &>(p);
		std::cout << "Type is C" << std::endl;
		static_cast<void>(test3);
		return ;
	}
	catch (std::exception &e)
	{
		std::cerr << "Unsuccessful conversion : " << e.what() << std::endl;
	}
}

int main(void)
{
	Base *one;
	Base *two;
	Base *b;

	one = generate();
	two = generate();
	b = generate();

	Base &three = *b;
	
	identify(one);
	identify(two);
	identify(three);

	delete one;
	one = NULL;
	delete two;
	two = NULL;
	delete b;
	b = NULL;
	return (0);
}
