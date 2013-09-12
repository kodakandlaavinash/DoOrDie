/*
 * PrismAlgorithm.h
 *
 *  Created on: Sep 7, 2013
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

#ifndef PRISMALGORITHM_H_
#define PRISMALGORITHM_H_

struct adjacencyListWithCost{
	int cost;
	int nodeIndex;
};

bool HeapFunctionForPrismAlgo(adjacencyListWithCost *firstNode,adjacencyListWithCost *secondNode){
	return firstNode->cost < secondNode->cost?true:false;
}

vector<adjacencyListWithCost *> FindMinimumSpanningTreePrismAlgo(vector<vector<adjacencyListWithCost *>> graphInput){
	if(allEdges == NULL || allEdges.size() == 0){
		return NULL;
	}
	bool groupForNodes[graphInput.size()];
	groupForNodes[0] = true;
	vector<adjacencyListWithCost *> auxSpace;
	for(int counter = 0;counter < graphInput[0].size();counter++){
		auxSpace.push_back(graphInput[0][counter]);
	}
	make_heap(auxSpace.begin(),auxSpace.end(),HeapFunctionForPrismAlgo);
	adjacencyListWithCost *tempMin;
	vector<adjacencyListWithCost *> minimumSpanningTree;
	for(int counter = 0;counter < graphInput.size();counter++){
		pop_heap(auxSpace.begin(),auxSpace.end());
		tempMin = auxSpace.front();
		if(!groupForNodes[tempMin->nodeIndex]){
			for(int neighbourCounter = 0;neighbourCounter = graphInput[tempMin->nodeIndex].size();neighbourCounter++){
				if(!groupForNodes[graphInput[tempMin->nodeIndex][neighbourCounter]->nodeIndex]){
					auxSpace.push_back(graphInput[tempMin->nodeIndex][neighbourCounter]);
					push_heap(auxSpace.begin(),auxSpace.end(),HeapFunctionForPrismAlgo);
				}
			}
			minimumSpanningTree.push_back(groupForNodes[tempMin->nodeIndex]);
		}
	}
	return minimumSpanningTree;
}

#endif /* PRISMALGORITHM_H_ */
