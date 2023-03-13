/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:49:21 by mcloarec          #+#    #+#             */
/*   Updated: 2023/02/15 14:55:32 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat 
{
    public:
	    Bureaucrat(void);
        ~Bureaucrat(void);
        Bureaucrat(std::string name, int grade);
	    Bureaucrat(Bureaucrat const &obj);
	    Bureaucrat& operator=(Bureaucrat const &obj);
	    std::string getName() const;
	    int getGrade() const;
	    void incrementGrade(void);
	    void decrementGrade(void);

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
	    int _grade;
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &one);

#endif
