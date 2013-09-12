/*
 *  SORTING.h
 *	http://www.codechef.com/problems/SORTING
 *  Created on: Sep 9, 2013
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

#ifndef SORTING_H_
#define SORTING_H_

/**
 * Tested
 */
int ComparisonCount(vector<int> userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return 0;
	}
	if(userInput.size() == 2){
		return 2;
	}
	unsigned int middleIndex;
	if(userInput.size()%2 == 1){
		middleIndex = userInput.size()/2;
	}else{
		middleIndex = (userInput.size()/2) -1;
	}
	vector<int> greaterElements,smallerElements;
	int comparisonCounter = 0;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		comparisonCounter++;
		if(userInput[counter] > userInput[middleIndex]){
			greaterElements.push_back(userInput[counter]);
		}
		if(userInput[counter] < userInput[middleIndex]){
			smallerElements.push_back(userInput[counter]);
		}
	}
	return comparisonCounter + ComparisonCount(greaterElements) + ComparisonCount(smallerElements);
}


int main(){
	int numberOfInputs,userInputTemp;
	scanf("%d",&numberOfInputs);
	vector<int> userInput;
	while(numberOfInputs){
		scanf("%d",&userInputTemp);
		userInput.push_back(userInput);
	}
	printf("%d",ComparisonCount(userInput));
}
#endif /* SORTING_H_ */
