/*
 * PopulateInorderSuccessor.h
 *
 *  Created on: Apr 30, 2013
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

#ifndef POPULATEINORDERSUCCESSOR_H_
#define POPULATEINORDERSUCCESSOR_H_

void PopulateInorderSuccessor(inOrderSuccessor *ptr,inOrderSuccessor **successor = NULL){
	if(ptr == NULL){
		return;
	}
	PopulateInorderSuccessor(ptr->right);
	ptr->successor = *successor;
	*successor = ptr;
	PopulateInorderSuccessor(ptr->left);
}

void GetSuccessorNodesInInOrder(inOrderSuccessor *ptr,vector<inOrderSuccessor *> &auxSpace){
	if(ptr == NULL){
		return;
	}
	GetSuccessorNodesInInOrder(ptr->left,auxSpace);
	auxSpace.push_back(ptr);
	GetSuccessorNodesInInOrder(ptr->right,auxSpace);
}


void PopulateInOrderSuccessor(inOrderSuccessor *ptr){
	vector<inOrderSuccessor *> nodesInInorder;
	GetSuccessorNodesInInOrder(ptr,&nodesInInorder);
	vector<inOrderSuccessor *>::iterator itToNodesInInorder;
	for( itToNodesInInorder = nodesInInorder.begin();itToNodesInInorder+1 != nodesInInorder.end();itToNodesInInorder++){
		(*itToNodesInInorder)->successor = *(itToNodesInInorder+1);
	}
	(*itToNodesInInorder)->successor = NULL;
}

void PopulateInOrderSuccessorAuxStackSpace(inOrderSuccessor *ptr){
	if(ptr == NULL){
		return;
	}
	stack<inOrderSuccessor *> auxSpaceForInOrder;
	auxSpaceForInOrder.push(ptr);
	inOrderSuccessor *prevNode = NULL,*currentNode;
	while(!auxSpaceForInOrder.empty()){
		if(auxSpaceForInOrder.top()->right != NULL){
			auxSpaceForInOrder.push(auxSpaceForInOrder.top()->right);
		}else{
			currentNode = auxSpaceForInOrder.top();
			currentNode->inOrderSuccessor = prevNode;
			prevNode = currentNode;
			auxSpaceForInOrder.pop();
			if(currentNode->left != NULL){
				auxSpaceForInOrder.push(currentNode->left);
			}
		}
	}
}

#endif /* POPULATEINORDERSUCCESSOR_H_ */
