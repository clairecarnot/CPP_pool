#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP

# include <iostream>
# include "ATarget.hpp"

class	BrickWall : public ATarget
{
	public:
		BrickWall();
		BrickWall(BrickWall const &src);
		virtual ~BrickWall();

		BrickWall	&operator=(BrickWall const &src);

		virtual ATarget	*clone() const;

	private:
};

#endif
