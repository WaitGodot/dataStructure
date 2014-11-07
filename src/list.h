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

		class iterator
		{
			friend list<T>;
			public:
				iterator(listNode* node = 0){
					m_node = node;
				}
				~iterator(){
					m_node = 0;
				}
				
				iterator(const iterator& rv){
					this->m_node = rv.m_node;
				}				
				iterator& operator=(const iterator& rv){
					this->m_node = rv.m_node;
					return *this;
				}
				bool operator==(const iterator& rv){
					return this->m_node == rv.m_node;
				}
				bool operator!=(const iterator& rv){
					return this->m_node != rv.m_node;
				}
				reference operator*(){
					return m_node->data;
				}
				iterator operator++(int){
					iterator rt = *this;
					m_node = m_node->next;
					return rt;
				}
				iterator& operator++(){
					m_node = m_node->next;
					return *this;
				}

			protected:
				listNode* m_node;
		};

		class const_iterator : public iterator
		{
			friend list<T>;
			public:
				const_iterator(listNode* node):
					iterator(node)
				{

				}
				~const_iterator(){

				}

				const_reference operator*()const {
					return iterator::operator*();
				}
		};
		
		typedef iterator iterator;
		typedef const_iterator const_iterator;

		list(){
			m_head = m_tail = 0;
			m_size = 0;
		}
		~list(){
			__destructor();
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
			__removeNode(__find(value));
		}
		void remove_front(){
			__removeNode(m_head);
		}		
		void remove_back(){
			__removeNode(m_tail);
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
			m_head = m_tail = 0;
			m_size = 0;
		}
		void print(){
			listNode* node = m_head;
			while(node){
				std::cout<< node->data << "\t";
				node = node->next;
			}
			std::cout<<"\n";
		}

		//iterator.
		iterator remove(iterator it){
			__removeNode((it++).m_node);
			return it;
		}
		iterator begin(){
			return iterator(m_head);
		}
		const_iterator cbegin(){
			return const_iterator(m_head);
		}
		iterator end(){
			return iterator(m_tail->next);
		}
		const_iterator cend(){
			return iterator(m_tail->next);
		}
	private:
		//function.
		void __destructor(){
			listNode* node = m_head;
			listNode* temp = node;
			while(node){
				node = node->next;
				delete temp;
				temp = node;
			}
			m_head = m_tail = 0;
			m_size = 0;
		}

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

		void __removeNode(listNode* node){
			if ( node == 0)
			{
				return ;
			}
			if(node->previous == 0)
			{
				m_head = node->next;
				m_head->previous = 0;
			}else{
				node->previous = node->next;
				if(node->next == 0){
					m_tail = node->previous;
				}
			}
			delete node; node = 0;
			m_size -= 1;
		}
		
		// data.
		listNode* m_head;
		listNode* m_tail;
		size_type m_size;

};


#endif
