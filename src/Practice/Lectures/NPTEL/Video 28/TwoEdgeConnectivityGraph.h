/*
 * TwoEdgeConnectivityGraph.h
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

#ifndef TWOEDGECONNECTIVITYGRAPH_H_
#define TWOEDGECONNECTIVITYGRAPH_H_

struct adjacencyListDS{
	int adjacentVertex;
	int edgeName;
};

bool isGraphTwoEdgeConnected(vector<vector<adjacencyListDS>> adjacencyList){
	if(adjacencyList.size() == 0){
		return false;
	}


}

#endif /* TWOEDGECONNECTIVITYGRAPH_H_ */
