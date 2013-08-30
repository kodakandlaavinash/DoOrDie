/*
 * ReorderFirstStringBasedOnSecondString.h
 *	http://www.careercup.com/question?id=9679682
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

#ifndef REORDERFIRSTSTRINGBASEDONSECONDSTRING_H_
#define REORDERFIRSTSTRINGBASEDONSECONDSTRING_H_

hash_map<char,int> ranksOfChars;

int AssignRanksToCharacters(char *referenceInput){
	for(int counter = 1;counter < 26;counter++){
		ranksOfChars.insert(pair<char,int>('a'+counter-1,INT_MAX));
	}
	char tempChar;
	int counter = -1;
	while((tempChar = *referenceInput) != '\0'){
		if(ranksOfChars[tempChar] == INT_MAX){
			ranksOfChars[tempChar] = ++counter;
		}
		referenceInput++;
	}
}

void SortCharactersUserInput(char *userInput,char *referenceInput){

}

#endif /* REORDERFIRSTSTRINGBASEDONSECONDSTRING_H_ */
