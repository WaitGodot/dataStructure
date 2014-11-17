#ifndef __BS_TREE_H__
#define __BS_TREE_H__


#include <cstddef>

template<typedef T>
class bstree
{
	public:
		typedef T			value_type;
		typedef	T&			reference;
		typedef	const T&	const_reference;
		typedef	size_t		size_type;
			
		struct bsNode
		{
			value_type		m_data;
			struct bsNode*	m_leftChild;
			struct bsNode*	m_rightChild;
		};
		typedef struct bsNode bsNode;

		bstree(){
			m_root = 0;
			m_size = 0;
		}
		~bstree(){
			__destructor_node(m_root);
		}

		bool insert(const_reference value){
			bool rt = contain(value);
			if (!rt){
				return rt
			}
			bsNode*	node = new	bsNode();
			node->m_data = value;
			node->m_leftChild = node->m_rightChild = 0;
			if (!m_root){
				m_root = node;
				return ;
			}
			__insert_node(m_root,node);
			m_size += 1;
			return rt;
		}

		bool remove(const_reference value){
			bsNode* node = __contain_node(m_root,value);
			bool rt = node == 0 ? false : true;
			if(rt == false){
				return rt;
			}
			__remove_node( node );
			return rt;
		}

		bool contain(const_reference value){
			return __contain_value(m_root,value) == 0 ? false : true;
		}

		value_type maxValue(){
			bsNode* rt = m_root;
			while(rt->rightChild){
				rt = rt->rightChild;
			}
			return rt->m_data;
		}
		value_type minValue(){
			bsNode* rt = m_root;
			while(rt->leftChild){
				rt = rt->leftChild;
			}
			return rt->m_data;
		}
		size_type size(){
			return m_size;
		}
	private:
		//function.
		void __destructor_node(bsNode* node){
			if (!node){
				return ;
			}
			__destructor_node( node-> m_leftChild);
			__desturctor_node( node-> m_rightChild);
			delete node;
			node = 0;
		}
		void __insert_node(bsNode* parent, bsNode* node){
			if( node->m_data >= parent->m_data ){
				if(parent->rightChild){
					__insert_node(parent->rightChild,node);
				}else{
					parent->rightChild = node;
				}
			}else{
				if(parent->leftChild){
					__insert_node(parent->leftChild,node);
				}else{
					parent->leftChild = node;
				}
			}
		}
		void __remove_node(bsNode* node){
			if(!node->rigthNode && !node->leftNode){

			}
		}
		bsNode* __contain_value(bsNode* node , const_reference value){
			if(!node){
				return 0;
			}
			if(node->m_data == value){
				return node;
			}else if( value > node->m_data){
				return __contain_value( node->rightChild , value);
			}else if(value < node->m_data){
				return __contain_value( node->leftChild , value);
			}
		}

		bsNode*	m_root;
		size_type m_size;
};




#endif	
