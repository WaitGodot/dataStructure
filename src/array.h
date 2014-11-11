#ifndef _ARRAY_H__
#define _ARRAY_H__

/*
 *
 * auchor : randy
 * a simple array.
 *
 */

#include <cstddef>
#include "macroConfig.h"

namespace dataStructure
{

	template<typename T >
	class array
	{
		public:
		
			typedef T				value_type;
			typedef T*				iterator;
			typedef const T*		const_iterator;
			typedef T&				reference;
			typedef const T&		const_reference;
			typedef std::size_t		size_type;
			typedef std::ptrdiff_t	difference_type;
			
			static const size_type ARRAY_END				 = 2147463645;
			static const size_type ARRAY_DEFAULT_CAPACITY	 = 2;

			array(size_type capacity = 0){
				constructor(capacity);
			}

			void insert	(value_type value,size_type pos = ARRAY_END){
				__resize();
				__insert(value,pos);
			}

			const_reference	 cfind	(size_type pos) const{
				__checkRange(pos);
				return m_data[pos];
			}

			reference		 find	(size_type pos){
				__checkRange(pos);
				return m_data[pos];
			}
			//size_type		 find	(const_reference value);
			value_type		 remove	(size_type pos = ARRAY_END){
				__checkRange(pos);
				return __remove(pos);
			}
			
			reference operator[](size_type pos){
				return find(pos);
			}
			const_reference operator[](size_type pos) const{
				return cfind(pos);
			}
			
			//
			reference front(){
				__checkRange(0);
				return find(0);
			}
			const_reference front()const{
				__checkRange(0);
				return cfind(0);
			}
			reference back(){
				__checkRange(m_size-1);
				return find(m_size-1);
			}
			const_reference back()const{
				__checkRange(m_size-1);
				return cfind(m_size-1);
			}
			//
			bool empty(){
				return m_size == 0 ;
			}

			void clear(){
				size_type capacity = m_capacity;
				destructor();
				constructor(capacity);
			}

			size_type size(){
				return m_size;
			}
			size_type capatity(){
				return capatity;
			}
			//TAG: will be removed
			void print(){
				std::cout<< "array element:";
				for(int i = 0; i < m_size ; i++)
				{
					std::cout<< m_data[i] << "\t";
				}
				std::cout<< "\n";
			}

		private:
			//function
			void constructor(size_type capacity){
				m_size = 0;
				m_data = 0;
				m_capacity = capacity;
			}
			void destructor(){
				m_size = m_capacity = 0;
				delete [] m_data;
				m_data = 0;
			}
			
			void __resize(){
				if (m_size < m_capacity){
					return ;
				}

				m_capacity = (m_capacity == 0 ? ARRAY_DEFAULT_CAPACITY : m_capacity);
				size_type n_capacity = m_capacity + m_capacity / 2;
				iterator n_d = new value_type[n_capacity];
				for(int i = 0; i < m_size ; i++)
				{
					n_d[i] = m_data[i];
				}
				delete m_data;
				m_data = n_d;
				m_capacity = n_capacity;
			}

			void __insert(value_type value , size_type pos){
				if(pos >= m_size - 1 || pos == ARRAY_END ){
					m_data[m_size] = value;
				}else{
					value_type temp = value;
					for (int i = pos ; i < m_size -1;i++){
						temp = m_data[i];
						m_data[i] = value;
						value = temp;
					}
				}
				m_size += 1;
			}
			value_type __remove(size_type pos){
				if (m_size <= 0 ){
					return -1;
				}
				size_type n_p = (pos == ARRAY_END ? m_size - 1 : pos);
				value_type result = m_data[n_p];
				for(int i = n_p ; i < m_size -1 ; i++)
				{
					m_data[i] = m_data[i+1];
				}
				m_size -= 1;
				return result;
			}
			
			void __checkRange(size_type pos)const{
				if(pos == ARRAY_END){
					return ;
				}
				if( pos > m_size && pos < m_capacity )
				{
					//warnning.
					LOG_ERROR("the position is over m_size!!");
				}
				
				CXASSERT( pos >=0 && pos < m_capacity ,"out of the range");
			}

			array<T>& operator=(array<T>& rhs){
				return *this;
			}
			array(array<T>& rhs){

			}

			//m_data
			iterator	 m_data;
			size_type	 m_size;
			size_type	 m_capacity;

	};

}

#endif
