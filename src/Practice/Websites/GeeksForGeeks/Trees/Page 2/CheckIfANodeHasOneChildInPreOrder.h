/*
 * CheckIfANodeHasOneChildInPreOrder.h
 *
 *  Created on: May 14, 2013
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

#ifndef CHECKIFANODEHASONECHILDINPREORDER_H_
#define CHECKIFANODEHASONECHILDINPREORDER_H_

bool CheckIfNodesHasOnlyOneChildInPreOrder(int preOrderTraversalNodes[],int sizeOfPreOrder){
	if(sizeOfPreOrder == 0){
		return true;
	}

	int outerCrawler = 0;
	int innerCrawler,difference;
	for(outerCrawler =0;outerCrawler < sizeOfPreOrder-1;outerCrawler++){
		innerCrawler = outerCrawler+1;
		difference = preOrderTraversalNodes[outerCrawler] - preOrderTraversalNodes[innerCrawler];
		for(innerCrawler = innerCrawler+1;innerCrawler < sizeOfPreOrder;innerCrawler++){
			if(difference * (preOrderTraversalNodes[outerCrawler] - preOrderTraversalNodes[innerCrawler])<0){
				return false;
			}
		}
	}
	return true;
}

bool CheckIfNodesHasOnlyOneChildInPreOrderUsingMaxMin(int preOrderTraversalNodes[],int sizeOfPreOrder){
	if(sizeOfPreOrder == 0){
		return true;
	}
	int max,min,temp;
	max = preOrderTraversalNodes[sizeOfPreOrder-1];
	min = preOrderTraversalNodes[sizeOfPreOrder-2];
	if(max < min){
		temp = max;
		max = min;
		min = temp;
	}

	for(int crawler = sizeOfPreOrder-3;crawler >=0;crawler--){
		if(preOrderTraversalNodes[crawler] < min){
			min = preOrderTraversalNodes[crawler];
		}else{
			if(preOrderTraversalNodes[crawler] > max){
				max = preOrderTraversalNodes[crawler];
			}else{
				return false;
			}
		}
	}
	return true;
}

bool CheckIfANodesHasOneChildSuccessorDifference(int preOrderNodes[],int sizeOfArray){
	if(sizeOfArray == 0){
		return true;
	}
}

#endif /* CHECKIFANODEHASONECHILDINPREORDER_H_ */
