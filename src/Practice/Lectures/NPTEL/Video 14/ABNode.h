/*
 * ABNode.h
 *
 *  Created on: Jun 3, 2013
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
#define A 2
#define B 4
#define LAST_NODE 0
#define LAST_PTR 0
//int main(){
//	return -1;
//}

struct ABNode{
	int value[B-1];
	ABNode *ptrToParent;
	ABNode *ptrToChildren[B] = {NULL};
	int noOfNodes = 0;
};
#ifndef ABNODE_H_
#define ABNODE_H_

ABNode *SearchForNodeForInsertion(ABNode *ptr,int value){
	if(ptr == NULL){
		return NULL;
	}
	ABNode *crawler = ptr;
	int indexCrawler = 1;
	while(1){
		if(ptr->value[0] > value){
			//less than the first child
			if(ptr->ptrToChildren[0] == NULL){
				return ptr;
			}
			ptr = ptr->ptrToChildren[0];
		}else{
			if(ptr->value[LAST_NODE] < value){
				if(ptr->ptrToChildren[LAST_PTR] == NULL){
					return ptr;
				}
				ptr = ptr->ptrToChildren[LAST_PTR];
			}else{
				for(indexCrawler = 0;indexCrawler < LAST_NODE-1;indexCrawler){
					if(ptr->value[indexCrawler] > value && value < ptr->value[indexCrawler+1]){
						if(ptr->ptrToChildren[indexCrawler+1] == NULL){
							return ptr->ptrToChildren[indexCrawler+1];
						}else{
							ptr = ptr->ptrToChildren[indexCrawler+1];
							break;
						}
					}
				}
			}
		}
	}
}

ABNode *SplitTheNode(ABNode *ptr,int value){
	ABNode *leftSplitNode = (ABNode *)malloc(sizeof(ABNode));
	ABNode *rightSplitNode = (ABNode *)malloc(sizeof(ABNode));

	int totalNoOfElements = (ptr->noOfNodes + 1);
	int noOfElementsInEachNode  = totalNoOfElements/2; // That one node is the newly added node
	int leftCrawler = -1,rightCrawler = -1;
	bool isNewValueInserted = false;
	for(int crawler=0;crawler < totalNoOfElements;){
		if(!isNewValueInserted){
			if(value < ptr->value[crawler]){
				if(leftCrawler < noOfElementsInEachNode){
					leftSplitNode->value[++leftCrawler] = ptr->value[crawler];
					leftSplitNode->noOfNodes += 1;
				}else{
					rightSplitNode->value[++rightCrawler] = ptr->value[crawler];
					rightSplitNode->noOfNodes += 1;
				}
				isNewValueInserted =  !isNewValueInserted;
			}
		}else{
			if(leftCrawler < noOfElementsInEachNode){
				leftSplitNode->value[++leftCrawler] = ptr->value[crawler];
				leftSplitNode->noOfNodes += 1;
				crawler++;
			}else{
				rightSplitNode->value[++rightCrawler] = ptr->value[crawler];
				rightSplitNode->noOfNodes += 1;
				crawler++;
			}
		}
	}
	ABNode newSplitNodes[2] = {leftSplitNode,rightSplitNode};
	return newSplitNodes;
}

int InsertAtAppropriatePosition(ABNode *ptr,int value){
	for(int crawler = ptr->noOfNodes - 1;crawler >= 0 ;crawler--){
		if(ptr->value[crawler] < value){
			ptr->value[crawler] = value;
			return crawler;
		}
		ptr->value[crawler+1] = ptr->value[crawler];
	}
}


void CreateABNode(ABNode **ptr,int value){
	ABNode *crawler = *ptr;

	if(crawler == NULL){
		//ABNode is NULL
		ABNode *newNode = (ABNode *)malloc(sizeof(ABNode));
		newNode->value[0] = value;
		newNode->ptrToParent = NULL;
		newNode->noOfNodes += 1;
		*ptr = newNode;
		return;
	}else{
		//Consists of some nodes
		ABNode *ptrToKey = SearchForNodeForInsertion(crawler,value);
		if(ptrToKey->noOfNodes == B-1){
			if(ptrToKey->ptrToParent == NULL){
				//Node is the root node
			}else{

				int lastIndexWhereValueHasBeenInserted;
				int valueToBeUpgradedToParent;
				if(ptrToKey->ptrToParent->noOfNodes == B-1){
					//Even the parent is Full
					while(ptrToKey->ptrToParent->noOfNodes != B-1 || ptrToKey->ptrToParent == NULL){ // Either the node is the root node or the no of nodes in the node is less than B
						//Splitting the child
						ABNode *childSplittedNodes[2];
						ABNode *parentSplittedNodes[2];
						ABNode *parentPTR = ptrToKey->ptrToParent;
						ABNode *grandParent;
						/**
						 * Since the child is full we will split the child Node
						 */
						childSplittedNodes = SplitTheNode(ptrToKey,value);
						lastIndexWhereValueHasBeenInserted = childSplittedNodes[0]->noOfNodes - 1;
						valueToBeUpgradedToParent = childSplittedNodes[0]->ptrToChildren[lastIndexWhereValueHasBeenInserted];
						childSplittedNodes[0]->value[lastIndexWhereValueHasBeenInserted] = INT_MIN;
						childSplittedNodes[0]->noOfNodes -= 1;

						/**
						 * Since the parent is full we will split the parent node
						 */

						parentSplittedNodes = SplitTheNode(parentPTR,valueToBeUpgradedToParent);
						lastIndexWhereValueHasBeenInserted = parentSplittedNodes[0]->noOfNodes - 1;
						valueToBeUpgradedToParent = parentSplittedNodes[0]->ptrToChildren[lastIndexWhereValueHasBeenInserted];
						parentSplittedNodes[0]->value[lastIndexWhereValueHasBeenInserted] = INT_MIN;
						parentSplittedNodes[0]->noOfNodes -= 1;

						//Rearranging the ptr of the splitted nodes of parent and children
						/***********************************************/
						/* 				SHOULD BE CODED				   */
						/***********************************************/
						ptrToKey = parentSplittedNodes[0]->ptrToParent;
						value = valueToBeUpgradedToParent;
					}
				}else{
					/**
					 * We are creating two new nodes
					 * and not making use of the old one because
					 * we need the pointer reference for the later use
					 *
					 * ie to rearrange the nodes in the tree
					 */
					ABNode *splittedNodes[2];
					splittedNodes = SplitTheNode(ptrToKey,value);
					lastIndexWhereValueHasBeenInserted = splittedNodes[0]->noOfNodes - 1;
					valueToBeUpgradedToParent = splittedNodes[0]->ptrToChildren[lastIndexWhereValueHasBeenInserted];
					splittedNodes[0]->ptrToChildren[lastIndexWhereValueHasBeenInserted] = INT_MIN;
					splittedNodes[0]->noOfNodes -= 1;

					int indexInParentWhereNodeHasBeenInserted = InsertAtAppropriatePosition(ptrToKey->ptrToParent,valueToBeUpgradedToParent);
					ABNode *parentPTR = ptrToKey->ptrToParent;
					parentPTR->ptrToChildren[indexInParentWhereNodeHasBeenInserted] = splittedNodes[0];
					parentPTR->ptrToChildren[indexInParentWhereNodeHasBeenInserted+1] = splittedNodes[1];
					splittedNodes[0]->ptrToParent = parentPTR;
					splittedNodes[1]->ptrToParent = parentPTR;

					ptrToKey->ptrToParent = NULL;
					free(ptrToKey);
				}
			}
		}else{
			InsertAtAppropriatePosition(ptr,value);
		}
	}
}

