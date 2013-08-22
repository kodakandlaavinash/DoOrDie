/*
 * RearrangePositiveAndNegativeNumbers.h
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

#ifndef REARRANGEPOSITIVEANDNEGATIVENUMBERS_H_
#define REARRANGEPOSITIVEANDNEGATIVENUMBERS_H_

void RearrangePositiveAndNegativeNumbersON2(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return;
	}
	int outerCounter,innerCounter,tempForSwap;
	bool searchForPositive = false,elementFound = true;

	for(outerCounter = 0;outerCounter < sizeOfArray;){
		elementFound = false;
		for(innerCounter = outerCounter+1;innerCounter < sizeOfArray;innerCounter++){
			if(searchForPositive){
				if(userInput[innerCounter] > 0){
					elementFound = true;
				}
			}else{
				if(userInput[innerCounter] <= 0){
					elementFound = true;
				}
			}
		}
		if(!elementFound){
			break;
		}
		tempForSwap = userInput[innerCounter];
		userInput[innerCounter] = userInput[outerCounter];
		userInput[outerCounter] = tempForSwap;
		outerCounter += innerCounter+1;
	}
}

void RearrangePositiveAndNegativeNumbersAuxSpace(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return;
	}
	queue<int> auxSpacePositiveNumbers,auxSpaceNegativeNumbers;
	for(int counter = 0;counter < sizeOfArray;counter++){
		if(userInput[counter] < 0){
			auxSpaceNegativeNumbers.push(userInput[counter]);
		}else{
			auxSpacePositiveNumbers.push(userInput[counter]);
		}
	}
	int fillCounter = -1;
	bool shouldFlip = false;
	while(!auxSpaceNegativeNumbers.empty() && !auxSpacePositiveNumbers.empty()){
		if(shouldFlip){
			userInput[++fillCounter] = auxSpaceNegativeNumbers.front();
			auxSpaceNegativeNumbers.pop();
		}else{
			userInput[++fillCounter] = auxSpacePositiveNumbers.front();
			auxSpacePositiveNumbers.pop();
		}
		shouldFlip = !shouldFlip;
	}
	while(auxSpaceNegativeNumbers.empty()){
		userInput[++fillCounter] = auxSpaceNegativeNumbers.front();
		auxSpaceNegativeNumbers.pop();
	}
	while(auxSpacePositiveNumbers.empty()){
		userInput[++fillCounter] = auxSpacePositiveNumbers.front();
		auxSpacePositiveNumbers.pop();
	}
	return;
}

void RearrangePositiveAndNegativeNumbersON(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return;
	}
	int startCrawler = 0,endCrawler = sizeOfArray-1,tempForSwap;
	bool searchForPositive = false;
	while(startCrawler < endCrawler){
		if(searchForPositive){
			while(userInput[startCrawler] > 0){
				startCrawler++;
			}
			while(userInput[endCrawler] < 0 && startCrawler < endCrawler){
				endCrawler--;
			}
		}else{
			while(userInput[startCrawler] < 0){
				startCrawler++;
			}
			while(userInput[endCrawler] < 0 && startCrawler < endCrawler){
				endCrawler--;
			}
		}
		if(startCrawler < endCrawler){
			tempForSwap = userInput[startCrawler];
			userInput[startCrawler] = userInput[endCrawler];
			userInput[endCrawler] = tempForSwap;
		}else{
			break;
		}
	}
}

#endif /* REARRANGEPOSITIVEANDNEGATIVENUMBERS_H_ */
