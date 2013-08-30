/*
 * FindTwoRepeatingElements.h
 *
 *  Created on: Aug 28, 2013
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

#ifndef FINDTWOREPEATINGELEMENTS_H_
#define FINDTWOREPEATINGELEMENTS_H_

int *FindTwoRepeatingElements(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
	sort(userInput,userInput+sizeOfArray);
	int result[2];
	int fillCounter = -1;
	for(int counter = 0;counter < sizeOfArray;){
		if(counter+1 < sizeOfArray){
			if(userInput[counter+1] != userInput[counter]){
				result[++fillCounter] = userInput[counter];
				counter++;
			}else{
				counter += 2;
			}
		}else{
			result[++fillCounter] = userInput[counter];
		}
	}
	return result;
}

#endif /* FINDTWOREPEATINGELEMENTS_H_ */
