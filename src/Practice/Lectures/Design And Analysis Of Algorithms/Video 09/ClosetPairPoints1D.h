/*
 * ClosetPairPoints1D.h
 *
 *  Created on: Aug 25, 2013
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

#ifndef CLOSETPAIRPOINTS1D_H_
#define CLOSETPAIRPOINTS1D_H_

int ClosestPaitOfPoints1dNavice(int userInputXCoordinates[],int sizeOfArray){
	if(userInputXCoordinates == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
	int outerCounter,innerCounter;
	int minDistance = INT_MAX,currentDistance;
	for(outerCounter = 0;outerCounter < sizeOfArray;outerCounter++){
		for(innerCounter = outerCounter+1;innerCounter < sizeOfArray;innerCounter++){
			currentDistance = abs(userInputXCoordinates[innerCounter]-userInputXCoordinates[outerCounter]);
			if(currentDistance < minDistance){
				minDistance = currentDistance;
			}
		}
	}
	return minDistance;
}

int ClosestPairOfPoints1DOptimised(int userInputXCoordinates[],int sizeOfArray){
	if(userInputXCoordinates == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
	sort(userInputXCoordinates,userInputXCoordinates+sizeOfArray);
	int minDistance = INT_MAX,distance;
	for(int counter = 1;counter < sizeOfArray-1;userInputXCoordinates++){
		distance = min(userInputXCoordinates[counter] - userInputXCoordinates[counter-1],userInputXCoordinates[counter+1]-userInputXCoordinates[counter]);
		if(minDistance > distance){
			minDistance = distance;
		}
	}
	return minDistance;
}

#endif /* CLOSETPAIRPOINTS1D_H_ */
