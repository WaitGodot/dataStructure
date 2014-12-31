#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__



template<typename T>
class avltree
{
	public:
		typedef T			value_type;
		typedef	T&			reference;
		typedef	const T&	const_reference;
		typedef	size_t		size_type;

		typedef struct Node{
			Node*		m_parent;
			Node*		m_leftChild;
			Node*		m_rightChild;
			int			m_height;
			::int			m_depth;
			value_type	m_data;
		};

		static const int INSERT_NONE	=	0;		
		static const int INSERT_LEFT	=	1;
		static const int INSERT_RIGHT	=	2;

		//function.
		avltree(){
			m_root	=	0;
			m_size	=	0;
		}
		~avltree(){
			__destructor_node(m_root);
			m_size = 0;
		}

		void insert(const_reference value){
			if ( cantain(value) ){
				return ;
			}
			Node* node = _node_create(value);
			if( !m_root){
				m_root = node;
				return ;
			}
			__rotate( __insert_node(m_root,node) ,node );
			
			m_size ++ ;
		}

		bool cantain(const_reference value){
			return __cantain_value(m_root,value) == 0 ? false : true;
		}
			
	private:
		//node function.
		void __destructor_node(Node* node){
			if (node == 0){
				return ;
			}
			__destructor_node(node->m_leftChild);
			__destructor_node(node->m_rightChild);
			node->m_depth = node->m_height = 0;
			delete node; node = 0;
		}
		
		int __insert_node(Node* parent,Node* node){
			if(node->m_data > parent->m_data){
				if(parent->m_rightChild){
					__insert_node(parent->m_rightChild);
				}else{
					parent->m_rightChild = node;
					return INSERT_RIGHT;
				}
			}else{
				if(parent->m_leftChild){
					__insert_node(parent->m_leftChild);
				}else{
					parent->m_leftChild = node;
					return INSERT_LEFT;
				}
			}
			return INSERT_NONE;
		}
		
		void __rotate(int type,Node* node){
			if ( type == INSERT_LEFT ) {
				__rotate_left(node);
			}else if( type == INSERT_RIGHT){
				__rotate_right(node);
			}
		}

		void __rotate_left(Node* node){
			if( !node ){
				return ;
			}
			Node* parent = node->m_parent == 0 ? m_root : node->m_parent;
			parent->m_leftChild = node->m_leftChild;
			node->m_leftChild->m_parent = parent;
			node->m_leftChild->m_rightChild = node;
			node->m_parent= node->m_leftChild;
			node->m_leftChild = 0;
		}

		void __rotate_right(Node* node){
			if( !node ){
				return ;
			}
			Node* parent = node->m_parent;
			if ( parent ){
				parent->m_rightChild
			}

			parent->m_rightChild = node->m_rightChild;

			node->m_rightChild->m_parent = parent;
			node->m_rightChild->m_leftChild = node;
			node->m_parent = node->m_rightChild;
			node->m_rightChild = node->m_rightChild->m_leftChild;
		}

		Node* __cantain_value(Node* node,const_reference value){
			if(node == 0 ){
				return 0;
			}
			if(node->m_data == value){
				return node;
			}else if(node->m_data > value){
				return __cantain_value(node->m_leftChild,value);
			}else if(node->m_data < value){
				return __cantain_value(node->m_rightChild,value);
			}
		}

		Node* _node_create(const_reference value){
			Node* n = new Node();
			m_parent = m_leftChild = m_rightChild = 0;
			m_height = m_depth = 0;
			m_data = value;
		}
		void _node_addLeft(Node* parent,Node* leftChild){
			if(parent == 0 || leftChild == 0 ){
				return ;
			}
			parent->m_leftChild = leftChild;
			leftChild->m_parent = parent;
		}
		void _node_addRight(node* parent,Node* rightChild){
			if(parent == 0 || leftChild == 0 ){
				return ;
			}
			parent->m_leftChild = leftChild;
			leftChild->m_parent = parent;
		}

	private:
		Node*		m_root;
		size_type	m_size;
}


#endif
