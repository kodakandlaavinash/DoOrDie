 /*
 * FirstCircularTourVisitingAllPetrolPumps.h
 *
 *  Created on: Aug 21, 2013
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

#ifndef FIRSTCIRCULARTOURVISITINGALLPETROLPUMPS_H_
#define FIRSTCIRCULARTOURVISITINGALLPETROLPUMPS_H_

int FirstCircularTourVisitingAllPetrolPumpsON2(int userInput[][2],int noOfRows){
	if(userInput == NULL || noOfRows == 0){
		return INT_MIN;
	}
	int outerCounter,innerCounter,currentPetrol = 0;
	bool reached;
	for(outerCounter = 0;outerCounter < noOfRows;outerCounter++){
		reached = true;
		currentPetrol = 0;
		for(innerCounter=outerCounter;innerCounter != outerCounter;innerCounter++,innerCounter%noOfRows){
			currentPetrol = userInput[innerCounter][0];
			if(currentPetrol < userInput[innerCounter][1]){
				reached = false;
			}
		}
		if(reached){
			return outerCounter;
		}
	}
	return INT_MIN;
}

int FirstCircularTourVisitingAllPetrolPumpsON(int userInput[][2],int noOfRows){
	if(userInput == NULL || noOfRows == 0){
		return INT_MIN;
	}
	queue<int> auxSpace;
	auxSpace.push(0);
	int currentPetrol;
	while(auxSpace.empty()){

	}
}

#endif /* FIRSTCIRCULARTOURVISITINGALLPETROLPUMPS_H_ */
