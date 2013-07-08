/*
 * AdjacencyMatrix.h
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

#ifndef ADJACENCYMATRIX_H_
#define ADJACENCYMATRIX_H_

struct adjacencyMatrix{
	bool edgeExists;
	char *edgeName[50];
};

int *createAdjacencyMatrixForUndirectedGraph(int noOfVertex){
	if(noOfVertex == 0){
		return NULL;
	}
	adjacencyMatrix adjacencyMatrixDS[noOfVertex][noOfVertex];
	int noOfEdgesInGraph;
	int sourceVertex,destinationVertex;
	string edgeName;
	cout << "No of edges in graph ?" << endl;
	cin >> noOfEdgesInGraph >> endl;

	for(int counter = 0;counter < noOfEdgesInGraph;counter++){
		cout << "source" << endl;
		scanf("%d",&sourceVertex);
		cout << "destination" << endl;
		scanf("%d",&destinationVertex);
		cout << "edge name" << endl;
		cin >> edgeName;
		adjacencyMatrixDS[sourceVertex][destinationVertex].edgeExists = true;
		adjacencyMatrixDS[destinationVertex][sourceVertex].edgeExists = true;
		adjacencyMatrixDS[sourceVertex][destinationVertex].edgeName = edgeName;
		adjacencyMatrixDS[destinationVertex][sourceVertex].edgeName = edgeName;
   	}
}

#endif /* ADJACENCYMATRIX_H_ */
