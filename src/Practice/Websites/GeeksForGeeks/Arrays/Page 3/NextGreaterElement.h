/*
 * NextGreaterElement.h
 *
 *  Created on: Aug 2, 2013
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

#ifndef NEXTGREATERELEMENT_H_
#define NEXTGREATERELEMENT_H_

void PrintNextGreaterElementON2(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return;
	}
	int outerCounter,innerCounter;
	bool nextGreaterFound;
	for(outerCounter = 0;outerCounter < sizeOfArray;outerCounter++){
		nextGreaterFound = false;
		for(innerCounter = outerCounter+1;innerCounter < sizeOfArray;innerCounter++){
			if(userInput[outerCounter] < userInput[innerCounter]){
				printf("%d -> %d",outerCounter[userInput],innerCounter[userInput]);
				nextGreaterFound = true;
				break;
			}
		}
		if(!nextGreaterFound){
			printf("%d -> -1",outerCounter[userInput]);
		}
	}
}

void PrintNextGreaterElementON(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return;
	}
	stack<int> auxSpace;
	auxSpace.push(userInput[0]);
	int topElement;
	for(int counter = 1;counter < sizeOfArray;counter++){
		while((!auxSpace.empty())&&(topElement = auxSpace.top())>userInput[counter]){
			printf("%d->%d",topElement,userInput[counter]);
			auxSpace.pop();
		}
		auxSpace.push(userInput[counter]);
	}

	while(!auxSpace.empty()){
		printf("%d->-1",auxSpace.top());
		auxSpace.pop();
	}
}
#endif /* NEXTGREATERELEMENT_H_ */
