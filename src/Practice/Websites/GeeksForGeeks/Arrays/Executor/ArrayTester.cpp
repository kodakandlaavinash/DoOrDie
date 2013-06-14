/*
 * ArrayExecutor.cpp
 *
 *  Created on: May 5, 2013
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

#include "../Array Utils/ArrayUtil.h"
#include "../Page 4/FindNumberOccuringOddTimes.h"
#include "../Page 4/CheckWhetherPairExistsForInputSum.h"
#include "../Page 4/FindMissingNumber.h"
#include "../Page 4/LeadersInArray.h"
#include "../Page 4/Segregate0sAnd1s.h"
#include "../Page 4/MergeTwoArrays.h"
#include "../Page 4/ReverseArray.h"
#include "../Page 4/LargestSumContigousArray.h"
#include "../Page 4/MajorityElement.h"
#include "../Page 4/RotateArray.h"


using namespace std;
using namespace __gnu_cxx;

#define null NULL
#define PRINT_NEW_LINE printf("\n")
#define NA -1
int main() {
	int arr[] = {0, 1, 0, 1, 1, 1};
	int arr_size = 6;
	SegregateZerosAndOnesCounter(arr,arr_size);
	PrintArray(arr,arr_size);


}

