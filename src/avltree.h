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
			int			m_depth;
			value_type	m_data;
		};

		//function.
		avltree(){
			m_root	=	0;
			m_size	=	0;
		}
		~avltree(){

		}
			
	private:
		//node function.
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
			parent->

		}

	private:
		Node*		m_root;
		size_type	m_size;
}


#endif
