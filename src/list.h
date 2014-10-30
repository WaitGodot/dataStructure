/*
 *	auchor : randy.
 *	list
 *
 */

#ifndef __LIST_H__
#define __LIST_H__

#include <cstddef>

template<typename T>
class list 
{
	pulic:
		typedef T			value_type;
		typedef T*			iterator;
		typedef const T*	const_iterator;
		typedef T&			reference;
		typedef const T&	const_reference;
		typedef std::size_t size_type;

	pravite:
		T data;

};


#endif
