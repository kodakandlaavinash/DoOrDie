/*
 * DetectACycleInAGraph.h
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

#ifndef DETECTACYCLEINAGRAPH_H_
#define DETECTACYCLEINAGRAPH_H_

struct adjacencyListDS{
	int adjacentVertex;
	int edgeName;
};

bool DoesCycleExistsInAGraph(vector<vector<adjacencyListDS>> adjacencyList,int source){
	if(adjacencyList.size() == 0){
		return false;
	}
	static int timeCounter = -1;
	vector<int> arrivalTimes;
	if(adjacencyList[source].size() == 0){
		return true;
	}
	for(int neighbourCounter = 0;neighbourCounter < adjacencyList[source].size();neighbourCounter++){
		if(arrivalTimes[adjacencyList[source][neighbourCounter]] != -1){
			return false;
		}
		arrivalTimes[adjacencyList[source][neighbourCounter]] = ++timeCounter;
		return DoesCycleExistsInAGraph(adjacencyList,source);
	}
}
#endif /* DETECTACYCLEINAGRAPH_H_ */
