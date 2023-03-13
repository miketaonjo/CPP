/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 06:15:40 by mcloarec          #+#    #+#             */
/*   Updated: 2023/03/11 19:06:46 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int>  mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << "top : " << mstack.top() << std::endl;

	mstack.pop();
	std::cout << "size : " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << std::endl;

	std::list<int>  l;
	l.push_back(5);
	l.push_back(17);

	std::cout << "top : " << l.back() << std::endl;

	l.pop_back();
	std::cout << "size : " << l.size() << std::endl;

	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	l.push_back(0);

	std::list<int>::iterator it1 = l.begin();
	std::list<int>::iterator it2 = l.end();
	
	++it1;
	--it1;

	while (it1 != it2)
	{
		std::cout << *it1 << std::endl;
		++it1;
	}

	std::cout << std::endl;

	MutantStack<char>  cstack;
	cstack.push('a');
	cstack.push('b');

	std::cout << "top : " << cstack.top() << std::endl;

	cstack.pop();
	std::cout << "size : " << cstack.size() << std::endl;

	cstack.push('c');
	cstack.push('d');
	cstack.push('e');
	cstack.push('f');

	MutantStack<char>::iterator ite1 = cstack.begin();
	MutantStack<char>::iterator ite2 = cstack.end();

	++ite1;
	--ite1;

	while (ite1 != ite2)
	{
		std::cout << *ite1 << std::endl;
		++ite1;
	}
	return(0);
}
