#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &src);
		~WrongAnimal(void);

		WrongAnimal	&operator=(WrongAnimal const &src);

		std::string	getType(void) const;
		void	makeSound(void) const;

	protected:
		std::string	_type;
	
	private:
};

#endif
