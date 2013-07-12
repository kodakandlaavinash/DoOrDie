/*
 * IsDirectedStronglyConnectedOrNot.h
 *
 *  Created on: Jun 27, 2013
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

#ifndef ISDIRECTEDSTRONGLYCONNECTEDORNOT_H_
#define ISDIRECTEDSTRONGLYCONNECTEDORNOT_H_

struct adjacencyListDS{
	int adjacentVertex;
	int edgeName;
};

bool IsGivenDirectedGraphStronglyConnected(vector<vector<adjacencyListDS>> adjacencyList){
	if(adjacencyList.size()){
		return true;
	}
	vector<int> arrivalTimes;
	vector<int> departureTimes;
	for(int counter = 0;counter < adjacencyList.size();counter++){
		arrivalTimes.clear();
		departureTimes.clear();
		PerformADFSInDirectedGraph(adjacencyList,counter,arrivalTimes,departureTimes);
		for(int arrivalTimeCounter = 0;arrivalTimeCounter < arrivalTimes.size();arrivalTimeCounter++){
			if(arrivalTimes[arrivalTimeCounter] == -1){
				return false;
			}
		}
	}
	return true;
}

bool IsGivenDirectedGraphStronglyConnected(vector<vector<adjacencyListDS>> adjacencyList){
	if(adjacencyList.size()){
		return true;
	}
	vector<int> arrivalTimes;
	vector<int> departureTimes;
	PerformADFSInDirectedGraph(adjacencyList,0,arrivalTimes,departureTimes);
	for(int arrivalTimeCounter = 0;arrivalTimeCounter = arrivalTimes.size();arrivalTimeCounter++){
		if(arrivalTimes[arrivalTimeCounter] == -1){
			return false;
		}
	}

	vector<vector<adjacencyListDS>> reverseAdjacencyList;
	arrivalTimes.clear();
	departureTimes.clear();
	PerformADFSInDirectedGraph(reverseAdjacencyList,0,arrivalTimes,departureTimes);
	for(int arrivalTimeCounter = 0;arrivalTimeCounter = arrivalTimes.size();arrivalTimeCounter++){
		if(arrivalTimes[arrivalTimeCounter] == -1){
			return false;
		}
	}

	return true;
}

#endif /* ISDIRECTEDSTRONGLYCONNECTEDORNOT_H_ */
