#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string.h>

using namespace std;

struct AverageNode {
  int average;
  int *values;
  AverageNode *next;
};

void findAverageOfGroup(int * arr, int size, int m, AverageNode **result)
{
    int i = 0, j = 0;
    AverageNode *ptrResult = NULL;
    
    if (size < m || NULL == result)
    {
        return;
    }
    
    for (i = 0; (i + (m - 1)) < size; ++i)
    {
        // Create Node
        AverageNode *newResult = (AverageNode*)malloc(sizeof(AverageNode));
        newResult->values = (int*)malloc(sizeof(newResult->values[0]) * m);
        
        for (j = 0; j < m; ++j)
        {
            newResult->values[j] = arr[i + j];
            newResult->average += newResult->values[j];
        }
        newResult->average /= m;
        newResult->next = NULL;
        
        // Add New Node
        if (NULL == ptrResult)
        {
            ptrResult = newResult;
            (*result) = ptrResult;
        }
        else {
            ptrResult->next = newResult;
            ptrResult = ptrResult->next;
        }
    }
}

// Driver program to test above functions
int main()
{
	AverageNode *result = NULL, *ptrResult = NULL;
	int arr[] = {1, 2, 3, 4, 5};
    int m = 3;
    
	int size = sizeof(arr) / sizeof(arr[0]);
	
	findAverageOfGroup(arr, size, m, &result);
	
	// Print
	ptrResult = result;
    for (int i = 0; NULL != ptrResult; ++i)
    {
        cout << i << " : average " << ptrResult->average << " -> ";
        for (int j = 0; j < m; ++j)
        {
            cout << ptrResult->values[j] << " ";
        }
        cout << std::endl;
        
        ptrResult = ptrResult->next;
        
        free(result->values);
        free(result);
        result = ptrResult;
    }
    
    return 0;
}
