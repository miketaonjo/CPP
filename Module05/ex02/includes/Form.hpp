/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:27:05 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/16 19:33:51 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class AForm
{
    public:
		AForm(void);
		AForm(std::string name, int signGrade, int execGrade);
		AForm(AForm const &obj);
		AForm& operator=(AForm const &obj);
		virtual ~AForm(void);
		const std::string& getName(void) const;
		bool getSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExec(void) const;
		void beSigned(Bureaucrat const &one);
		virtual void execute(Bureaucrat const &executor) const = 0;
		void checkExecute(Bureaucrat const &one) const;

    private:
		class GradeTooHighException : public std::exception
        {
            public:
            const char *what(void) const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
            const char *what(void) const throw();
        };
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExec;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
