/*
 * DFSInDirectedGraph.h
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

#ifndef DFSINDIRECTEDGRAPH_H_
#define DFSINDIRECTEDGRAPH_H_

struct adjacencyListDS{
	int adjacentVertex;
	int edgeName;
};

void PerformDFSInUnDirectedGraphRecursive(vector<vector<adjacencyListDS>> adjacencyList,int source){
	if(adjacencyList.size() == 0){
		return;
	}
	static  int timeCounter = -1;
	vector<int> departureTimes;
	vector<int> arrivalTimes;
	vector<adjacencyListDS> neighbours;
	for(int neighbourCounter = 0;neighbourCounter < adjacencyList[source].size();neighbourCounter++){
		arrivalTimes[adjacencyList[source][neighbourCounter]] = ++timeCounter;
		PerformDFSInUnDirectedGraph(adjacencyList,adjacencyList[source][neighbourCounter]);
	}
	departureTimes[source] = ++timeCounter;
}

void PerformDFSInUnDirectedGraphIterative(vector<vector<adjacencyListDS>> adjacencyList){
	if(adjacencyList.size() == 0){
		return;
	}
	vector<int> departureTimes;
	vector<int> arrivalTimes;
	stack<int> auxSpaceForDFS;
	int topIndex;
	while(!auxSpaceForDFS.empty()){
		topIndex = auxSpaceForDFS.top();
		auxSpaceForDFS.pop();
		for(int neighbouringCounter = adjacencyList[topIndex].size()-1;neighbouringCounter >=0;neighbouringCounter--){

		}

	}
}

#endif /* DFSINDIRECTEDGRAPH_H_ */
