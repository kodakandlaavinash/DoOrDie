/*
 * UnionIntersectionOfNodes.h
 *
 *  Created on: May 10, 2013
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

#ifndef UNIONINTERSECTIONOFNODES_H_
#define UNIONINTERSECTIONOFNODES_H_

vector<int> * UnionIntersectionOfNodes(linkedListNode *list1,linkedListNode *list2){
	if(list1 == NULL && list2 == NULL){
		return NULL;
	}
	hash_map<int,int> occurenceMap;
	linkedListNode *crawler = list1;
	hash_map<int,int>::iterator itToOccurenceMap;
	vector<int> unionOfList,intersectionOfList;
	while(crawler != NULL){
		if((itToOccurenceMap = occurenceMap.find(crawler->value)) != occurenceMap.end()){
			occurenceMap[crawler->value]++;
		}else{
			unionOfList.push_back(crawler->value);
			occurenceMap.insert(pair<int,int>(crawler->value,1));
		}
		crawler = crawler->next;
	}

	crawler = list2;
	while(crawler != NULL){
		if((itToOccurenceMap = occurenceMap.find(crawler->value)) != occurenceMap.end()){
			if(itToOccurenceMap->second == 1){
				occurenceMap.erase(itToOccurenceMap);
			}else{
				occurenceMap[crawler->value]--;
			}
			intersectionOfList.push_back(crawler->value);
		}else{
			unionOfList.push_back(crawler->value);
			occurenceMap.insert(pair<int,int>(crawler->value,1));
		}
	}
}

vector<int> * UnionIntersectionON2(linkedListNode *list1,linkedListNode *list2){
	vector<int> unionOfLists,intersectionOfLists;

	linkedListNode *crawler1 = list1,*crawler2 = list2;
	int crawlerOfUnion;
	bool isFound;
	while(crawler1 != NULL){
		isFound = false;
		for(crawlerOfUnion = 0;crawlerOfUnion < unionOfLists.size();crawlerOfUnion++){
			if(unionOfLists[crawlerOfUnion] == crawler1->value){
				isFound = true;
				break;
			}
		}

		if(!isFound){
			unionOfLists.push_back(crawler1->value);
		}

		crawler2 = list2;
		isFound = false;
		while(crawler2 != NULL){
			if(crawler1->value == crawler2->value){
				isFound = true;
				break;
			}
		}
		if(isFound){
			intersectionOfLists.push_back(crawler1->value);
		}
		crawler1 = crawler1->next;
	}

	crawler2 = list2;
	while(crawler2 != NULL){
		isFound = true;
		for(crawlerOfUnion = 0;crawlerOfUnion < unionOfLists.size();crawlerOfUnion++){
			if(unionOfLists[crawlerOfUnion] == crawler2->value){
				isFound = false;
				break;
			}
		}
		if(!isFound){
			unionOfLists.push_back(crawler2->value);
		}
		crawler2 = crawler2->next;
	}
}

void ConstructAugumentedBSTIterative(augumentedTNode **ptr,int value){
	if(ptr == NULL){
		augumentedTNode *newNode = (augumentedTNode *)malloc(sizeof(augmentedTNode));
		newNode->value = value;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->helperVar = 1;
		*ptr = newNode;
	}else{
		augumentedTNode *crawler = *ptr;
		while(crawler != NULL || crawler->value== value){
			if(crawler->value > value){
				if(crawler->left != NULL){
					crawler = crawler->left;
				}else{
					break;
				}
			}else{
				if(crawler->right != NULL){
					crawler = crawler->right;
				}else{
					break;
				}
			}
		}

		if(crawler->value == value){
			crawler->helperVar += 1;
		}else{
			augumentedTNode *newNode = (augumentedTNode *)malloc(sizeof(augmentedTNode));
			newNode->value = value;
			newNode->left = NULL;
			newNode->right = NULL;
			newNode->helperVar = 1;

			if(crawler->value > value){
				crawler->left = newNode;
			}else{
				crawler->right = newNode;
			}
		}
	}
}

void GetUnionAndIntersectionUsingBST(augumentedTNode *ptr,vector<int> &unionOfLists,vector<int> &intersectionOfLists){
	if(ptr == NULL){
		return;
	}
	GetUnionAndIntersectionUsingBST(ptr->left,unionOfLists,intersectionOfLists);
	if(ptr->helperVar > 1){
		unionOfLists.push_back(ptr->value);
		intersectionOfLists.push_back(ptr->value);
	}else{
		unionOfLists.push_back(ptr->value);
	}
	GetUnionAndIntersectionUsingBST(ptr->right,unionOfLists,intersectionOfLists);
}

//Assuming there are unique values in the lists
vector<int> * UnionIntersectionOfLinkedListONLOGN(linkedListNode *list1,linkedListNode *list2){
	if(list1 == NULL && list2 == NULL){
		return NULL;
	}
	vector<int> unionIntersectionOfLists[2];
	vector<int> unionOfLists,intersectionOfLists;
	if(list1 == NULL || list2 == NULL){
		if(list1 != NULL){
			unionIntersectionOfLists[1]  = NULL;
			while(list1 != NULL){
				unionOfLists.push_back(list1->value);
				list1 = list1->next;
			}
			unionIntersectionOfLists[0] = unionOfLists;
		}else{
			unionIntersectionOfLists[1] = NULL;
			while(list2 != NULL){
				unionOfLists.push_back(list2->value);
				list2 = list2->next;
			}
		}
		return unionIntersectionOfLists;
	}
	augumentedTNode *rootBST;
	linkedListNode *crawler = list1;
	while(crawler != NULL){
		ConstructAugumentedBSTIterative(rootBST,crawler->value);
		crawler = crawler->next;
	}

	crawler = list2;
	while(crawler != NULL){
		ConstructAugumentedBSTIterative(rootBST,crawler->value);
		crawler = crawler->next;
	}

	GetUnionAndIntersectionUsingBST(rootBST,unionOfLists,intersectionOfLists);
}


#endif /* UNIONINTERSECTIONOFNODES_H_ */
