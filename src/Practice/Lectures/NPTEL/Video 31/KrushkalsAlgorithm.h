/*
 * KrushkalsAlgorithm.h
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

#ifndef KRUSHKALSALGORITHM_H_
#define KRUSHKALSALGORITHM_H_

#define KRUSHKAL_VISITED_NODE_FLAG 1
#define KRUSHKAL_UNVISITED_NODE_FLAG -1
#define KRUSHKAL_TOTAL_NODES 10

struct UnionFindDS{
	int value;
	int nodesCount;
	UnionFindDS *parent;
};

struct krushkalsDS{
	int startVertex;
	int endVertex;
	int value;
	UnionFindDS *startVertexRef;
	UnionFindDS *endVertexRef;
};

struct graphInput{
	int areConnected;
	int cost;
};


UnionFindDS *FindFromUnionDS(UnionFindDS *ptr){
	if(ptr == NULL){
		return NULL;
	}
	while(ptr->parent != NULL){
		ptr = ptr->parent;
	}
	return ptr;
}

bool krushkalCompareFunc(krushkalsDS firstEdge,krushkalsDS secondEdge){
	return firstEdge.value > secondEdge.value?true:false;
}

vector<krushkalsDS> MinimumSpanningTreeKrushkalsAlgorithm(vector<krushkalsDS> allEdges,int totalNoOfNodes){
	if(allEdges == NULL || allEdges.size() == 0){
		return;
	}
	int visitedFlag[totalNoOfNodes]= {KRUSHKAL_UNVISITED_NODE_FLAG};
	//Because in a tree the no of edges are equal to #nodes -1
	krushkalsDS currentEdge;
	vector<krushkalsDS> minimumSpanningTree;
	UnionFindDS *tempStartVertex,*tempEndVertex;
	sort(allEdges.begin(),allEdges.end(),krushkalCompareFunc);
	for(int counter =0;counter < allEdges.size();counter++){
		if((tempStartVertex = FindFromUnionDS(allEdges[counter].startVertexRef)) != (tempEndVertex = FindFromUnionDS(allEdges[counter].endVertexRef))){
			if(tempStartVertex->nodesCount > tempEndVertex->nodesCount){
				tempEndVertex->parent = tempStartVertex;
				tempStartVertex->nodesCount += tempEndVertex->nodesCount;
			}else{
				tempStartVertex->parent = tempEndVertex;
				tempEndVertex->nodesCount += tempStartVertex->nodesCount;
			}
			minimumSpanningTree.push_back(allEdges[counter]);
		}
	}
	return minimumSpanningTree;
}

int *MinimumSpanningTreeKrushkalsDriver(graphInput userInputGraph[][KRUSHKAL_TOTAL_NODES],int noOfNodes){

	vector<krushkalsDS> krushkalAlgoInput;
	int rowCounter,columnCounter;
	hash_map<int,UnionFindDS *> nodeUnionFindDSMap;
	hash_map<int,UnionFindDS *>::iterator itToNodeUnionFindDSMap;
	for(rowCounter =0;rowCounter < noOfNodes;rowCounter++){
		for(columnCounter = 0;columnCounter < noOfNodes;columnCounter++){
			if(userInputGraph[rowCounter][columnCounter] == 1){
				krushkalsDS newNode;
				newNode.endVertex = columnCounter;
				newNode.startVertex = rowCounter;
				if(itToNodeUnionFindDSMap = nodeUnionFindDSMap.find(rowCounter) != nodeUnionFindDSMap.end()){
					newNode.startVertexRef = itToNodeUnionFindDSMap->second;
				}else{
					UnionFindDS *newRef = (UnionFindDS *)malloc(sizeof(UnionFindDS));
					newRef->nodesCount = 1;
					newRef->parent = NULL;
					newRef->value = rowCounter;
					nodeUnionFindDSMap.insert(pair<int,UnionFindDS *>(rowCounter,newRef));
					newNode.startVertexRef = newRef;
				}
				if(itToNodeUnionFindDSMap = nodeUnionFindDSMap.find(columnCounter) != nodeUnionFindDSMap.end()){
					newNode.endVertexRef = itToNodeUnionFindDSMap->second;
				}else{
					UnionFindDS *newRef = (UnionFindDS *)malloc(sizeof(UnionFindDS));
					newRef->nodesCount = 1;
					newRef->parent = NULL;
					newRef->value = columnCounter;
					nodeUnionFindDSMap.insert(pair<int,UnionFindDS *>(columnCounter,newRef));
					newNode.endVertexRef = newRef;
				}
				krushkalAlgoInput.push_back(newNode);
			}
		}
	}
	vector<krushkalsDS> result = MinimumSpanningTreeKrushkalsAlgorithm(krushkalAlgoInput,KRUSHKAL_TOTAL_NODES);
	int minimumSpanningTreeSum = 0;
	for(int counter = 0;counter < result.size();counter++){
		minimumSpanningTreeSum += result[counter].value;
	}
	printf("Length of minimum spanning tree "+minimumSpanningTreeSum);
	return result;
}

#endif /* KRUSHKALSALGORITHM_H_ */
