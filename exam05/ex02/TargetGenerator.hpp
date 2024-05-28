#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <iostream>
# include <map>

# include "Warlock.hpp"

class	TargetGenerator
{
	public:
		TargetGenerator();
		TargetGenerator(TargetGenerator const &src);
		~TargetGenerator();

		TargetGenerator	&operator=(TargetGenerator const &src);

		void		learnTargetType(ATarget* target);
		void		forgetTargetType(std::string const &type);
		ATarget*	createTarget(std::string const &type);

	private:
		std::map<std::string, ATarget *>	_gen;
};

#endif
