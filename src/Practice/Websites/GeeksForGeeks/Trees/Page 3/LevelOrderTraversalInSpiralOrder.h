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

#endif /* LEVELORDERTRAVERSALINSPIRALORDER_H_ */
