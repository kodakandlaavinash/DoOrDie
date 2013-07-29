/*
 * LevelOrderTraversalInSpiralOrder.h
 *
 *  Created on: Apr 23, 2013
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

#ifndef LEVELORDERTRAVERSALINSPIRALORDER_H_
#define LEVELORDERTRAVERSALINSPIRALORDER_H_

/*
 * Tested
 */
void PrintTreeInSpiralOrder(tNode *ptr){
	stack<tNode *> leftToRight;
	stack<tNode *> rightToLeft;
	leftToRight.push(ptr);
	tNode *currentElement;
	int count=1;
	while(1){
		printf("\nLevel %d\n",count);
		printf("-----------\n");
		while(!leftToRight.empty()){
			currentElement = leftToRight.top();
			printf("%d\t",currentElement->value);
			if(currentElement->left != NULL){
				rightToLeft.push(currentElement->left);
			}
			if(currentElement->right != NULL){
				rightToLeft.push(currentElement->right);
			}
			leftToRight.pop();
		}
		count++;
		printf("\n");
		printf("\nLevel %d\n",count);
		printf("-----------\n");
		while(!rightToLeft.empty()){
			currentElement = rightToLeft.top();
			printf("%d\t",currentElement->value);
			if(currentElement->left != NULL){
				leftToRight.push(currentElement->right);
			}
			if(currentElement->right != NULL){
				leftToRight.push(currentElement->left);
			}
			rightToLeft.pop();
		}
		printf("\n");
		count++;
		if(leftToRight.empty() && rightToLeft.empty()){
			break;
		}
	}
}

void LevelOrderTraversalInSpiralOrder(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	hashmapForTreeDS *hashmapTreeDS = GetHashMapForTreeDS(ptr);
	int maxLevel = GetMaxLevelFromHashMapForATree(hashmapTreeDS->rankNodeMap);
	bool shouldPrintReverse;
	hash_map<int,tNode *>::iterator *itToRankNodeMap;
	for(int levelCounter = 0;levelCounter <= maxLevel;levelCounter){
		if(shouldPrintReverse){
			for(int printerCounter = pow(2,levelCounter)- 2 + pow(2,levelCounter);printerCounter>=pow(2,levelCounter)-1;printerCounter--){
				if((itToRankNodeMap = hashmapTreeDS->rankNodeMap.find(printerCounter)) != hashmapTreeDS->rankNodeMap.end()){
					printf("%d",(*itToRankNodeMap)->second);
				}
			}
		}else{
			for(int printerCounter = pow(2,levelCounter)-1;printerCounter > pow(2,levelCounter)- 1 + pow(2,levelCounter);printerCounter++){
				printf("%d",(*itToRankNodeMap)->second);
			}
		}
		shouldPrintReverse = !shouldPrintReverse;
	}
}

#endif /* LEVELORDERTRAVERSALINSPIRALORDER_H_ */
