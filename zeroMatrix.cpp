/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


void zeroMatrix(std::vector<std::vector<bool>> &matrix) {
    std::vector<std::pair<int,int>> points;
    
    // Get true points 
    for (int row = 0; row < matrix.size(); ++row) {
        for (int col = 0; col < matrix.size(); ++col) {
            if (matrix[row][col]) {
                points.push_back({row, col});    
            }
        }
    }
    
    for (auto p : points) {
        // Set Rows to true
        for (int row = 0; row < matrix.size(); ++row) {
            matrix[row][p.second] = true;
        }
        
        // Set col to true
        for (int col = 0; col < matrix[0].size(); ++col) {
            matrix[p.second][col] = true;
        }
    }
}

int main()
{
    std::vector<std::vector<bool>> matrix = {
        {true, false, false},
        {false, false, false},
        {false, false, true}
    };
    
    zeroMatrix(matrix);
    
    for (int row = 0; row < matrix.size(); ++row) {
        for (int col = 0; col < matrix.size(); ++col) {
            cout << matrix[row][col];
        }
        cout << endl;
    }
    
    return 0;
}
