/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:58:53 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/16 19:37:00 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm()
{
	this->_target = "Anonymous";
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", 145, 37)
{
	this->_target = target;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj) : AForm(obj)
{
	*this = obj;
    return ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &obj)
{
	if (this != &obj)
    {
	    this->_target = obj._target;
	    this->AForm::operator=(obj) = obj;
    }
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    return ;
}

void ShrubberyCreationForm::execute(Bureaucrat const &one) const
{
	std::ofstream ofs;
	std::string out;

	this->checkExecute(one);
	out = this->_target;
	out.append("_shruberry");
	ofs.open(out.c_str());
	if (ofs.fail())
	{
		std::cout << "Open failed" << std::endl;
		return ;
	}
	ofs <<
		"               ,@@@@@@@,                \n"
		"       ,,,.   ,@@@@@@/@@,  .oo8888o.    \n"
		"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o   \n"
		"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'  \n"
		"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'  \n"
		"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'   \n"
		"    `&%\\ ` /%&'    |.|        \\ '|8'    \n"
		"        |o|        | |         | |      \n"
		"        |.|        | |         | |      \n"
		" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		<< std::endl;
	ofs.close();
	std::cout << "Go check my beautiful trees" << std::endl;
	// try
	// {
	// 	this->checkExecute(one);
	// 	out = this->_target;
	// 	out.append("_shruberry");
	// 	ofs.open(out.c_str());
	// 	if (ofs.fail())
	// 	{
	// 		std::cout << "Open failed" << std::endl;
	// 		return ;
	// 	}
	// 	ofs <<
	// 		"               ,@@@@@@@,                \n"
	// 		"       ,,,.   ,@@@@@@/@@,  .oo8888o.    \n"
	// 		"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o   \n"
	// 		"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'  \n"
	// 		"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'  \n"
	// 		"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'   \n"
	// 		"    `&%\\ ` /%&'    |.|        \\ '|8'    \n"
	// 		"        |o|        | |         | |      \n"
	// 		"        |.|        | |         | |      \n"
	// 		" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	// 		<< std::endl;
	// 	ofs.close();
	// 	std::cout << "Go check my beautiful trees" << std::endl;
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << this->_target << " is either unsigned or " << one.getName() << " grade's is too low" << std::endl;
	// }
}
