/*
 * SegregateEvenAndOddNumbers.h
 *
 *  Created on: Jun 20, 2013
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

#ifndef SEGREGATEEVENANDODDNUMBERS_H_
#define SEGREGATEEVENANDODDNUMBERS_H_

int *SegregateEvenAndOddNumbersON2(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return null;
	}
	int innerCounter,tempForSwap;
	bool elementFound = false;
	for(int counter =0;counter < sizeOfArray;counter++){
		if(userInput[counter]%2 != 0){
			elementFound = false;
			for(innerCounter = counter+1;counter < sizeOfArray;innerCounter++){
				if(userInput[innerCounter]%2 == 0){
					elementFound = true;
					break;
				}
			}
			if(!elementFound){
				break;
			}
			tempForSwap = userInput[innerCounter];
			userInput[innerCounter] = userInput[counter];
			userInput[counter] = tempForSwap;
		}
	}
	return userInput;
}

int *SegregateEvenAndOddNumberONBuckets(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return null;
	}

	queue<int> buckets[2];
	for(int counter = 0;counter < sizeOfArray;counter++){
		if(userInput % 2 == 1){
			buckets[1].push(userInput[counter]);
		}else{
			buckets[0].push(userInput[counter]);
		}
	}

	int fillCounter =-1;
	while(!buckets[0].empty()){
		userInput[++fillCounter] = buckets[0].front();
		buckets[0].pop();
	}

	while(!buckets[1].empty()){
		userInput[++fillCounter] = buckets[1].front();
		buckets[1].pop();
	}
	return userInput;
}

int *SegregateEvenAndOddNumbers(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
	int startCrawler = 0,endCrawler = sizeOfArray-1;
	while(startCrawler < endCrawler){
		while(userInput[startCrawler] % 2 == 1){
			startCrawler++;
		}

		if(startCrawler < endCrawler){
			while(userInput[endCrawler]%2 == 0){
				endCrawler--;
			}
		}else{
			break;
		}

		if(startCrawler < endCrawler){
			int tempForSwap;
			tempForSwap = userInput[startCrawler];
			userInput[startCrawler] = userInput[endCrawler];
			userInput[endCrawler] = tempForSwap;
		}
	}
}

#endif /* SEGREGATEEVENANDODDNUMBERS_H_ */
