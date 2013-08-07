/*
 * ReplaceEveryElementWithGreatestElementRight.h
 *
 *  Created on: Aug 6, 2013
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

#ifndef REPLACEEVERYELEMENTWITHGREATESTELEMENTRIGHT_H_
#define REPLACEEVERYELEMENTWITHGREATESTELEMENTRIGHT_H_

void ReplaceEveryElementWithGreaterElementRight(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return;
	}
	int innerCounter,outerCounter;
	bool greatestElementFound;
	for(outerCounter = 0;outerCounter < sizeOfArray;outerCounter++){
		greatestElementFound = false;
		for(innerCounter = outerCounter+1;innerCounter < sizeOfArray;innerCounter++){
			if(userInput[outerCounter] < userInput[innerCounter]){
				greatestElementFound = true;
				break;
			}
		}
		if(greatestElementFound){
			userInput[outerCounter] = userInput[innerCounter];
		}else{
			userInput[outerCounter] = -1;
		}
	}
}



#endif /* REPLACEEVERYELEMENTWITHGREATESTELEMENTRIGHT_H_ */
