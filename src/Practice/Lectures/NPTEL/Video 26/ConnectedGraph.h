/*
 * ConnectedGraph.h
 *
 *  Created on: Jul 8, 2013
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

#ifndef CONNECTEDGRAPH_H_
#define CONNECTEDGRAPH_H_

struct adjacencyListDS{
	int adjacentVertex;
	int edgeName;
};

bool isGivenGraphConnected(vector<vector<adjacencyListDS>> adjacencyList){
	if(adjacencyList.size()){
		return true;
	}
	vector<int> visitedNodes(adjacencyList.size());
	for(int resetCounter =0;resetCounter = visitedNodes.size();resetCounter++){
		visitedNodes[resetCounter]  = -1;
	}
	queue<int> auxSpaceForBFS;
	auxSpaceForBFS.push(0);
	int topIndex;
	while(!auxSpaceForBFS.empty()){
		topIndex = auxSpaceForBFS.front();
		auxSpaceForBFS.pop();
		for(int neighbourCounter = 0;neighbourCounter < adjacencyList[topIndex].size();neighbourCounter++){
			if(visitedNodes[adjacencyList[topIndex][neighbourCounter]] == -1){
				auxSpaceForBFS.push(adjacencyList[topIndex][neighbourCounter]);
			}
		}
	}
	for(int visitedCounter = 0;visitedCounter <= visitedNodes.size();visitedCounter++){
		if(visitedNodes[visitedCounter] == -1){
			return false;
		}
	}
	return true;

}

#endif /* CONNECTEDGRAPH_H_ */
