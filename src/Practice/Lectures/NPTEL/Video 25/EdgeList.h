/*
 * EdjeList.h
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

#ifndef EDGELIST_H_
#define EDGELIST_H_

struct edgeListDS{
	int startVertex;
	int endVertex;
	string edgeName;
};

vector<edgeListDS> CreateEdgeList(int noOfEdges){
	if(noOfEdges == 0){
		return NULL;
	}
	int counter =0,sourceVertex,destinationVertex;
	string edgeName;
	vector<edgeListDS> edgeList;
 	for(counter =0;counter <noOfEdges;counter++){
		cout << "Enter edge name" << endl;
		cin >> edgeName;
		cout << "Source vertex index" << endl;
		cin >> sourceVertex;
		cout << "Destination vertex index" << endl;
		cin >> destinationVertex;
		edgeListDS *newNode = (edgeListDS *)malloc(sizeof(edgeListDS));
		newNode->edgeName = edgeName;
		newNode->startVertex = sourceVertex;
		newNode->endVertex = destinationVertex;
		edgeList.push_back(newNode);
	}
 	return edgeList;
}



#endif /* EDJELIST_H_ */
