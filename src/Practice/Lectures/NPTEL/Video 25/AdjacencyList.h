/*
 * AdjacencyList.h
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

#ifndef ADJACENCYLIST_H_
#define ADJACENCYLIST_H_

struct adjacencyListDS{
	int adjacentVertex;
	int edgeName;
};

vector<vector<adjacencyListDS>> CreateAdjacencyListForUndirectedGraph(int noOfVertex){
	if(noOfVertex == 0){
		return;
	}
	vector<vector<adjacencyListDS>> adjacencyList;
	int noOfEdges,sourceVertexIndex,destinationVertexIndex;
	cout << "No of edges in graph" << endl;
	cin >> noOfEdges >> endl;
	string edgeName;
	for(int counter =0;counter < noOfEdges;counter++){
		cout << "Source vertex index" << endl;
		cin >> sourceVertexIndex;
		cout << "Destination vertex index" << endl;
		cin >> destinationVertexIndex;
		cout << "Enter edge name" << endl;
		cin >> edgeName;
		adjacencyListDS *adjacencyListNode1 = (adjacencyListDS *)malloc(sizeof(adjacencyListDS));
		adjacencyListNode1->adjacentVertex = destinationVertexIndex;
		adjacencyListNode1->edgeName = edgeName;

		adjacencyListDS *adjacencyListNode2 = (adjacencyListDS *)malloc(sizeof(adjacencyListDS));
		adjacencyListNode2->adjacentVertex = sourceVertexIndex;
		adjacencyListNode2->edgeName = edgeName;
		adjacencyList[sourceVertexIndex].push_back(adjacencyListNode1);
		adjacencyList[destinationVertexIndex].push_back(adjacencyListNode2);
	}

	return adjacencyList;
}


vector<vector<adjacencyListDS>> CreateAdjacencyListForDirectedGraph(int noOfVertex){
	if(noOfVertex == 0){
		return NULL;
	}
	vector<vector<adjacencyListDS>> adjacencyList;
	int noOfEdges,sourceVertexIndex,destinationVertexIndex;
	cout << "No of edges in graph" << endl;
	cin >> noOfEdges >> endl;
	string edgeName;
	for(int counter =0;counter < noOfEdges;counter++){
		cout << "Source vertex index" << endl;
		cin >> sourceVertexIndex;
		cout << "Destination vertex index" << endl;
		cin >> destinationVertexIndex;
		cout << "Enter edge name" << endl;
		cin >> edgeName;
		adjacencyListDS *adjacencyListNode1 = (adjacencyListDS *)malloc(sizeof(adjacencyListDS));
		adjacencyListNode1->adjacentVertex = destinationVertexIndex;
		adjacencyListNode1->edgeName = edgeName;


		adjacencyList[sourceVertexIndex].push_back(adjacencyListNode1);
		adjacencyList[destinationVertexIndex].push_back(adjacencyListNode2);
	}
	return adjacencyList;
}

#endif /* ADJACENCYLIST_H_ */

