/*
 * PriorityQueues.h
 *
 *  Created on: Jun 10, 2013
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

#ifndef PRIORITYQUEUES_H_
#define PRIORITYQUEUES_H_

void ReorderVectorToFormHeap(vector<int> &userInput){
	if(userInput.size() == 0 || userInput.size() == 1){
		return;
	}
}

void ReorderVectorForNewlyInsertedElement(vector<int> &userInput,int indexOfLastInsertedElement){
	if(indexOfLastInsertedElement == 0){
		return;
	}
	int indexOfParentNode;
	int tempForSwap;
	do{
		indexOfParentNode = indexOfLastInsertedElement/2;
		if(userInput[indexOfParentNode] < userInput[indexOfLastInsertedElement]){
			return;
		}
		tempForSwap = userInput[indexOfParentNode];
		userInput[indexOfParentNode] = userInput[indexOfLastInsertedElement];
		userInput[indexOfLastInsertedElement] = tempForSwap;
		indexOfLastInsertedElement = indexOfParentNode;
		indexOfParentNode = indexOfLastInsertedElement/2;
	}while(indexOfParentNode != 0);
	return;
}

void CreatePriorityQueue(vector<int> heap,int userInput){
	heap.push_back(userInput);
	ReorderVectorForNewlyInsertedElement(heap,heap.size()-1);
}

int FindTheLastLevelInPriorityQueue(vector<int> userInput){
	if(userInput.size() == 0){
		return INT_MIN;
	}
	int level = -1;
	while(++level>=0){
		if(userInput < pow(2,level)){
			return level-1;
		}
	}
}

int SumOfGP(int level){
	return (2^level - 1);
}

vector<int> CreatePriorityQueueBottomUp(int userInput[]){
	if(userInput == null){
		return NULL;
	}
	vector<int> userInputInVectorFormat(userInput);
	int lastLevel = FindTheLastLevelInPriorityQueue(userInputInVectorFormat);
	int counter,tempForSwap;
	int levelCounter = lastLevel - 1;
	while(lastLevel >0){
		for(counter = 2^(levelCounter-1) - 1;counter < (2^levelCounter - 1);counter--){
			if(userInputInVectorFormat[counter] > userInput[2*counter] || userInputInVectorFormat[counter] > userInput[2*counter+1]){
				if(userInput[2*counter] > userInput[2*counter+1]){
					tempForSwap = userInput[2*counter];
					userInput[2*counter] = userInput[counter];
					userInput[counter] = tempForSwap;
				}else{
					tempForSwap = userInput[2*counter +1];
					userInput[2*counter + 1] = userInput[counter];
					userInput[counter] = tempForSwap;
				}
			}
		}
		levelCounter--;
	}
}

void Heapify(vector<int> userInput){
	if(userInput.size() == 0|| userInput.size() == 1){
		return;
	}
	int counter = 0;
	do{
		if(2*counter < userInput.size()){
			return;
		}
		int tempForSwap;
		if(userInput[counter] > userInput[2*counter] || userInput[2*counter + 1]){
			if(userInput[2*counter] < userInput[2*counter+1]){
				tempForSwap = userInput[2*counter];
				userInput[2*counter] = userInput[counter];
				userInput[counter] = tempForSwap;
				counter = 2*counter;
			}else{
				tempForSwap = userInput[2*counter + 1];
				userInput[2*counter+1] = userInput[counter];
				userInput[counter] = tempForSwap;
				counter = 2*counter+1;
			}
		}
	}while(counter < userInput.size());
}

int GetMinElement(vector<int> userInput){
	return userInput[0];
}

void DeleteMinHeap(vector<int> &userInput){
	if(userInput.size() == 0){
		return;
	}
	if(userInput.size() == 1){
		userInput.erase(userInput.begin());
		return;
	}

	userInput[0] = userInput[userInput.size() - 1];
	userInput.erase(userInput.begin() + userInput.size() - 1);
	Heapify(userInput);
}

vector<int> HeapSort(vector<int> userInputHeapified){
	vector<int> sortedUserInput;
	while(userInputHeapified.size() >0){
		sortedUserInput = GetMinElement(userInputHeapified);
		DeleteMinHeap(userInputHeapified);
	}
}

#endif /* PRIORITYQUEUES_H_ */
