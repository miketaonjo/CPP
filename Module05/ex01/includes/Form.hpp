/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:27:05 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/15 18:46:27 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form
{
    public:      
        Form(void);
        Form(std::string name, int signGrade, int execGrade);
        Form(Form const &obj);
        Form& operator=(Form const &obj);
        ~Form(void);
        const std::string& getName(void) const;
        bool getSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExec(void) const;
        void beSigned(Bureaucrat const &one);

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

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
