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
	
	printf("Linear search:\n");
	for(int i = 0; i < s; i++){
		printf(search.linear_search(test_array, search_values[i], n) >= 0 ? "Yes\n" : "No\n");
	}
	
	printf("Binary search:\n");
	for(int i = 0; i < s; i++){
		printf(search.binary_search(test_array, search_values[i], n) >= 0 ? "Yes\n" : "No\n");
	}
	
	delete[] test_array;
	delete[] search_values;
	return 0;
}
