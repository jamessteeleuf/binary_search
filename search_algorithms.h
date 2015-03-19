#ifndef SEARCH_ALGORITHMS_H
#define SEARCH_ALGORITHMS_H

#include <algorithm>
#include "binary_search_tree.h"

class SearchAlgorithms{
	public:
		int* sort_array(int[], int);
		int linear_search(int[], int, int);
		int binary_search(BinarySearchTree*, int);	
};

#endif
