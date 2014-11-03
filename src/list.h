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
	public:
		typedef T			value_type;
		typedef T*			iterator;
		typedef const T*	const_iterator;
		typedef T&			reference;
		typedef const T&	const_reference;
		typedef std::size_t size_type;
		
		static const size_type LIST_HEAD  = 0;
		static const size_type LIST_TAIL  = 1;

		struct listNode{
				value_type data;
				listNode* previous;
				listNode* next;
		};

		list(){
			m_head = m_tail = 0;
			m_size = 0;
		}
		
		//insert
		void insert_front(const_reference value){
			__insert(value,LIST_HEAD);
		}
		void insert_back(const_reference value){
			__insert(value,LIST_TAIL);
		}
		void insert(const_reference value){
			insert_front(value);
		}
		//find
		reference front(){
			return m_head->data;
		}
		reference back(){
			return m_tail->data;
		}
		//remove.
		void remove(const_reference value){
			listNode* node = __find(value);
			if ( node == 0)
			{
				return ;
			}
			if(node->previous == 0)
			{
				m_head = node->next;
			}else{
				node->previous = node->next;
				if(node->next == 0){
					m_tail = node->previous;
				}
			}
			
			delete node;node = 0;
			m_size -= 1;
		}
		void remove_front(){
			if (m_head){
				listNode* node = m_head;
				m_head = m_head->next;
				delete node ; node = 0;
				m_size -= 1;
			}
		}		
		void remove_back(){
			if(m_tail){
				listNode* node = m_tail;
				m_tail = m_tail->previous;
				delete node ; node = 0;
				m_size -= 1;
			}
		}
		void filter(){

		}
		//
		bool empty(){
			return m_size == 0;
		}
		size_type size(){
			return m_size;
		}
		
		void clear(){
			listNode* node = m_head;
			listNode* temp = node;
			while(node){
				node = node->next;
				delete temp;
				temp = node;
			}
		}
		void print(){
			listNode* node = m_head;
			while(node){
				std::cout<< node->data << "\t";
				node = node->next;
			}
			std::cout<<"\n";
		}
	private:
		//function.
		void __insert(const_reference value , size_type pos){
			listNode* node = new listNode();
			node->data = value;
			node->previous = node->next = 0;

			if ( !m_head || !m_tail )
			{	
				m_head = m_tail = node;
			}else if ( pos == LIST_TAIL )
			{
				m_tail->next = node;
				node->previous = m_tail;
				m_tail = node;
			}else{
				node->next = m_head;
				m_head->previous = node;
				m_head = node;
			}
			m_size += 1;
		}

		listNode* __find(const_reference value){
			listNode * result = 0;
			listNode * node = m_head;
			while(node)
			{
				if (value == node->data)
				{
					result = node;
					break;
				}
				node = m_head->next;
			}
			return result;
		}
		
		// data.
		listNode* m_head;
		listNode* m_tail;
		size_type m_size;

};


#endif
