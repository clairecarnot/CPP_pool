#include "Serializer.hpp"

// CONSTRUCTORS / DESTRUCTORS -------------------------------------------------------------- //

Serializer::Serializer(void)
{
}

Serializer::Serializer(Serializer const &src)
{
	*this = src;
	return ;
}

Serializer::~Serializer(void)
{
}


// OPERATORS ------------------------------------------------------------------------------- //

Serializer	&Serializer::operator=(Serializer const &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

// GETTERS / SETTERS ----------------------------------------------------------------------- //


// FUNCTIONS ------------------------------------------------------------------------------- //


// STATIC ELEMENTS ------------------------------------------------------------------------- //

/*
 uintptr_t is not a standard integer type; it's defined as an unsigned integer type capable of holding a pointer
  Thus there's no implicit conversion from int to uintptr_t
  We could use static casting because it is explicit and performed at compile-time (clear conversion path from int to uintptr_t)
  But we use reinterpretation casting because of the deserialize()
*/

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

/*
 No static casting here because it is used for conversions between related types, such as different pointer types or base/derived class conversions.
 Using it in this context would be inappropriate because uintptr_t and pointers are not related types in terms of the type system.
 Since uintptr_t is not a standard pointer type but rather an integer type capable of holding a pointer, we use reinterpret_cast to convert it back into a pointer type.
 */

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
