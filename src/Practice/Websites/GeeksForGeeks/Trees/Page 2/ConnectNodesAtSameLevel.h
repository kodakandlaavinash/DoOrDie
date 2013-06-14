/*
 * ConnectNodesAtSameLevel.h
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

#ifndef CONNECTNODESATSAMELEVEL_H_
#define CONNECTNODESATSAMELEVEL_H_

void ConnectNodesAtSameLevel(nextRightTNode *ptr){
	if(ptr == NULL){
		return;
	}
	queue<nextRightTNode *> auxSpace;
	nextRightTNode *endOfLevelIndicator = (nextRightTNode *)malloc(sizeof(nextRightTNode));
	endOfLevelIndicator->value = INT_MAX;
	endOfLevelIndicator->left = NULL;
	endOfLevelIndicator->right = NULL;

	auxSpace.push(ptr);
	auxSpace.push(endOfLevelIndicator);
	nextRightTNode *currentNode;
	nextRightTNode *nextNode;
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		auxSpace.pop();
		nextNode = auxSpace.front();
		if(isEndOfLevelIndicator(nextNode)){
			currentNode->nextRight = NULL;
		}else{
			currentNode->nextRight = nextNode;
		}
		if(isEndOfLevelIndicator(currentNode)){
			if(auxSpace.size() > 1){
				auxSpace.push(endOfLevelIndicator);
			}else{
				break;
			}
		}
		if(currentNode->left != NULL){
			auxSpace.push(currentNode->left);
		}
		if(currentNode->right != NULL){
			auxSpace.push(currentNode->right);
		}
	}
}

void ConnectNodesInPreOrderCompleteTreeDriver(nextRightTNode *ptr){
	if(ptr == NULL){
		return;
	}
	ptr->nextRight = NULL;
}

void ConnectNodesInPreOrderCompleteTree(nextRightTNode *ptr){
	if(ptr == NULL){
		return;
	}

	if(ptr->left != NULL){
		ptr->left->nextRight = ptr->right;
	}

	if(ptr->right != NULL){
		ptr->right->nextRight = (ptr->nextRight != NULL)?ptr->nextRight->left:NULL;
	}

	ConnectNodesInPreOrderCompleteTree(ptr->left);
	ConnectNodesInPreOrderCompleteTree(ptr->right);

}

nextRightTNode *GetNextRightPtr(nextRightTNode *ptr){
	while(ptr != NULL){
		if(ptr->left != NULL){
			return ptr->left;
		}else{
			if(ptr->right != NULL){
				return ptr->right;
			}
		}
		ptr = ptr->nextRight;
	}
	return NULL;
}

void ConnectNodesInAnyBinaryTree(nextRightTNode *ptr){
	if(ptr == NULL){
		return;
	}

	if(ptr->nextRight != NULL){
		ConnectNodesInAnyBinaryTree(ptr->nextRight);
	}

	if(ptr->left != NULL){
		if(ptr->right != NULL){
			ptr->left->nextRight = ptr->right;
			ptr->right->nextRight = GetNextRightPtr(ptr);
		}else{
			ptr->left->nextRight = GetNextRightPtr(ptr);
		}
		ConnectNodesInAnyBinaryTree(ptr->left);
	}else{
		if(ptr->right != NULL){
			ptr->right = GetNextRightPtr(ptr);
			ConnectNodesInAnyBinaryTree(ptr->right);
		}else{
			ConnectNodesInAnyBinaryTree(GetNextRightPtr(ptr));
		}
	}
}


void ConnectNodesInLevelIteratively(nextRightTNode *ptr){
	if(ptr == NULL){
		return;
	}
	ptr->nextRight = NULL;

	while(ptr != NULL){
		nextRightTNode *crawler = ptr;
		while(crawler != NULL){
			if(crawler->left != NULL){
				if(crawler->right != NULL){
					crawler->left->nextRight = crawler->right;
				}else{
					crawler->left->nextRight = GetNextRightPtr(crawler);
				}
			}
			if(crawler->right != NULL){
				crawler->right = GetNextRightPtr(crawler);
			}
			crawler = crawler->nextRight;
		}

		if(ptr->left != NULL){
			ptr = ptr->left;
		}else{
			if(ptr->right != NULL){
				ptr = ptr->right;
			}else{
				ptr =GetNextRightPtr(ptr);
			}
		}
	}
}

#endif /* CONNECTNODESATSAMELEVEL_H_ */
