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

void PerformADFSInDirectedGraph(vector<vector<adjacencyListDS>> adjacencyList,int source,vector<int> &arrivalTimes,vector<int> &departureTimes){
	if(adjacencyList.size() == 0){
		return;
	}
	static int timeCounter = -1;
	vector<adjacencyListDS> neighbouringVertices;

	for(int counter =0;counter < adjacencyList.size();counter++){
		if(arrivalTimes[adjacencyList[source][counter]] == -1){
			arrivalTimes[adjacencyList[source][counter]] = ++timeCounter;
			PerformADFSInDirectedGraph(adjacencyList,adjacencyList[source][counter],arrivalTimes,departureTimes);
		}
	}
	departureTimes[source] = ++timeCounter;
}

#endif /* DFSINDIRECTEDGRAPH_H_ */
