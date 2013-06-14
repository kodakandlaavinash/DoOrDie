/*
 * PrintAllDuplicatesInputString.h
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

#ifndef PRINTALLDUPLICATESINPUTSTRING_H_
#define PRINTALLDUPLICATESINPUTSTRING_H_

void PrintAllDuplicates(char *userInput){
	if(userInput == NULL){
		return;
	}
	char *crawler;
	bitset<256> visitedChar;
	visitedChar.reset();
	char *innerCrawler;
	for(crawler = userInput;crawler != '\0';++crawler){
		if(!visitedChar[(int)crawler]){
			for(innerCrawler= crawler+1;innerCrawler != '\0';innerCrawler++){
				if(userInput[innerCrawler] == userInput[crawler]){
					printf("%c",userInput[crawler]);
					break;
				}
			}
			visitedChar[(int)crawler] = true;
		}
	}
}

void PrintAllDuplicatesON(char *userInput){
	if(userInput == NULL){
		return;
	}
	int characterFrequency[256];
	char *crawler = userInput;
	char currentChar;
	while(*crawler != '\0'){
		currentChar = *crawler;
		characterFrequency[currentChar]++;
		crawler++;
	}

	for(int frequencyCrawler = 0;frequencyCrawler < 256;frequencyCrawler++){
		if(characterFrequency[frequencyCrawler] > 1){
			printf("%c\t",frequencyCrawler);
		}
	}
}


#endif /* PRINTALLDUPLICATESINPUTSTRING_H_ */
