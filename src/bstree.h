#ifndef __BS_TREE_H__
#define __BS_TREE_H__


#include <cstddef>

template<typename T>
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
			if (rt){
				return rt;
			}
			rt = true;
			bsNode*	node = new	bsNode();
			node->m_data = value;
			node->m_leftChild = node->m_rightChild = 0;
			if (!m_root){
				m_root = node;
				return rt;
			}
			__insert_node(m_root,node);
			m_size += 1;
			return rt;
		}

		bool remove(const_reference value){
			bsNode* node = __contain_value(m_root,value);
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
			return __max_node(m_root)->m_data;
		}
		value_type minValue(){
			return __min_node(m_root)->m_data;
		}
		size_type size(){
			return m_size;
		}
		//TAG: will be remove
		void print_preorder(){
			__print_preorder(m_root,0);
		}
		void print_postorder(){
			__print_postorder(m_root,0);
		}
		void print_inorder(){
			__print_inorder(m_root,0);
		}
	private:
		//function.
		void __destructor_node(bsNode* node){
			if (!node){
				return ;
			}
			__destructor_node( node-> m_leftChild);
			__destructor_node( node-> m_rightChild);
			delete node;
			node = 0;
		}
		void __insert_node(bsNode* parent, bsNode* node){
			if( node->m_data >= parent->m_data ){
				if(parent->m_rightChild){
					__insert_node(parent->m_rightChild,node);
				}else{
					parent->m_rightChild = node;
				}
			}else{
				if(parent->m_leftChild){
					__insert_node(parent->m_leftChild,node);
				}else{
					parent->m_leftChild = node;
				}
			}
		}
		void __remove_node(bsNode* &node){
			if(!node->m_rightChild && !node->m_leftChild){
				bsNode* dNode = __min_node(node->m_rightChild);
				node->m_data = dNode->m_data;
				__remove_node(dNode);
			}else{
				bsNode* temp = node;
				node = (node->m_leftChild ? node->m_leftChild : node->m_rightChild);
				delete temp;temp = 0;
			}
		}
		bsNode* __contain_value(bsNode* node , const_reference value){
			if(!node){
				return 0;
			}
			if(node->m_data == value){
				return node;
			}else if( value > node->m_data){
				return __contain_value( node->m_rightChild , value);
			}else if(value < node->m_data){
				return __contain_value( node->m_leftChild , value);
			}
		}
		
		bsNode* __max_node(bsNode* root){
			return root->m_rightChild ? __max_node(root->m_rightChild) : root;
		}
		bsNode* __min_node(bsNode* root){
			return root->m_leftChild ? __min_node(root->m_leftChild) : root;
		}
		
		//TAG: will be remove.
		void __print_preorder(bsNode* node, int depth){
			if (!node){
				return ;
			}
			for(int i = 0 ; i < depth ; i++){
				std::cout<<"\t";
			}
			std::cout<<node->m_data << "\n";
			__print_preorder(node->m_leftChild,depth+1);
			__print_preorder(node->m_rightChild,depth+1);
		}
		void __print_postorder(bsNode* node,int depth){
			if(!node){
				return ;
			}
			__print_postorder(node->m_leftChild, depth + 1);
			__print_postorder(node->m_rightChild,depth + 1);
			for(int i = 0 ; i < depth ; i++){
				std::cout << "\t";
			}
			std::cout << node->m_data << "\n";
		}
		void __print_inorder(bsNode* node,int depth){
			if(!node){
				return ;
			}
			__print_inorder(node->m_leftChild,depth + 1);
			for(int i = 0 ; i < depth ; i++){
				std::cout << "\t";
			}
			std::cout << node->m_data << "\n";
			__print_inorder(node->m_rightChild,depth + 1);
		}

		bsNode*	m_root;
		size_type m_size;
};




#endif	
