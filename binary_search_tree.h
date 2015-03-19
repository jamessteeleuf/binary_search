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

	binary_search_tree_node* sorted_array_to_BST(int sorted_array[], int start, int end){
		if(start > end){
			return NULL;
		}

		int midpoint					=	start + (end - start)/2;
		binary_search_tree_node* node	=	new binary_search_tree_node();
		node->value						=	sorted_array[midpoint];
		node->index						=	midpoint;
		node->left						=	this->sorted_array_to_BST(sorted_array, start, mid-1);
		node->right						=	this->sorted_array_to_BST(sorted_array, mid+1, end);
		return node;
	}

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
public:
	BinarySearchTree(int sorted_array[], int n){
		this->root	=	this->sorted_array_to_BST(sorted_array, 0, n -1);
	}

	~BinarySearchTree(){
		this->clear(this->root);
	}

	int search(int needle){
		binary_search_tree_node* active_node;

		active_node	=	this->root;

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
		
		// Return the position of the node if it is found
		return active_node->index;
	}
};
