#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
//# include <stdint.h>

typedef unsigned long int uintptr_t;

typedef struct s_data
{
	int nb;
}		Data;

class	Serializer
{
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data*		deserialize(uintptr_t raw);
	
	private:
		Serializer(void);
		Serializer(Serializer const &src);
		~Serializer(void);

		Serializer	&operator=(Serializer const &src);
};

#endif
