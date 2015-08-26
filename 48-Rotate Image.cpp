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
            //cout<<"1�������Խ��߷�ת"<<endl;
            for(int j = i; j < matrix.size(); j++)
            {
                if( i == j) continue;
                else if(i != j) swap(matrix[i][j], matrix[j][i]);
            }
            //cout<<"2���ƴ�ֱ�߷�ת"<<endl;
            for( int k = 0; k < matrix.size()/2; k++)
            {
                swap(matrix[i][k], matrix[i][matrix.size()-k-1]);
            }
        }
    }
};

//��ӡ���������Ϊ��vector<vector<int>��
void print_vector (vector<vector<int>> matrix)
{
    cout<<"������Ϊ��"<<endl;
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

    //����ά����ѹ��vector��
    for( int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            //��ÿһ��ѹ��vector��
            row.push_back(input_array[i][j]);
        }
        //��vectorѹ���ܵ�vector��
        input_vector.push_back(row);
        //����ܵ�vector
        row.clear();
    }

    cout<<"����תǰ��"<<endl;
    print_vector(input_vector);

    cout<<"\n��ʼ��ת......"<<endl;
    //����ת
    Solution s;
    s.rotate(input_vector);

    cout<<"\n����ת��"<<endl;
    print_vector(input_vector);
    return 0;
}
