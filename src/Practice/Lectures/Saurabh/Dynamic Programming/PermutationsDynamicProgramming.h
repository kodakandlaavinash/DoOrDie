/*
 * PermutationsDynamicProgramming.h
 *
 *  Created on: Aug 23, 2013
 *      Author: Avinash
 */
//
// Testing Status
//
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <hash_map>
#include <stack>
#include <queue>
#include <limits.h>

using namespace std;
using namespace __gnu_cxx;

#define null NULL
#define PRINT_NEW_LINE printf("\n")
//int main(){
//	return -1;
//}

#ifndef PERMUTATIONSDYNAMICPROGRAMMING_H_
#define PERMUTATIONSDYNAMICPROGRAMMING_H_

void PrintAllPermutations(int userInput[],int startIndex,int endIndex){
	if(index > endIndex){
		return;
	}
	if(index == endIndex){
		for(int counter =startIndex;counter < endIndex;counter++){
			printf("%d\t",userInput[counter]);
		}
		printf("\n");
		return;
	}
	int tempForSwap;
	for(int counter =startIndex;counter <= endIndex;counter++){
		tempForSwap = userInput[counter];
		userInput[counter] = userInput[startIndex];
		userInput[startIndex] = tempForSwap;
		PrintAllPermutations(userInput,startIndex+1,endIndex);
		tempForSwap = userInput[counter];
		userInput[counter] = userInput[startIndex];
		userInput[startIndex] = tempForSwap;
	}
}

void GenerateAllPermutations(int userInput[],int startIndex,int endIndex,list<list<int>> &allPermutation){
	if(userInput > endIndex){
		return NULL;
	}
	if(userInput == endIndex){
		list<int> permutation;
		for(int counter = startIndex;counter < endIndex;counter++){
			permutation.push_back(userInput[counter]);
		}
		allPermutation.push_back(permutation);
	}
	for(int counter = startIndex;counter <= endIndex;counter){
		tempForSwap = userInput[counter];
		userInput[counter] = userInput[startIndex];
		userInput[startIndex] = tempForSwap;
		PrintAllPermutations(userInput,startIndex+1,endIndex);
		tempForSwap = userInput[counter];
		userInput[counter] = userInput[startIndex];
		userInput[startIndex] = tempForSwap;
	}
}


#endif /* PERMUTATIONSDYNAMICPROGRAMMING_H_ */
