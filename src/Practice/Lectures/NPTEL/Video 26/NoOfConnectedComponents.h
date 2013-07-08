/*
 * NoOfConnectedComponents.h
 *
 *  Created on: Jun 22, 2013
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

#ifndef NOOFCONNECTEDCOMPONENTS_H_
#define NOOFCONNECTEDCOMPONENTS_H_

struct adjacencyListDS{
	int adjacentVertex;
	int edgeName;
};

int NoOfConnectedComponents(vector<vector<adjacencyListDS>> adjacencyList){
	if(adjacencyList.size() == 0){
		return 0;
	}
	vector<int> visitedNodes;
	for(int resetCounter = 0;resetCounter < adjacencyList.size();resetCounter++){
		visitedNodes[resetCounter] = -1;
	}
	vector<adjacencyListDS> neighbouringVertices;
	queue<int> auxSpaceForConnectedComponents;
	int topIndex;
	int connectedComponentCounter = 0;
	for(int visitedNodesCounter = 0;visitedNodesCounter < visitedNodes.size();visitedNodesCounter++){
		if(visitedNodesCounter == -1){
			auxSpaceForConnectedComponents.push(visitedNodesCounter);
			while(!auxSpaceForConnectedComponents.empty()){
				topIndex = auxSpaceForConnectedComponents.front();
				auxSpaceForConnectedComponents.pop();
				neighbouringVertices = adjacencyList[topIndex];
				for(int adjacentVerticesCounter = 0;adjacentVerticesCounter < neighbouringVertices.size();adjacentVerticesCounter++){
					if(visitedNodes[adjacentVerticesCounter] == -1){
						auxSpaceForConnectedComponents.push(adjacencyList[topIndex][adjacentVerticesCounter].adjacentVertex);
						visitedNodes[adjacencyList[topIndex][adjacentVerticesCounter]] = connectedComponentCounter;
					}
				}
			}
			connectedComponentCounter++;
		}
	}
}

#endif /* NOOFCONNECTEDCOMPONENTS_H_ */
