/*
 * BFSForUndirectedGraph.h
 *
 *  Created on: Jun 21, 2013
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

#ifndef BFSFORUNDIRECTEDGRAPH_H_
#define BFSFORUNDIRECTEDGRAPH_H_

struct adjacencyListDS{
	int adjacentVertex;
	int edgeName;
};

void CreateBFSTree(vector<vector<adjacencyListDS>> adjacencyList,int sourceNodeIndex){
	hash_map<int,int> nodeLevelMap;
	hash_map<int,int>::iterator *itToNodeLevelMap;
	queue<int> auxSpaceForBFS;
	int currentNode;
	int levelForCurrentNode;
	auxSpaceForBFS.push(sourceNodeIndex);
	nodeLevelMap.insert(pair<int,int>(sourceNodeIndex,0));
	vector<adjacencyListDS> adjacentNodesOfCurrentNode;
	adjacencyListDS *adjacentNode;
	while(!auxSpaceForBFS.empty()){
		currentNode = auxSpaceForBFS.front();
		itToNodeLevelMap = nodeLevelMap.find(currentNode);
		levelForCurrentNode = (*itToNodeLevelMap)->second;
		adjacentNodesOfCurrentNode = adjacencyList[currentNode];
		for(int counter =0;counter < adjacencyList.size();counter++){
			if((itToNodeLevelMap = nodeLevelMap.find(adjacentNodesOfCurrentNode[counter].adjacentVertex))== nodeLevelMap.end()){
				nodeLevelMap.insert(pair<int,int>((*itToNodeLevelMap)->first,currentNode+1));
			}
		}
	}

	return nodeLevelMap;
}


#endif /* BFSFORUNDIRECTEDGRAPH_H_ */
