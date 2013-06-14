/*
 * PrintReverseOfStringRecursion.h
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

#ifndef PRINTREVERSEOFSTRINGRECURSION_H_
#define PRINTREVERSEOFSTRINGRECURSION_H_

void PrintReverseOfString(char *userInput){
	if(userInput == '\0'||userInput == null){
		return;
	}
	PrintReverseOfString(userInput+1);
	char ch = *userInput;
	printf("%c",ch);
}

void PrintReverseOfStringAuxStack(char *userInput){
	if(userInput == '\0'||userInput == null){
		return;
	}
	stack<char> auxSpace;
	char *crawler;
	char ch;
	while((ch = *crawler) != '\0'){
		auxSpace.push(ch);
	}

	while(!auxSpace.empty()){
		printf("%c",auxSpace.top());
		auxSpace.pop();
	}
}

void PrintReverseStringLength(char *userInput){
	if(userInput == '\0' || userInput == NULL){
		return;
	}
	int lengthOfUserInput = strlen(userInput);
	for(int counter = lengthOfUserInput-1;counter>=0;counter--){
		printf("%c",userInput[counter]);
	}
}

void PrintReverseStringIterator(char *userInput){
	if(userInput == '\0' || userInput == NULL){
		return;
	}
	string input = userInput;
	string::iterator itToUserInput;
	for(itToUserInput = input.end();itToUserInput != input.begin();){
		itToUserInput--;
		printf("%c",*itToUserInput);
	}
}

void PrintReverseStringReverseIterator(char *userInput){
	if(userInput == '\0' || userInput == NULL){
		return;
	}
	string input = userInput;
	string::iterator itToUserInput;
	for(itToUserInput = input.rbegin();itToUserInput != input.rend();itToUserInput++){
		printf("%c",*itToUserInput);
	}
}

#endif /* PRINTREVERSEOFSTRINGRECURSION_H_ */
