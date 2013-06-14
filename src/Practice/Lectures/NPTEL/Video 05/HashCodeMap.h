/*
 * HashCodeMap.h
 *
 *  Created on: May 27, 2013
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

#ifndef HASHCODEMAP_H_
#define HASHCODEMAP_H_

int HashCodeMapStrategy1(char *userInput){
	int sumOfAsciiValue = 0;
	char *crawler = userInput;
	char ch;
	while((ch = *crawler) !='\0'){
		sumOfAsciiValue += ch;
		crawler++;
	}
	return sumOfAsciiValue;
}

int HashCodeMapStrategy2(char *userInput){
	static int valueOfXIndex;
	if(valueOfXIndex == 0){
		valueOfXIndex = GenerateChoiceForX();
	}
	int choiceForX[] = {33,37,39,41};
	int polynomialAccumulation = 0;
	char *crawler = userInput;
	char ch;
	int counter = 0;
	while((ch = *crawler) != '\0'){
		polynomialAccumulation += ch + powl(choiceForX[valueOfXIndex - 1],counter);
		counter++;
		crawler++;
	}
	return polynomialAccumulation;
}


int GenerateChoiceForX(){
	return rand()%4 + 1;
}

#endif /* HASHCODEMAP_H_ */
