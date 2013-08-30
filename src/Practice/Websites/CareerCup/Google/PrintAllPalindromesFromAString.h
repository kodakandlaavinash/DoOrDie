/*
 * PrintAllPalindromesFromAString.h
 *	http://www.careercup.com/question?id=9689276
 *  Created on: Aug 29, 2013
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

#ifndef PRINTALLPALINDROMESFROMASTRING_H_
#define PRINTALLPALINDROMESFROMASTRING_H_

int IfPalindromeFindLengthUsingDeque(char *start,char *end){

}

int IfPalindromeFindLengthUsingLength(char *start,char *end){

}

void PrintAllPalindromes(char *userInput){
	if(userInput == NULL){
		return;
	}
	int lengthOfUserInput = strlen(userInput);
	char *tempString = (char *)calloc(lengthOfUserInput+1,sizeof(char));
	for(int counter = 0;counter < pow(2,lengthOfUserInput);counter++){
		bitset<lengthOfUserInput> binaryRepOfUserInput(counter);

	}
}


#endif /* PRINTALLPALINDROMESFROMASTRING_H_ */
