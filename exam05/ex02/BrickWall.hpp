#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP

# include "ATarget.hpp"

class BrickWall : public ATarget
{
	public:
		BrickWall(void);
		BrickWall(BrickWall const &src);
		virtual ~BrickWall(void);

		BrickWall	&operator=(BrickWall const &src);

		virtual ATarget	*clone(void) const;

	private:
};

#endif
