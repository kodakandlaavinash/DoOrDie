/*
 * MaximumRepeatingElement.h
 *
 *  Created on: Aug 22, 2013
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

#ifndef MAXIMUMREPEATINGELEMENT_H_
#define MAXIMUMREPEATINGELEMENT_H_

int MaximumRepeatingElement(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
	int outerCounter = 0,innerCounter = 0;
	int maxRepeatingElement = INT_MIN,frequencyElement;
	for(outerCounter = 0;outerCounter < sizeOfArray;outerCounter++){
		frequencyElement = 0;
		for(innerCounter = 0;innerCounter < sizeOfArray;innerCounter++){
			if(userInput[outerCounter] == userInput[innerCounter]){
				frequencyElement++;
			}
		}
		if(maxRepeatingElement < frequencyElement){
			maxRepeatingElement = frequencyElement;
		}
	}
	return maxRepeatingElement;
}

int MaximumRepeatingElement(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
	int *auxSpace = (int *)calloc(sizeOfArray,sizeof(int));
	for(int counter = 0;counter < sizeOfArray;counter++){
		auxSpace[userInput[counter]] += 1;
	}
	int maxElement,maxFrequency;
	for(int counter = 0;counter < sizeOfArray;counter++){
		if(maxFrequency < auxSpace[counter]){
			maxFrequency = auxSpace[counter];
			maxElement = counter;
		}
	}
	return maxElement;
}

int MaximumRepeatingElement(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
	for(int counter = 0;counter < sizeOfArray;counter++){
		userInput[userInput[counter]%sizeOfArray] += sizeOfArray;
	}

	int maxElementFrequency = INT_MIN,maxElementIndex;
	for(int counter = 0;counter < sizeOfArray;counter++){
		if(maxElementFrequency < userInput[counter]){
			maxElementFrequency = userInput[counter];
			maxElementIndex = counter;
		}
	}
	return  maxElementIndex;
}

int MaximumRepeatingElementSorting(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
	sort(userInput,userInput+sizeOfArray);
	int maxElement,maxElementFrequency = INT_MIN,frequencyElement;
	for(int counter = 0;counter < sizeOfArray;){
		frequencyElement = 1;
		while(userInput[counter] == userInput[counter+1]){
			counter++;
			frequencyElement++;
		}
		if(maxElementFrequency <frequencyElement){
			maxElement = userInput[counter];
			maxElementFrequency = frequencyElement;
		}
		counter++;
	}
	return maxElement;
}

#endif /* MAXIMUMREPEATINGELEMENT_H_ */
