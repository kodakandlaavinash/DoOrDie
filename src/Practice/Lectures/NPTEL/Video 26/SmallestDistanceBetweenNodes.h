/*
 * SmallestDistanceBetweenNodes.h
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

#ifndef SMALLESTDISTANCEBETWEENNODES_H_
#define SMALLESTDISTANCEBETWEENNODES_H_
struct adjacencyListDS{
	int adjacentVertex;
	int edgeName;
};
int SmallestDistanceBetweenTwoNodes(vector<vector<adjacencyListDS>> adjacencyList,int sourceIndex,int destinationIndex){
	if(adjacencyList.size() == 0 || sourceIndex >= adjacencyList.size() || destinationIndex >= adjacencyList.size()){
		return INT_MIN;
	}
	vector<int> levelOfNodesInBFSTree;
	for(int resetCounter =0;resetCounter < adjacencyList.size();resetCounter++){
		levelOfNodesInBFSTree[resetCounter] = -1;
	}
	queue<int> auxSpaceForBFS;
	auxSpaceForBFS.push(sourceIndex);
	int topIndex;
	int currentNodeLevel;
	while(!auxSpaceForBFS.empty()){
		topIndex = auxSpaceForBFS.front();
		currentNodeLevel = levelOfNodesInBFSTree[topIndex];
		for(int neighbourCounter = 0;neighbourCounter < adjacencyList[topIndex].size();neighbourCounter++){
			if(destinationIndex == adjacencyList[topIndex][neighbourCounter]){
				return currentNodeLevel+1;
			}
			if(levelOfNodesInBFSTree[adjacencyList[topIndex][neighbourCounter]] == -1){
				auxSpaceForBFS.push(adjacencyList[topIndex][neighbourCounter]);
				levelOfNodesInBFSTree[adjacencyList[topIndex][neighbourCounter]] = currentNodeLevel+1;
			}
		}
	}

	return INT_MIN;
}

#endif /* SMALLESTDISTANCEBETWEENNODES_H_ */
