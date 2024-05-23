#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <iostream>
# include <vector>

# include "ATarget.hpp"
# include "Dummy.hpp"
# include "BrickWall.hpp"

class	TargetGenerator
{
	public:
		TargetGenerator(void);
		~TargetGenerator(void);

		void learnTargetType(ATarget* target);
		void forgetTargetType(std::string const &target);
		ATarget* createTarget(std::string const &type);

	private:
		TargetGenerator(TargetGenerator const &src);

		TargetGenerator	&operator=(TargetGenerator const &src);

		std::vector<ATarget *>	_tg;
};

#endif
