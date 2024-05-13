#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <cctype>
# include <cstdlib>

class	RPN
{
	public:
		RPN(void);
		RPN(RPN const &src);
		~RPN(void);

		RPN	&operator=(RPN const &src);

		void	solve(std::string const &input);

	private:
		std::stack<int>	_pile;
};

#endif
