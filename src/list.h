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
		
		static const size_type LIST_HEAD  = 0;
		static const size_type LIST_TAIL  = 1;

		class listNode{
			public:
				value_type data;
				listNode* previous;
				listNode* next;
		};

		list(){
			head = tail = 0;
			m_size = 0;
		}
		
		void insert( reference value , pos = LIST_TAIL){
			__insert(value,pos);
		}
	pravite:
		//function.
		void __insert(reference value , size_type pos){
			if ( !head || !tail )
			{	
				listNode
			}
			if ( pos == LIST_TAIL )
			{
				
			}
		}
		
		// data.
		listNode* head;
		listNode* tail;
		size_type m_size;

};


#endif
