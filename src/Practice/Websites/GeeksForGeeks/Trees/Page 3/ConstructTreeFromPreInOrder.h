/*
 * ConstructTreeFromPreInOrder.h
 *
 *  Created on: Apr 24, 2013
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

#ifndef CONSTRUCTTREEFROMPREINORDER_H_
#define CONSTRUCTTREEFROMPREINORDER_H_

int FindIndexOfNodesInInOrder(int inOrder[],int startInOrder,int endInOrder,int key){
	for(int crawler=startInOrder;crawler <= endInOrder;crawler++){
		if(inOrder[crawler] == key){
			return crawler;
		}
	}
}

void ConstructTreeUsingPreInOrder(int preOrder[],int inOrder[],int startInOrder,int endInOrder,int startPreOrder,int endPreOrder,tNode **ptr){
	if(startInOrder > endInOrder){
		return;
	}
	tNode *newNode;
	newNode = (tNode *)malloc(sizeof(tNodes));
	newNode->value = preOrder[startPreOrder];
	*ptr = newNode;

	int indexInInorder = FindIndexOfNodesInInOrder(inOrder,startInOrder,endInOrder,preOrder[startPreOrder]);
	int difference = indexInInorder - startInOrder;
	ConstructTreeUsingPreInOrder(preOrder,inOrder,startInOrder,indexInInorder-1,startPreOrder+1,startPreOrder+difference,ptr->left);
	ConstructTreeUsingPreInOrder(preOrder,inOrder,indexInInorder+1,endInOrder,startPreOrder+difference+1,endPreOrder,ptr->right);

}


#endif /* CONSTRUCTTREEFROMPREINORDER_H_ */
