#ifndef INCLUDES_HPP
# define INCLUDES_HPP

# include <iostream>

class	Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void announce (void) const;

	private:
		std::string	_name;

};

# endif