ABNode *SearchForANodeInABTree(ABNode *ptr,int value){
	if(ptr == NULL){
		return NULL;
	}
	//Checking whether the value is less than first node
	if(ptr->value[0] > value){
		if(ptr->ptrToChildren[0] == NULL){
			return NULL;
		}
		return SearchForANodeInABTree(ptr->ptrToChildren[0],value);
	}

	//Checking whether the value is greater than last node
	if(ptr->value[ptr->noOfNodes - 1] < value){
		if(ptr->ptrToChildren[ptr->noOfNodes] == NULL){
			return NULL;
		}
		return SearchForANodeInABTree(ptr->ptrToChildren[ptr->noOfNodes],value);
	}

	//Checking whether it lies in the nodes or is in between the nodes
	for(int crawler =0;crawler < ptr->noOfNodes;crawler++){
		if(ptr->value[crawler] == value){
			return ptr;
		}else{
			if(crawler != ptr->noOfNodes - 1){
				if(ptr->value[crawler] > value && ptr->value[crawler+1]){
					if(ptr->ptrToChildren[crawler+1] == NULL){
						return NULL;
					}else{
						return SearchForANodeInABTree(ptr->ptrToChildren[crawler+1],value);
					}
				}
			}
		}
	}

	return NULL;
}

int GetIndexOfValueInNodeForGivenValue(ABNode *ptr,int value){
	for(int crawler = 0;crawler < ptr->noOfNodes;crawler++){
		if(ptr->value[crawler] == value){
			return crawler;
		}
	}
	return INT_MIN;
}

int GetChildIndexOfChildPTR(ABNode *parentPTR,ABNode *childPTR){
	for(int crawler=0;crawler < parentPTR->noOfNodes;crawler++){
		if(parentPTR->ptrToChildren[crawler] == childPTR){
			return crawler;
		}
	}
	return INT_MIN;
}

