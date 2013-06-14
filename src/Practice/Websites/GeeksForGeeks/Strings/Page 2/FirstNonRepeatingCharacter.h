/*
 * FirstNonRepeatingCharacter.h
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

#ifndef FIRSTNONREPEATINGCHARACTER_H_
#define FIRSTNONREPEATINGCHARACTER_H_

char FirstNonRepeatingCharacter(char *userInput){
	bitset<256> visitedChars;
	char *crawler = userInput;
	char currentChar;
	while(*crawler != '\0'){
		currentChar = *crawler;
		crawler++;
		visitedChars[currentChar] = true;
	}

	crawler = userInput;
	while(*crawler != '\0'){
		currentChar = *crawler;
		crawler++;
		if(!visitedChars[currentChar]){
			return currentChar;
		}
	}
	return '\0';
}

char FirstNonRepeatingCharacterON2(char *userInput){
	if(userInput == NULL){
		return '\0';
	}
	int innerCrawler;
	int lengthOfUserInput = strlen(userInput);
	for(int outerCrawler = 0;outerCrawler < lengthOfUserInput;outerCrawler++){
		int counter = 1;
		for(innerCrawler = outerCrawler+1;innerCrawler < lengthOfUserInput;innerCrawler++){
			if(userInput[innerCrawler] == userInput[outerCrawler]){
				counter++;
				break;
			}
		}
		if(counter == 1){
			return userInput[outerCrawler];
		}
	}
	return '\0';
}


#endif /* FIRSTNONREPEATINGCHARACTER_H_ */
