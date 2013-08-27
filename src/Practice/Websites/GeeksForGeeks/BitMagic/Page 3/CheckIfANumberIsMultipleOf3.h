/*
 * CheckIfANumberIsMultipleOf3.h
 *
 *  Created on: Aug 27, 2013
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

#ifndef CHECKIFANUMBERISMULTIPLEOF3_H_
#define CHECKIFANUMBERISMULTIPLEOF3_H_

bool CheckIfANumberIsMultipleOf3OrNot(int userInput){
	if(userInput == 0){
		return true;
	}
	if(userInput == 1 || userInput == 2){
		return false;
	}
	bitset<32> bitPatternOfUserInput(userInput);
	int counterOddPosition=0,counterEvenPosition=0;
	for(int counter = 0;counter < 32;counter++){
		if(counter & 1){
			counterOddPosition++;
		}else{
			counterEvenPosition++;
		}
	}
	return CheckIfANumberIsMultipleOf3OrNot(mod(counterOddPosition-counterEvenPosition));
}

bool CheckIfANumberIsMultipleOf3OrNotShifting(int userInput){
	if(userInput == 0){
		return true;
	}
	if(userInput == 1 || userInput == 2){
		return false;
	}
	unsigned int oddBitCounter=0,evenBitCounter=0;

	while(userInput){
		if(userInput & 1){
			oddBitCounter++;
		}
		userInput = userInput >> 1;
		if(userInput & 1){
			evenBitCounter++;
		}
		userInput = userInput >> 1;
	}
}

#endif /* CHECKIFANUMBERISMULTIPLEOF3_H_ */
