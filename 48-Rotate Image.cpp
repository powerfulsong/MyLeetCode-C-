/*
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int SIZE = 3;

class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        //cout<<"matrix.size() = "<<matrix.size()<<endl;
        for(int i = 0; i < matrix.size(); i++)
        {
            //cout<<"1、绕主对角线反转"<<endl;
            for(int j = i; j < matrix.size(); j++)
            {
                if( i == j) continue;
                else if(i != j) swap(matrix[i][j], matrix[j][i]);
            }
            //cout<<"2、绕垂直线反转"<<endl;
            for( int k = 0; k < matrix.size()/2; k++)
            {
                swap(matrix[i][k], matrix[i][matrix.size()-k-1]);
            }
        }
    }
};

//打印输出（输入为：vector<vector<int>）
void print_vector (vector<vector<int>> matrix)
{
    cout<<"输出结果为："<<endl;
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

int main()
{
    vector<vector<int>> input_vector;
    vector<int> row;
    //int input_array[SIZE][SIZE] = {{1}};
    int input_array[SIZE][SIZE] = {{1,2,3},{4,5,6},{7,8,9}};

    //将二维数组压入vector中
    for( int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            //将每一行压入vector中
            row.push_back(input_array[i][j]);
        }
        //将vector压入总的vector中
        input_vector.push_back(row);
        //清空总的vector
        row.clear();
    }

    cout<<"矩阵反转前："<<endl;
    print_vector(input_vector);

    cout<<"\n开始反转......"<<endl;
    //矩阵反转
    Solution s;
    s.rotate(input_vector);

    cout<<"\n矩阵反转后："<<endl;
    print_vector(input_vector);
    return 0;
}