ABNode *GetPredessecorOfAValue(ABNode *ptr){
	if(ptr == NULL){
		return NULL;
	}
	if(ptr->ptrToChildren[ptr->noOfNodes] == NULL){
		return ptr;
	}else{
		return GetPredessecorOfAValue(ptr->ptrToChildren[ptr->noOfNodes]);
	}
}

ABNode *MergeWithSibling(ABNode *ptrToKey,ABNode *ptrToSibling,int valueToBeDeleted){
	if(ptrToKey == NULL || ptrToSibling == NULL){
		return NULL;
	}
	ABNode *mergedNode =(ABNode *)malloc(sizeof(ABNode));
	int crawlerForInsertionInMergedNode = -1;
	for(int crawler = 0;crawler < ptrToSibling->noOfNodes;crawler++){
		mergedNode->value[++crawlerForInsertionInMergedNode] = ptrToSibling->value[crawler];
	}
	for(int crawler =0;crawler < ptrToKey->noOfNodes;crawler++){
		if(ptrToKey->value[crawler] == valueToBeDeleted){
			continue;
		}
		mergedNode->value[++crawlerForInsertionInMergedNode] = ptrToKey->value[crawler];
	}
	return mergedNode;
}

void DeleteANodeInABTree(ABNode **ptr,int value){
	if(*ptr  == NULL){
		//Tree is empty
		return NULL;
	}
	ABNode *nodeInWhichValueIsPresent = SearchForANodeInABTree(*ptr,value);
	if(nodeInWhichValueIsPresent == NULL){
		cout << "Node with given value doesn't exists in the ABTree" << endl;
		return;
	}

	int indexOfValueOfNode  = GetIndexOfValueInNodeForGivenValue(nodeInWhichValueIsPresent,value);

	if(nodeInWhichValueIsPresent->ptrToChildren[indexOfValueOfNode] == NULL){
		//This is a leaf Node
		if(nodeInWhichValueIsPresent->noOfNodes - 1 > A-1){
			// Have sufficient nodes in the ABTree so can safely delete the node
			for(int crawler = indexOfValueOfNode;crawler < nodeInWhichValueIsPresent->noOfNodes-1;crawler++){
				nodeInWhichValueIsPresent->value[crawler] = nodeInWhichValueIsPresent->value[crawler+1];
			}
			nodeInWhichValueIsPresent->value[nodeInWhichValueIsPresent->noOfNodes-1] = INT_MIN;
			nodeInWhichValueIsPresent->noOfNodes -= 1;
		}else{
			// Have less number of nodes than the required nodes
			if(1){
				// Have enough number of nodes in the siblings
				ABNode *ptrToParentForKeyNode = nodeInWhichValueIsPresent->ptrToParent;
				int indexOfPTROfKeyNode = GetChildIndexOfChildPTR(nodeInWhichValueIsPresent->ptrToParent,nodeInWhichValueIsPresent);
				ABNode *ptrToSibling = ptrToParentForKeyNode->ptrToChildren[indexOfPTROfKeyNode-1];
				int valueToBeMovedToKeyNode  = ptrToParentForKeyNode->value[indexOfPTROfKeyNode-1];
				ptrToParentForKeyNode->value[indexOfPTROfKeyNode-1] = ptrToSibling->value[ptrToSibling->noOfNodes - 1];
				ptrToSibling->value[ptrToSibling->noOfNodes - 1] = INT_MIN;
				ptrToSibling->noOfNodes -= 1;

				for(int crawler = nodeInWhichValueIsPresent->noOfNodes - 1;crawler > 0;crawler++){
					nodeInWhichValueIsPresent->value[crawler] = nodeInWhichValueIsPresent->value[crawler-1];
				}

				nodeInWhichValueIsPresent->value[0] = valueToBeMovedToKeyNode;
				nodeInWhichValueIsPresent->noOfNodes += 1;
				return;
			}else{
				// Even the sibling the nodes are full
				ABNode *ptrToParentForKeyNode = nodeInWhichValueIsPresent->ptrToParent;
				ABNode *grandParent = ptrToParentForKeyNode->ptrToParent;
				if(grandParent == NULL){
					//parent is NULL
				}else{
					if(ptrToParentForKeyNode->noOfNodes - 1 > A-1){
						//Parent Has Sufficient no of nodes
						int indexOfPTROfKeyNode = GetChildIndexOfChildPTR(ptrToParentForKeyNode,nodeInWhichValueIsPresent);
						ABNode *mergedNode = MergeNodesInABTree(nodeInWhichValueIsPresent,ptrToParentForKeyNode->ptrToChildren[indexOfPTROfKeyNode-1]);

					}else{
						//Even Parent doesnt have sufficient node of nodes
					}
				}
			}
		}
	}else{
		//This is not a leaf Node

	}
}

#endif /* ABNODE_H_ */
