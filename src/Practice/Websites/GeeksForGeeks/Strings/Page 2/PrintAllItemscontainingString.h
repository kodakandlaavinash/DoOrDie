/*
 * PrintAllItemscontainingString.h
 *
 *  Created on: Apr 30, 2013
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

#ifndef PRINTALLITEMSCONTAININGSTRING_H_
#define PRINTALLITEMSCONTAININGSTRING_H_

void PrintAllItemsWhichContainsGivenLetters(char *listOfWords[],char *word,int listSize){
	hash_map<char,int> frequencyCounter;
	char *crawler = word;
	char currentCharacter;
	hash_map<char,int>::iterator itToFrequencyCounter;
	while(*crawler != '\0' && *crawler != NULL){
		currentCharacter = *crawler;
		if((itToFrequencyCounter = frequencyCounter.find(currentCharacter)) != frequencyCounter.end()){
			frequencyCounter[currentCharacter] += 1;
		}else{
			frequencyCounter[currentCharacter] = 1;
		}
		crawler++;
	}
}

void PrintAllItemsWhichContainsGivenLettersBySorting(char *listOfWords[],char *keyWord,int listSize){
	//After sorting move the crawler one by one from front or back
}


#endif /* PRINTALLITEMSCONTAININGSTRING_H_ */
