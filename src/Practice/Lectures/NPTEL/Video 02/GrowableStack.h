/*
 * GrowableStack.h
 *
 *  Created on: May 28, 2013
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
#define INCREMENTS_FOR_TIGHT_STRATEGY 4
//int main(){
//	return -1;
//}

#ifndef GROWABLESTACK_H_
#define GROWABLESTACK_H_

void DoublingStrategy(int userInput[],int sizeOfUserInput){
	int *newUserAuxSpace;
	newUserAuxSpace = (int *)calloc(2*sizeOfUserInput,sizeof(int));
	int *crawlerForNewArray = newUserAuxSpace;
	for(int crawler =0;crawler < sizeOfUserInput;crawler++){
		crawlerForNewArray[crawler] = userInput[crawler];
	}
	userInput = newUserAuxSpace;
	return;
}

void TightStrategy(int userInput[],int sizeOfUserInput){
	int *newUserAuxSpace;
	newUserAuxSpace = (int *)calloc(sizeOfUserInput+INCREMENTS_FOR_TIGHT_STRATEGY,sizeof(int));
	int *crawlerForNewArray = newUserAuxSpace;
	for(int crawler=0;crawler < sizeOfUserInput;crawler++){
		crawlerForNewArray[crawler] = userInput[crawler];
	}
	userInput = newUserAuxSpace;
	return;
}

#endif /* GROWABLESTACK_H_ */
