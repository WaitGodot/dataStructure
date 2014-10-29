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
			typedef std::ptrdiff_c	difference_type;
			
			
			static const size_type ARRAY_END				 = 4294967295;
			static const size_type ARRAY_DEFAULT_CAPACITY	 = 2;

			array();
			array(size_type capacity);

			void			 insert	(value_type value,size_type pos = ARRAY_END);
			const_reference	 cfind	(size_type pos) const;
			reference		 find	(size_type pos);
			//size_type		 find	(const_reference value);
			value_type		 remove	(size_type pos);
			
			reference operator[](size_type pos);
			const_reference operatorp[] (size_type pos) const;
			
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
				__checkRange(size-1);
				return find(size-1);
			}
			const_reference back()const{
				__checkRange(size-1);
				return cfind(size-1);
			}
			//
			bool empty(){
				return size
			}
			size_type size(){
				return size;
			}
			size_type capatity(){
				return capatity;
			}
			//

		private:
			//function
			void constructor(size_type capacity){
				size = 0;
				data = 0;
				capacity = capacity;
			}
			void destructor(){
				size = capacity = 0;
				delete [] data;
				data = 0;
			}
			
			void reAlloc(){
				if (size < capacity){
					return ;
				}

				capacity = capacity == 0 ? ARRAY_DEFAULT_CAPATITY : capacity;
				size_type n_capatity = capacity + capacity * 0.5;
				iterator n_d = new value_type[n_capatity];
				for(int i = 0; i < size ; i++)
				{
					n_d[i] = data[i];
				}
				delete data;
				data = n_d;
				capatity = n_capatity
			}

			void __insert(value_type value , size_type pos){
				if(pos >= size - 1){
					data[size] = value;
				}else{
					value_type temp = value;
					for (int i = pos ; i < size -1){
						temp = data[i];
						data[i] = value;
						value = temp;
					}
				}
				size += 1;

			}

			void __remove(size_type pos){
				value_type result = data[pos];
				for(int i = pos ; i < size -1 ; i++)
				{
					data[i] = data[i+1];
				}
				size -= 1;
				return result;
			}
			
			void __checkRange(size_type pos){
				if( pos > size && pos < capacity )
				{
					//warnning.
				}else if( pos >= capacity){
					//error.
				}
			}
			array<T>& operator=(array<T>& rhs){
				return *this
			}
			array(array<T>& rhs){

			}

			//data
			iterator	 data;
			size_type	 size;
			size_type	 capacity;

	}

	template<typename T>
	array<T>::array(){
		constructor(0);
	}

	template<typename T>
	array<T>::array(size_type capacity){
		constructor(capacity);
	}

	template<typename T>
	void  array<T>::insert(value_type value,size_type pos){
		reAlloc();
		_insert(value,pos);
	}
	
	template<typename T>
	const_reference  array<T>::cfind(size_type pos) const{
		__checkRange(pos);
		return data[pos];
	}

	template<typename T>
	reference  array<T>::find(size_type pos){
		__chekcRange(pos);
		return data[pos];
	}

	template<typename T>
	value_type  array<T>::remove(size_type pos){
		__checkRange(pos);
		return __remove(pos);
	}

	template<typename T>
	reference array<T>::operator[](size_type pos){
		return find(pos);
	}

	template<typename T>
	const_reference array<T>::operator[](size_type pos){
		return cfind(pos);
	}

	}

}

#endif
