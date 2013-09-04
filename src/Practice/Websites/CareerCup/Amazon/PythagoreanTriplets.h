/*
 * PythagoreanTriplets.h
 *	http://www.careercup.com/question?id=5333117799759872
 *	http://geekyjumps.blogspot.in/2013/08/pythagorean-triplets.html
 *  Created on: Sep 4, 2013
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

#ifndef PYTHAGOREANTRIPLETS_H_
#define PYTHAGOREANTRIPLETS_H_

list<list<int>> GetPythagoreanTripletsON3(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
	int outerCounter,middleCounter,innerCounter;
	list<list<int>> listOfTriplets;
	int maxIndex;

	for(outerCounter =0;outerCounter < sizeOfArray-2;outerCounter++){
		for(middleCounter = outerCounter+1;middleCounter < sizeOfArray-1;middleCounter++){
			for(innerCounter = middleCounter;innerCounter < sizeOfArray;innerCounter++){
				if(userInput[outerCounter] > userInput[innerCounter]){
					if(userInput[outerCounter] > userInput[middleCounter]){
						if(userInput[outerCounter]*userInput[outerCounter] == userInput[innerCounter]*userInput[innerCounter] + userInput[middleCounter]*userInput[middleCounter]){
							list<int> atomicResult;
							atomicResult.push_back(userInput[innerCounter]);
							atomicResult.push_back(userInput[outerCounter]);
							atomicResult.push_back(userInput[middleCounter]);
							listOfTriplets.push_back(atomicResult);
						}
					}else{
						if(userInput[middleCounter]*userInput[middleCounter] == userInput[innerCounter]*userInput[innerCounter] + userInput[outerCounter]*userInput[outerCounter]){
							list<int> atomicResult;
							atomicResult.push_back(userInput[innerCounter]);
							atomicResult.push_back(userInput[outerCounter]);
							atomicResult.push_back(userInput[middleCounter]);
							listOfTriplets.push_back(atomicResult);
						}
					}
				}else{
					if(userInput[innerCounter]> userInput[middleCounter]){
						if(userInput[innerCounter]*userInput[innerCounter] == userInput[outerCounter]*userInput[outerCounter] + userInput[middleCounter]*userInput[middleCounter]){
							list<int> atomicResult;
							atomicResult.push_back(userInput[innerCounter]);
							atomicResult.push_back(userInput[outerCounter]);
							atomicResult.push_back(userInput[middleCounter]);
							listOfTriplets.push_back(atomicResult);
						}
					}else{
						if(userInput[middleCounter]*userInput[middleCounter] == userInput[innerCounter]*userInput[innerCounter] + userInput[outerCounter]*userInput[outerCounter]){
							list<int> atomicResult;
							atomicResult.push_back(userInput[innerCounter]);
							atomicResult.push_back(userInput[outerCounter]);
							atomicResult.push_back(userInput[middleCounter]);
							listOfTriplets.push_back(atomicResult);
						}
					}
				}
			}
		}
	}
	return listOfTriplets;
}

list<list<int>> GetPythagoreanTripletsON2(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
	hash_map<int,int> squaresOfNumbers;
	hash_map<int,int>::iterator itToSquareOfNumbers;
	for(int counter = 0;counter < sizeOfArray;counter++){
		squaresOfNumbers.insert(pair<int,int>(userInput[counter]*userInput[counter],userInput[counter]));
	}
	list<list<int>> listOfAllTriplets;
	int outerCounter,innerCounter,result;
	for(outerCounter = 0;outerCounter < sizeOfArray-1;outerCounter++){
		for(innerCounter = outerCounter;innerCounter < sizeOfArray;innerCounter++){
			result = (userInput[innerCounter]*userInput[innerCounter]) + (userInput[outerCounter]*userInput[outerCounter]);
			if((itToSquareOfNumbers = squaresOfNumbers.find(result))!=squaresOfNumbers.end()){
				list<int> atomicResult;
				atomicResult.push_back(userInput[innerCounter]);
				atomicResult.push_back(userInput[outerCounter]);
				atomicResult.push_back(itToSquareOfNumbers->second);
				listOfAllTriplets.push_back(atomicResult);
			}
		}
	}
	return listOfAllTriplets;
}

#endif /* PYTHAGOREANTRIPLETS_H_ */
