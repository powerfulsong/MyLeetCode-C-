/*
Search a 2D Matrix
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool b = false;
        if(matrix.size() == 0) return false;
        int row_max = (int)matrix.size()-1;
        int column_max = (int)matrix[0].size()-1;

        if( target < matrix[0][0] || target > matrix[row_max][column_max]) return false;
        for( int i = 0; i <= row_max; i++){
            if(target >= matrix[i][0] && target <= matrix[i][column_max]){
                b = find_target(matrix[i], target);
                return b;
            }
        }
        return b;
    }

    //在一个vector中寻找一个数
    bool find_target(vector<int> myArray, int target){
        bool b = false;
        vector<int>::iterator it;
        for(it = myArray.begin(); it != myArray.end(); it++){
            if(*it == target) {
                b = true;
            }
        }
        return b;
    }
};

void print_vector (vector<vector<int>> matrix){
    vector<vector<int>>::iterator it1;
    for(it1 = matrix.begin(); it1 != matrix.end(); it1++){
        vector<int> matrix_row = *it1;
        vector<int>::iterator it2;
        for(it2 = matrix_row.begin(); it2 != matrix_row.end(); it2++){
            cout<<*it2<<" ";
        }
        cout<<endl;
    }
}

const int M = 3;
const int N = 4;

int main()
{
    int test[M][N] = { {1,   3,  5,  7},{10, 11, 16, 20},{23, 30, 34, 50}};
    vector<vector<int>> matrix;
    vector<int> temp;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
             temp.push_back(test[i][j]);
        }
        matrix.push_back(temp);
        temp.clear();
    }

    print_vector(matrix);

    Solution s;
    cout<<s.searchMatrix(matrix, 51)<<endl;
    return 0;
}
