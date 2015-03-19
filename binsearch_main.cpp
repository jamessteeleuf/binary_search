#include "search_algorithms.h"
#include <stdio.h>
#include <iostream>

using namespace std;

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
	
	for(int i = 0; i < s; i++){
		printf("Linear search for %i, found at %i\n", search_values[i], search.linear_search(test_array, search_values[i], n));
		printf("Binary search for %i, found at %i\n", search_values[i], search.binary_search(test_array, search_values[i], n));
	}
	
	delete[] test_array;
	delete[] search_values;
	printf("n: %i, s: %i\n", n, s);
	return 0;
}
