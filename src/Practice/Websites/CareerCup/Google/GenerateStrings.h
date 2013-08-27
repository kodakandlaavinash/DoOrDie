/*
 * GenerateStrings.h
 *	http://www.careercup.com/question?id=20308668
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

#ifndef GENERATESTRINGS_H_
#define GENERATESTRINGS_H_

void GenerateStrings(char userInput[],int startIndex,int endIndex){
	if(startIndex > endIndex){
		return;
	}
	if(startIndex == endIndex){
		printf("%s",userInput);
	}
	char temp;
	while((temp = userInput[startIndex])!='?'){
		startIndex++;
	}
	userInput[startIndex] = '0';
	GenerateStrings(userInput,startIndex,endIndex);
	userInput[startIndex] = '1';
	GenerateStrings(userInput,startIndex,endIndex);
}

void GenerateStrings(char userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return;
	}
	int totalNumberWildCards = 0;
	for(int counter =0;counter < sizeOfArray;counter++){
		if(userInput[counter] == '?'){
			totalNumberWildCards++;
		}
	}

	int bitCounter;
	for(int counter =0;counter < totalNumberWildCards;counter++){
		bitset<totalNumberWildCards> bitRepOfDecimal(counter);
		bitCounter=-1;
		for(int userInputCounter = 0;userInputCounter < sizeOfArray;userInputCounter++){
			if(userInput[userInputCounter] == '?'){
				printf("%c",bitRepOfDecimal[++bitCounter]==false?0:1);
			}else{
				printf("%c",userInput[userInputCounter]);
			}
		}
		printf("\n");
	}
}


#endif /* GENERATESTRINGS_H_ */
