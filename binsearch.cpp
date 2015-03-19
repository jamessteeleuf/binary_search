#include "search_algorithms.h"
#include "binary_search_tree.h"
#include <stdio.h>
using namespace std;

int SearchAlgorithms::linear_search(int haystack[], int needle, int size){
	// Pretty straightforward: check all of our elements until we find our needle. We'll return the position of the needle if it's found and -1 if it isn't. Ideally, we'd throw an error if it isn't found, as it would maintain the "1 function per function" rule, but then the user would have to either a) check if the needle is in the haystack before hand or b) catch the error, neither of which is efficient and efficiency is a priority.
	
	for(int i = 0; i < size; i++){
		if(haystack[i] == needle){
			return i;
		}
	}
	return -1;
}

int* SearchAlgorithms::sort_array(int sortable[], int size){
	// <algorithm> has a really clumsy sorting method. Even though we're only using it once, I feel more comfortable abstracting it out, so that the fumbling around with array element pointers doesn't get in the way of our searching algorithms.
	
	// The sort function modifies an existing array, so this function accepts an array by value to prevent side effects. Yeah, it uses *a lot* more memory, but I don't want a 1m+ element array to randomly become sorted. That'd be a pretty tough bug to track down.
	
	sort(sortable, sortable + size); // The magic
	return sortable;
}

int SearchAlgorithms::binary_search(int haystack[], int needle, int size){
	// Gotta go fast, gotta go fast,
	// Gotta go faster, faster, faster, faster, faster
	
	BinarySearchTree binary_search_tree; // It wouldn't be a binary search without one of these guys
	
	// Fill our tree. We could require our haystack to be a binary search tree, which would be faster when the same input is used multiple times, but that isn't in the specification
	for(int i = 0; i < size; i++){
		binary_search_tree.insert(haystack[i], i);
	}
	
	binary_search_tree_node* result	=	binary_search_tree.search(needle);
	if(result == NULL){
		return -1;
	}
	return result->index;
}
