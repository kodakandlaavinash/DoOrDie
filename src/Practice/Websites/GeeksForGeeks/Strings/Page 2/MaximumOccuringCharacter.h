/*
 * MaximumOccuringCharacter.h
 *
 *  Created on: Apr 29, 2013
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

#ifndef MAXIMUMOCCURINGCHARACTER_H_
#define MAXIMUMOCCURINGCHARACTER_H_

int MaximumOccuringCharacter(char *userInput){
	if(userInput == NULL){
		return '\0';
	}
	hash_map<char,int> charFrequency;
	char *crawler = userInput;
	hash_map<char,int>::iterator itToCharFrequency;
	char currentCharacter;
	int currentCharacterFrequency = 0;
	while(*crawler != '\0'){
		currentCharacter = *crawler;
		if((itToCharFrequency = charFrequency.find(currentCharacter))!= charFrequency.end()){
			currentCharacterFrequency = itToCharFrequency->second;
			charFrequency[currentCharacter] = ++currentCharacterFrequency;
		}else{
			charFrequency[currentCharacter] = 1;
		}
	}

	int maxCount = INT_MIN;
	char maxOccuringChar;

	for(itToCharFrequency = charFrequency.begin();itToCharFrequency != charFrequency.end();itToCharFrequency++){
		if(maxCount < itToCharFrequency->second){
			maxCount = itToCharFrequency->second;
			maxOccuringChar = itToCharFrequency->first;
		}
	}

	return maxOccuringChar;
}

char maxOccuringCharacterON2(char *userInput){
	if(userInput == NULL){
		return '\0';
	}
	int innerCounter;
	int userInputLength = strlen(userInput);
	int counterCurrentChar;
	int maxCount = INT_MIN;
	char maxOccuringChar;
	for(int outerCounter=0;outerCounter < userInputLength;outerCounter++){
		counterCurrentChar = 0;
		for(innerCounter =0;innerCounter < userInputLength;innerCounter++){
			if(userInput[outerCounter] == userInput[innerCounter]){
				counterCurrentChar++;
			}
		}

		if(maxCount < counterCurrentChar){
			maxCount = counterCurrentChar;
			maxOccuringChar = userInput[outerCounter];
		}
	}

	return maxOccuringChar;
}

char MaxOccuringCharSortingONLOGN(char *userInput){
	if(userInput == NULL){
		return '\0';
	}
	int lengthOfUserInput = strlen(userInput);
	sort(userInput,userInput+lengthOfUserInput);
	int innerCrawler;
	int counter= 0;
	int maxCounter = INT_MIN;
	char maxOccuringCharacter;
	for(int outerCrawler =0;outerCrawler < lengthOfUserInput;outerCrawler = outerCrawler+counter){
		counter = 0;
		for(innerCrawler=0;innerCrawler < lengthOfUserInput;innerCrawler++){
			if(userInput[outerCrawler] == userInput[innerCrawler]){
				counter++;
			}
		}

		if(maxCounter < counter){
			maxCounter = counter;
			maxOccuringCharacter = userInput[outerCrawler];
		}
	}

	return maxOccuringCharacter;
}

char maxOccuringCharacterAuxArray(char *userInput){
	if(userInput == NULL){
		return '\0';
	}
	int auxArray[256];
	char currentChar;
	char *crawler = userInput;
	while((currentChar = *userInput) != '\0'){
		auxArray[currentChar]++;
	}

	int maxOccuringCounter = INT_MIN;
	int maxOccuringCharIndex;
	for(int counter=0;counter < 256;counter++){
		if(auxArray[counter] > maxOccuringCounter){
			maxOccuringCharIndex = counter;
			maxOccuringCounter = auxArray[counter];
		}
	}

	return (char)maxOccuringCharIndex;
}

#endif /* MAXIMUMOCCURINGCHARACTER_H_ */
