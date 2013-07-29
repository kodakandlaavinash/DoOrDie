/*
 * FindTwoRepeatingElements.h
 *
 *  Created on: May 16, 2013
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

#ifndef FINDTWOREPEATINGELEMENTS_H_
#define FINDTWOREPEATINGELEMENTS_H_

int *FindTwoRepeatingElementsInRange(int userInput[],int sizeOfArray,int startRange){
	if(sizeOfArray == 0){
		return NULL;
	}
	int crawler =0;
	long int sumOfRange = 0;
	long int productOfRange = 1;
	for(crawler = startRange;crawler < startRange+sizeOfArray-2;crawler++){
		sumOfRange += crawler;
		productOfRange *= crawler;
	}

	long int sumOfUserInput = 0;
	long int productOfUserInput = 1;
	for(crawler = 0;crawler < sizeOfArray;crawler++){
		sumOfUserInput += userInput[crawler];
		productOfUserInput *= userInput[crawler];
	}
}

int *FindTwoRepeatingElementsON2(int userInput[],int sizeOfArray,int startRange){
	if(sizeOfArray == 0){
		return NULL;
	}
	int outerCrawler = startRange;
	int innerCrawler;
	int crawler = -1;
	int twoRepeatingElements[2];
	for(outerCrawler = startRange;outerCrawler < sizeOfArray-1;outerCrawler){
		for(innerCrawler = outerCrawler+1;;innerCrawler++){
			if(userInput[outerCrawler] == userInput[innerCrawler]){
				if(crawler == 0){
					if(userInput[outerCrawler] == userInput[crawler]){
						continue;
					}else{
						userInput[++crawler] = userInput[outerCrawler];
					}
				}
				userInput[++crawler] = userInput[outerCrawler];
			}
		}
	}
}

int * FindTwoRepeatingElementsUsingArrayIndex(int userInput[],int sizeOfArray,int startRange){
	if(sizeOfArray == 0){
		return NULL;
	}
	int twoRepeatingElements[2];
	int counter=-1;
	for(int crawler = 0;crawler < sizeOfArray;crawler++){
		if(userInput[userInput[crawler] - startRange] < 0){
			twoRepeatingElements[++counter] = userInput[crawler];
			if(counter == 1){
				return twoRepeatingElements;
			}
		}
		userInput[userInput[crawler] - startRange] *= -1;
	}
	return NULL;
}

int *FindTwoRepeatingElementsUsingHashMap(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return NULL;
	}

	hash_map<int,int> auxSpace;
	hash_map<int,int>::iterator itToAuxSpace;
	for(int crawler =0;crawler < sizeOfArray;crawler++){
		if((itToAuxSpace = auxSpace.find(userInput[crawler])) == auxSpace.end()){
			auxSpace.insert(pair<int,int>(userInput[crawler],(itToAuxSpace->second)++));
		}else{
			auxSpace.insert(pair<int,int>(userInput[crawler],1));
		}
	}

	int twoRepeatingElements[2];
	int counter = -1;
	for(itToAuxSpace = auxSpace.begin();itToAuxSpace != auxSpace.end();itToAuxSpace++){
		if(itToAuxSpace->second > 1){
			twoRepeatingElements[++counter] = userInput[crawler];
			if(counter == 1){
				return twoRepeatingElements;
			}
		}
	}
	return NULL;
}

int *FindTwoRepeatingElementsUsingXOR(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return NULL;
	}

	int XORResult= 0;
	for(int crawler = 0;crawler < sizeOfArray;crawler++){
		XORResult ^= userInput[crawler];
	}

	int setBitPosition = 0;
	bitset<16> temp(XORResult);
	for(int bitCounter = 0;bitCounter < 16;bitCounter++){
		if(temp[bitCounter] == true){
			bitPosition = bitCounter;
			break;
		}
	}

	vector<bitset<16>> bitRepresentationOfUserInput;
	for(int counter =0;counter < sizeOfArray;counter++){
		bitset<16> temp(userInput[counter]);
		bitRepresentationOfUserInput.push_back(temp);
	}

	int frontCrawler = 0,backCrawler = sizeOfArray - 1;
	while(1){
		while(bitRepresentationOfUserInput[frontCrawler][setBitPosition] == true){
			frontCrawler++;
		}

		if(frontCrawler < backCrawler){
			while(bitRepresentationOfUserInput[backCrawler][setBitPosition] == false){
				backCrawler--;
			}
		}

		if(frontCrawler<backCrawler){
			temp = bitRepresentationOfUserInput[frontCrawler];
			bitRepresentationOfUserInput[frontCrawler] = bitRepresentationOfUserInput[backCrawler];
			bitRepresentationOfUserInput[backCrawler] = temp;
		}
	}

	int twoRepeatingElements[2];
	XORResult =0;
	for(int counter =0;counter <= backCrawler;counter++){
		XORResult ^= (int)bitRepresentationOfUserInput[counter].to_ulong();
	}
	twoRepeatingElements[0] = XORResult;
	XORResult =0;
	for(int counter =backCrawler+1;counter < sizeOfArray;counter++){
		XORResult ^= (int)bitRepresentationOfUserInput[counter].to_ulong();
	}
	twoRepeatingElements[1] = XORResult;
	return twoRepeatingElements;
}

#endif /* FINDTWOREPEATINGELEMENTS_H_ */
