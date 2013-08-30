/*
 * RemoveACAndB.h
 *
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

#ifndef REMOVEACANDB_H_
#define REMOVEACANDB_H_

char *RemoveACAndB(char *userInput){
	char currentChar,tempChar;
	char *userInputCrawler;
	int counter = -1;
	while((currentChar = *userInputCrawler) != '\0'){
		counter++;
		if(currentChar == 'B'){
			userInput[counter] = '$';
		}
		if(currentChar == 'A'){
			if((tempChar = *(userInputCrawler+1))== 'C'){
				userInput[counter] = '$';
				userInput[counter+1] = '$';
				counter++;
				userInputCrawler++;
			}
		}
		userInputCrawler++;
	}
	int characterToBeFilled = -1;
	while(true){

	}
}

#endif /* REMOVEACANDB_H_ */
