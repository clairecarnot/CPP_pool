#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(Animal const &src);
		virtual ~Animal(void);

		Animal	&operator=(Animal const &src);

		std::string	getType(void) const;
		virtual void	makeSound(void) const;

	protected:
		std::string	_type;
	
	private:
};

#endif
