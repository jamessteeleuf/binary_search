#include "search_algorithms.h"
#include "binary_search_tree.h"
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <cstddef>
#include <sys/time.h>

using namespace std;

typedef unsigned long long timestamp_t;

static timestamp_t
get_timestamp (){
  struct timeval now;
  gettimeofday (&now, NULL);
  return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}

int main(){
	SearchAlgorithms search;
	
	int n;
	cin >> n;
	
	int s;
	cin >> s;
	
	int* test_array	=	new int[n];
	
	for(int i = 0; i < n; i++){
		cin >> test_array[i];
	}
	
	int* search_values	=	new int[s];
	
	for(int i = 0; i < s; i++){
		cin >> search_values[i];
	}
	
	printf("Linear search:\n");
	timestamp_t lin1, lin2;
	lin1	=	get_timestamp();
	for(int i = 0; i < s; i++){
		printf(search.linear_search(test_array, search_values[i], n) >= 0 ? "Yes\n" : "No\n");
	}
	lin2	=	get_timestamp();
	
	int* sorted_test_array	=	search.sort_array(test_array, n);
	printf("Binary search:\n");
	
	timestamp_t bin1, bin2;
	bin1	=	get_timestamp();
	
	BinarySearchTree* BST	=	new BinarySearchTree(sorted_test_array, n);
	for(int i = 0; i < s; i++){
		printf(search.binary_search(BST, search_values[i]) >= 0 ? "Yes\n" : "No\n");
	}
	delete BST;
	
	bin2	=	get_timestamp();
	
	//printf("Linear runtime: %llu\n", (lin2 - lin1)); // Uncomment to see the run time
	//printf("Binary runtime: %llu\n", (bin2 - bin1));
	
	delete[] test_array;
	delete[] search_values;
	return 0;
}
