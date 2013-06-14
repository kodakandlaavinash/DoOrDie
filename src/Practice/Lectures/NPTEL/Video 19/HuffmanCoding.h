/*
 * HuffmanCoding.h
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

#ifndef HUFFMANCODING_H_
#define HUFFMANCODING_H_

struct huffmanCodeLeafNode;

struct huffmanCodeNode{
	int value;
	huffmanCodeNode *left;
	huffmanCodeNode *right;
	huffmanCodeLeafNode *leftLeaf;
	huffmanCodeLeafNode *rightLeaf;
	huffmanCodeNode *parent;
};

struct huffmanCodeLeafNode{
	int value;
	char ch;
	huffmanCodeNode *parent;
};

struct huffmanHelperDS{
	huffmanCodeLeafNode *leafNode;
	huffmanCodeNode *node;
};

huffmanHelperDS *GetMinimumValues(hash_map<int,int> huffmanTrees){
	if(huffmanTrees.size() == 0){
		return NULL;
	}

	hash_map<int,int>::iterator *itToHuffmanTrees = huffmanTrees.begin();
	int min1,min2;
	int minValue1 = INT_MAX,minValue2 = INT_MAX;
	for(itToHuffmanTrees = huffmanTrees.begin();itToHuffmanTrees != huffmanTrees.end();itToHuffmanTrees++){
		if(minValue1 > (*itToHuffmanTrees)->second){
			minValue2 = minValue1;
			minValue1 = (*itToHuffmanTrees)->second;
			min2 = min1;
			min1 = (*itToHuffmanTrees)->first;
		}else{
			if(minValue2 > (*itToHuffmanTrees)->second){
				minValue2 = (*itToHuffmanTrees)->second;
				min2 = (*itToHuffmanTrees)->first;
			}
		}
	}

	int *result[2] = {min1,min2};
	//returns the index of huffman trees
	return result;
}

huffmanCodeNode *BuildHuffmanTree(hash_map<char,int> frequencyTable){
	if(frequencyTable.size() == 0){
		return NULL;
	}
	if(frequencyTable.size() == 1){
		return NULL;
	}
	hash_map<char,int>::iterator *itToFrequenctTable;
	hash_map<int,int> auxSpace;
	hash_map<int,huffmanHelperDS> indexNodeMap;
	huffmanCodeLeafNode *newLeafNode;
	huffmanHelperDS *newAuxSpace;
	int indexCounter = -1;
	for(itToFrequenctTable = frequencyTable.begin();itToFrequenctTable != frequencyTable.end();itToFrequenctTable++){
		newLeafNode = (huffmanCodeLeafNode *)malloc(sizeof(huffmanCodeLeafNode));
		newLeafNode->ch = (*itToFrequenctTable)->first;
		newLeafNode->value = (*itToFrequenctTable)->second;
		newLeafNode->parent = NULL;

		newAuxSpace = (huffmanHelperDS *)malloc(sizeof(huffmanHelperDS));
		newAuxSpace->leafNode = newLeafNode;
		newAuxSpace->node = null;

		auxSpace.insert(pair<int,int>(++indexCounter,newLeafNode->value));
		indexNodeMap.insert(pair<int,huffmanHelperDS>(indexCounter,newAuxSpace));
	}

	int *twoMinNodeIndexValue[2];
	hash_map<int,huffmanHelperDS>::iterator *itToMinHuffmanTree1,*itToMinHuffmanTree2;
	huffmanHelperDS *minTree1,*minTree2;
	while(auxSpace.size() == 1){
		twoMinNodeIndexValue = GetMinimumValues(auxSpace);
		itToMinHuffmanTree1 = indexNodeMap.find(*twoMinNodeIndexValue[0]);
		itToMinHuffmanTree2 = indexNodeMap.find(*twoMinNodeIndexValue[1]);
		minTree1 = (*itToMinHuffmanTree1)->second;
		minTree2 = (*itToMinHuffmanTree2)->second;

		huffmanCodeNode *internalNode = (huffmanCodeNode)malloc(sizeof(huffmanCodeNode));
		if(minTree1->leafNode != NULL && minTree2->leafNode != NULL){
			// Both are leaf nodes
			internalNode->leftLeaf = minTree1->leafNode;
			internalNode->rightLeaf = minTree2->leafNode;
			internalNode->value = minTree1->leafNode->value + minTree2->leafNode->value;
			internalNode->left = null;
			internalNode->right = null;
			minTree1->leafNode->parent = internalNode;
			minTree2->leafNode->parent = internalNode;
			internalNode->parent = null;
		}else{
			if(minTree1->leafNode == NULL || minTree2->leafNode == NULL){
				// One is leaf node
				if(minTree1->leafNode != NULL){
					internalNode->leftLeaf = minTree1->leafNode;
					internalNode->value = minTree1->leafNode->value + minTree2->node->value;
					minTree1->leafNode->parent = internalNode;
					minTree2->node->parent = internalNode;
					internalNode->right = minTree2->node;
					internalNode->left = NULL;
					internalNode->rightLeaf = NULL;
					internalNode->parent = NULL;
				}else{
					internalNode->leftLeaf = minTree2->leafNode;
					internalNode->value = minTree2->leafNode->value + minTree1->node->value;
					minTree2->leafNode->parent = internalNode;
					minTree1->node->parent = internalNode;
					internalNode->right = minTree1->node;
					internalNode->left = NULL;
					internalNode->rightLeaf = NULL;
					internalNode->parent = NULL;
				}
			}else{
				// Both are partially built huffman tree
				internalNode->left = minTree1->node;
				minTree1->node->parent = internalNode;
				internalNode->right = minTree2->node;
				minTree2->node->parent = internalNode;

				internalNode->value = minTree1->node->value + minTree2->node->value;
				internalNode->leftLeaf = NULL;
				internalNode->parent = NULL;
				internalNode->rightLeaf = NULL;
			}
		}

		indexNodeMap.erase(itToMinHuffmanTree1);
		indexNodeMap.erase(itToMinHuffmanTree2);

		auxSpace.erase(twoMinNodeIndexValue[0]);
		auxSpace.erase(twoMinNodeIndexValue[1]);

		auxSpace.insert(pair<int,int>(++indexCounter,internalNode->value));

		indexNodeMap.insert(pair<int,huffmanHelperDS>(indexCounter,internalNode));
	}

	hash_map<int,huffmanHelperDS>::iterator *itToFinalHuffmanTree = indexNodeMap.begin();
	return (*itToFinalHuffmanTree)->second;
}


#endif /* HUFFMANCODING_H_ */
