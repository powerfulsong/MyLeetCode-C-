/*
Set Matrix Zeroes
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
[[0,1,2,3][4,5,6,7][8,9,10,11]] -> [[0,0,0,0],[0,5,6,7],[0,9,10,11]]

[[1,1,2,3][4,0,6,7][0,9,10,11]] -> [[0,0,2,3],[0,0,0,0],[0,0,0,0]]

[[0,0,0,5],[4,3,1,4],[0,1,1,4],[1,2,1,3],[0,0,1,1]] -> [[0,0,0,0],[0,0,0,4],[0,0,0,0],[0,0,0,3],[0,0,0,0]]
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void print_vector (vector<vector<int>> matrix);

class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        vector<int> temp;
        queue<vector<int>> row_num_column_num; //用于存储所有0所对应的行号和列号
        int rows = (int)matrix.size();
        int colums = (int)matrix[0].size();
        cout<<"rows = "<<rows<<" , cloumns = "<<colums<<endl;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < colums; j++)
            {
                if(matrix[i][j] == 0)
                {
                    temp.push_back(i); //压入行号
                    temp.push_back(j); //压入列号
                    row_num_column_num.push(temp);
                    temp.clear();
                }
            }
        }
        changeMatrix(matrix, row_num_column_num);

    }

    //改变矩阵
    void changeMatrix(vector<vector<int>>& matrix, queue<vector<int>> row_num_column_num)
    {
        int rows = (int)matrix.size();
        int colums = (int)matrix[0].size();
        int row_number, column_number;

        while(!row_num_column_num.empty())
        {
            vector<int> temp = row_num_column_num.front();
            row_number = temp[0];
            column_number = temp[1];
            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < colums; j++)
                {
                    if( i == row_number || j == column_number)  //清零
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
            row_num_column_num.pop();
        }
    }
};

//打印二维数组
void print_vector (vector<vector<int>> matrix)
{
    cout<<"输出的二维矩阵为："<<endl;
    vector<vector<int>>::iterator it1;
    for(it1 = matrix.begin(); it1 != matrix.end(); it1++)
    {
        vector<int> matrix_row = *it1;
        vector<int>::iterator it2;
        for(it2 = matrix_row.begin(); it2 != matrix_row.end(); it2++)
        {
            cout<<*it2<<" ";
        }
        cout<<endl;
    }
}

const int M = 5;
const int N = 4;

int main()
{
    vector<vector<int>> matrix;
    vector<int> row;
    int a[M][N] = {{0,0,0,5},{4,3,1,4},{0,1,1,4},{1,2,1,3},{0,0,1,1}};
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            row.push_back(a[i][j]);
        }
        matrix.push_back(row);
        row.clear();
    }

    Solution s;
    s.setZeroes(matrix);
    print_vector(matrix);
    return 0;
}
