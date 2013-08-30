/*
 * BiggestIntervalContainingAllInput.h
 *	http://www.careercup.com/question?id=21630672
 *	question?id=19778663
 *	http://stackoverflow.com/questions/17591467/find-the-biggest-interval-that-has-all-its-members-in-list-in-on
 *  Created on: Aug 23, 2013
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

#ifndef BIGGESTINTERVALCONTAININGALLINPUT_H_
#define BIGGESTINTERVALCONTAININGALLINPUT_H_

int BiggestIntervalContainingAllInput(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray){
		return 0;
	}
	hash_map<int,int> intervalsFlags;
	hash_map<int,int>::iterator itToIntevalsEndPoints;
	for(int counter = 0;counter < sizeOfArray;counter++){
		if((itToIntevalsEndPoints = intervalsFlags.find(counter-1))!=intervalsFlags.end()){

		}
		if((itToIntevalsEndPoints = intervalsFlags.find(counter+1))!=intervalsFlags.end()){

		}
	}

}

#endif /* BIGGESTINTERVALCONTAININGALLINPUT_H_ */
