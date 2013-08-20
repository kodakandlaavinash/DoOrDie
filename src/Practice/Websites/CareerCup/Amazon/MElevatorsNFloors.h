/*
 * MElevatorsNFloors.h
 * http://www.careercup.com/question?id=5625215304335360
 *  Created on: Aug 20, 2013
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

#ifndef MELEVATORSNFLOORS_H_
#define MELEVATORSNFLOORS_H_

int FindClosestElevatorUsingBinarySearch(int elevatorsPositionInOrder[],int startArray,int endArray,int key){
	if(startArray > endArray){
		return INT_MIN;
	}
	int middleIndex = (startArray + endArray)/2;
	if(elevatorsPositionInOrder[middleIndex] == key){
		return middleIndex;
	}
	if(middleIndex-1 < startArray){
		if(elevatorsPositionInOrder[middleIndex] < key){
			return middleIndex;
		}
	}
	if(middleIndex+1 > endArray){
		if(elevatorsPositionInOrder[middleIndex] > key){
			return middleIndex;
		}
	}
	if(elevatorsPositionInOrder[middleIndex-1] < key && elevatorsPositionInOrder[middleIndex+1] < key){
		return abs(key - elevatorsPositionInOrder[middleIndex-1]) > abs(key-elevatorsPositionInOrder[middleIndex+1])?middleIndex+1:middleIndex-1;
	}
	if(elevatorsPositionInOrder[middleIndex] > key){
		return FindClosestElevatorUsingBinarySearch(elevatorsPositionInOrder,startArray,middleIndex-1,key);
	}else{
		return FindClosestElevatorUsingBinarySearch(elevatorsPositionInOrder,middleIndex+1,endArray,key);
	}

}

int MElevatorsNFloors(int elevatorsPositionInOrder[],int noOfElevators,int userRequest){
	if(elevatorsPositionInOrder == NULL || noOfElevators == 0){
		return INT_MIN;
	}
	return FindClosestElevatorUsingBinarySearch(elevatorsPositionInOrder,0,noOfElevators-1,userRequest);
}

#endif /* MELEVATORSNFLOORS_H_ */
