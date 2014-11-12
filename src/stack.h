/*
 * anchor randy
 * stack
 *
 */

#ifndef	__STACK_H__
#define __STACK_H__

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
			return m_data[m_size -1];
		}
		value_type	pop(){
			value_type rt = top();
			m_size = m_size - 1;
			return rt;
		}
		void		push(const_reference value){
			if(m_size == m_capacity){
				m_capacity = m_capacity/2 + DEFAULT_CAPACITY;
				pointer tempdata = new value_type[m_capacity];
				if(m_data)
				{
					for(int i = 0 ; i < m_size ; i++)
					{
						tempdata[i] = m_data[i];
					}
				}
				delete [] m_data;
				m_data = tempdata;
			}
			m_size += 1;
			m_data[m_size - 1] = value;
		}
		//	the index: 1 ~ size.
		//	-1:  the top
		//	1: the tail.
		reference	at(index_type index){
			index = index > 0 ? index - 1 : m_size + index;
			return m_data[index];
		}

		bool		empty(){
			return m_size == 0;
		}
		size_type	size(){
			return m_size;
		}
		void		clear(){
			m_size = m_capacity = 0;
			delete [] m_data;
			m_data = 0;
		}

		stack(){
			m_size = m_capacity = 0;
			m_data = 0;
		}
		~stack(){
			m_size = m_capacity = 0;
			delete [] m_data;
			m_data = 0;
		}

		//TAG: will be removed
		void print(){
			std::cout<<"\n";
			for(int i = m_size -1 ; i >=0 ; i--)
			{
				std::cout<<m_data[i]<<"\t";
			}
			std::cout<<"\n";
		}
	private:
		size_type	m_size;
		size_type	m_capacity;
		pointer		m_data;	
};


#endif
