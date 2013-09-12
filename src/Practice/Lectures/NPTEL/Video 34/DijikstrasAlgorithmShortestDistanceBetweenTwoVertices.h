/*
 * DijistrasAlgorithmShortestDistanceBetweenTwoVertices.h
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

#ifndef DIJISTRASALGORITHMSHORTESTDISTANCEBETWEENTWOVERTICES_H_
#define DIJISTRASALGORITHMSHORTESTDISTANCEBETWEENTWOVERTICES_H_

struct adjacencyListNodeDS{
	int nodeIndex;
	adjacencyListNodeDS *next;
};

int ShortestPathBetweenTwoVertices(vector<vector<adjacencyListNodeDS *>> adjacencyList,int sourceNodeIndex,int targetNodeIndex){
	if(adjacencyList == NULL || adjacencyList.size() == 0){
		return INT_MAX;
	}

}

#endif /* DIJISTRASALGORITHMSHORTESTDISTANCEBETWEENTWOVERTICES_H_ */
