/*
 * anchor randy
 * stack
 *
 */

#ifndef __LIST_H__
#define __LIST_H__

#include <cstddef>

template<typename T>
class stack
{
	public:
		typedef	T			value_type;
		typedef	T&			reference;
		typedef const T&	const_reference;
		typedef	T*			pointer;
		typedef size_t		size_type;
		typedef	int			index_type;
		
		static const int	DEFAULT_CAPACITY	=	2;
		static const int	NO_VALUE			=	0;
		reference	top(){
			if( m_ size == 0)
			{
				return -1;
			}
			return m_data[m_size -1];
		}
		value_type	pop(){
			if
		}
		void		push(const_reference value);
		reference	at(index_type index);

		stack(){
			m_size = m_capacity = 0;
			m_data = 0;
		}

	private:
		size_type	m_size;
		size_type	m_capacity;
		pointer		m_pointer;	
}


#endif
