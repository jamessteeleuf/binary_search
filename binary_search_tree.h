#include <cstddef>

struct binary_search_tree_node{
	binary_search_tree_node *left;
	binary_search_tree_node *right;
	int value;
	int index;
};

class BinarySearchTree{
	private:
		binary_search_tree_node* root;
		void clear(binary_search_tree_node* node){
			// Make sure we have something to work with
			if(node == NULL){
				return;
			}
			
			// Clear the left side
			if(node->left != NULL){
				this->clear(node->left);
			}
			
			// And clear the right side, of course
			if(node->right != NULL){
				this->clear(node->right);
			}
			
			// Destroy the node
			delete node;
		}
		
		binary_search_tree_node* copy_node(binary_search_tree_node* node){
			// This is a security thing. If we return a pointer to our inner tree, users can access the whole thing, so we need to return a copy of it instead
			
			binary_search_tree_node* copied_node;
			copied_node		=	new binary_search_tree_node();
			*copied_node	=	*node; // Copy
			
			// We're only interested in the value of the node, so we can destroy its children
			copied_node->left			=	NULL;
			copied_node->right			=	NULL;
			return copied_node;
		}
	public:
		BinarySearchTree(){
			this->root	=	NULL;
		}
		
		~BinarySearchTree(){
			this->clear(this->root);
		}
		
		bool empty(){
			// Our tree is empty if the root is null
			return this->root == NULL;
		}
		
		binary_search_tree_node* search(int needle){
			binary_search_tree_node* active_node;
			
			active_node 	=	this->root;
			
			while(active_node != NULL && active_node->value != needle){
				// If our needle is less than our value, then it's located on the left side, otherwise it's on the right side
				if(needle < active_node->value){
					active_node	=	active_node->left;
				}else{
					active_node =	active_node->right;
				}
			}
			
			// If our active node is null after all this, it means that the needle is not in the haystack :(
			if(active_node == NULL){
				return active_node;
			}
			
			// Return a copy of the node if it is found
			return this->copy_node(active_node);
		}
		
		void insert(binary_search_tree_node* node){
			binary_search_tree_node* placeholder_node;
			binary_search_tree_node* active_node;
			
			placeholder_node 	=	this->root;
			active_node 		=	NULL;
			
			// Find where our new node belongs
			while(placeholder_node != NULL){
				active_node	=	placeholder_node;
				if(node->value < placeholder_node->value){
					placeholder_node 	=	placeholder_node->left;
				}else{
					placeholder_node 	=	placeholder_node->right;
				}
			}
			
			// Attach the new node to the correct side of our active node
			if(active_node == NULL){
				root	=	node;
			}else{
				if(node->value < active_node->value){
					active_node->left	=	node;
				}else{
					active_node->right	=	node;
				}
			}
		}
		
		void insert(int value, int index){
			binary_search_tree_node* node	=	new binary_search_tree_node();
			node->value	=	value;
			node->index	=	index;
			node->left	=	NULL;
			node->right	=	NULL;
			this->insert(node);
		}
};
