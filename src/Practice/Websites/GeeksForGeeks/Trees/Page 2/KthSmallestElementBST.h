/*
 * KthSmallestElement.h
 *
 *  Created on: Apr 27, 2013
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

#ifndef KTHSMALLESTELEMENT_H_
#define KTHSMALLESTELEMENT_H_

int KthSmallestElementInBST(tNode *ptr,int kValue){
	if(ptr == NULL){
		return INT_MIN;
	}
	vector<int> inOrderOfNodes;
	GetInOrderTraversalNodes(ptr,inOrderOfNodes);

	return inOrderOfNodes[kValue-1];
 }

int KthSmallestElementBSTInOrder(tNode *ptr,int kValue,int &nodeIndexInInOrder){
	if(ptr == NULL){
		return INT_MIN;
	}
	if(kValue == nodeIndexInInOrder){
		return ptr->value;
	}
	int leftValue = KthSmallestElementBSTInOrder(ptr->left,kValue,nodeIndexInInOrder);
	if(leftValue != INT_MIN){
		return leftValue;
	}
	nodeIndexInInOrder++;
	int rightValue = KthSmallestElementBSTInOrder(ptr->right,kValue,nodeIndexInInOrder);
	if(rightValue != INT_MIN){
		return rightValue;
	}else{
		return INT_MIN;
	}
}

void FillAugTreeWithIndexInTree(augumentedTNode *ptr,int &counter){
	if(ptr == NULL){
		return;
	}
	FillAugTreeWithIndexInTree(ptr->left,counter);
	counter++;
	ptr->helperVar=counter;
	FillAugTreeWithIndexInTree(ptr->right,counter);
}

int KthSmallestElementBST(augumentedTNode *ptr,int kValue){
	if(ptr == NULL){
		return INT_MIN;
	}
	if(ptr->helperVar == kValue){
		return ptr->value;
	}
	int leftValue = KthSmallestElementBST(ptr->left,kValue);
	if(leftValue != INT_MIN){
		return leftValue;
	}
	int rightValue = KthSmallestElementBST(ptr->right,kValue);
	if(rightValue != INT_MIN){
		return INT_MIN;
	}else{
		return rightValue;
	}
}

int KthSmallestElementBSTAugStructDriver(augumentedTNode *ptr,int kValue){
	if(ptr == NULL){
		return INT_MIN;
	}


}

int KthSmallestElementInorderStack(tNode *ptr,int kValue){
	if(ptr == NULL){
		return INT_MIN;
	}
	tNode *crawler = ptr;
	stack<tNode *> auxSpace;
	auxSpace.push(ptr);
	int counter = 0;
	while(!auxSpace.empty()){
		crawler = auxSpace.top();
		if(crawler->left != NULL){
			auxSpace.push(crawler->left);
		}else{
			counter++;
			if(counter == kValue){
				return;
			}
			if(crawler->right != NULL){
				auxSpace.push(crawler->right);
			}else{
				auxSpace.pop();
			}
		}
	}

}

#endif /* KTHSMALLESTELEMENT_H_ */
