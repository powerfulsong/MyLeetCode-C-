/*
Spiral(����״) Matrix
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//��ӡ���������Ϊ��vector<vector<int>��
void print_vector (vector<vector<int>> matrix)
{
    cout<<"����Ķ�ά����Ϊ��"<<endl;
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

/*
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        int beginX = 0, endX = matrix[0].size() - 1;
        int beginY = 0, endY = matrix.size() - 1;
        while (true) {
            // From left to right
            for (int j = beginX; j <= endX; ++j) result.push_back(matrix[beginY][j]);
            if (++beginY > endY) break;
            // From top to bottom
            for (int i = beginY; i <= endY; ++i) result.push_back(matrix[i][endX]);
            if (beginX > --endX) break;
            // From right to left
            for (int j = endX; j >= beginX; --j) result.push_back(matrix[endY][j]);
            if (beginY > --endY) break;
            // From bottom to top
            for (int i = endY; i >= beginY; --i) result.push_back(matrix[i][beginX]);
            if (++beginX > endX) break;
        }
        return result;
    }
};
*/

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> res;
        if (matrix.empty()) return res; //����Ϊ��

        int rows, columns; //�С��е���Ŀ
        int index_row = 0, index_column = 0; //�С��б��
        rows = matrix.size();
        columns = matrix[0].size();
        cout<<"rows = "<<rows<<endl;
        cout<<"columns = "<<columns<<endl;

        if(rows == 1)  //ֻ��һ��Ԫ��
        {
            for(index_column = 0; index_column < columns; index_column++)
            {
                res.push_back(matrix[0][index_column]);
            }
            return res;
        }
        if( columns == 1)  //ֻ��һ��Ԫ��
        {
            for(index_row = 0; index_row < rows; index_row++)
            {
                res.push_back(matrix[index_row][0]);
            }
            return res;
        }

        //һ�����
        int direction = 0; // 0: ���� 1: ���� 2:����   3: ����
        bool flag = true;
        while(flag)
        {
            //1.�Ƚ���ǰԪ�ؼ���vector
            cout<<"����vector��Ԫ��Ϊ��"<<matrix[index_row][index_column]<<endl;
            res.push_back(matrix[index_row][index_column]);
            //2.����λ�ñ�ʶΪ���ù�
            matrix[index_row][index_column] = INT_MIN;

            switch(direction)
            {
            case 0:
                //cout<<"����"<<endl;
                if( (columns == index_column + 1) || (INT_MIN == matrix[index_row][index_column+1]) ) //�����һ��Ԫ�ص���߽磬����һ��Ԫ�ر��ù�����ı䷽������
                {
                    direction = 1;
                    //cout<<"����"<<endl;
                    index_row++;
                    if(INT_MIN == matrix[index_row][index_column]){ //��һ��Ԫ�ر��ù�
                        flag = false;
                    }
                }
                else{  //û�е���߽磬 ��ǰһ��Ԫ��û�б��ù�
                    index_column++;
                }
                break;
            case 1:
                //cout<<"����"<<endl;
                if((rows == index_row + 1) || (INT_MIN == matrix[index_row+1][index_column])){
                    direction = 2;
                    //cout<<"����"<<endl;
                    index_column--;
                    if(INT_MIN == matrix[index_row][index_column]){ //��һ��Ԫ�ر��ù�
                        flag = false;
                    }
                }
                else{
                    index_row++;
                }
                break;
            case 2:
                //cout<<"����"<<endl;
                if((0 == index_column ) || (INT_MIN == matrix[index_row][index_column-1])){
                    direction = 3;
                    //cout<<"����"<<endl;
                    index_row--;
                    if(INT_MIN == matrix[index_row][index_column]){ //��һ��Ԫ�ر��ù�
                        flag = false;
                    }
                }
                else{
                    index_column--;
                }
                break;
            case 3:
                //cout<<"����"<<endl;
                if((0 == index_row ) || (INT_MIN == matrix[index_row-1][index_column])){
                    direction = 0;
                    //cout<<"����"<<endl;
                    index_column++;
                    if(INT_MIN == matrix[index_row][index_column]){ //��һ��Ԫ�ر��ù�
                        flag = false;
                    }
                }
                else{
                    index_row--;
                }
                break;
            default:
                break;
            }
        }

        return res;
    }
};

const int M=4;
const int N = 3;

int main()
{
    vector<vector<int>> matrix;
    vector<int> row;
/*
    int i, j;
    //int a[M][N] = {{1, 2, 3}, {4,5, 6}, {7, 8, 9}};
    //int a[M][N] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int a[M][N] ={{1, 2, 3}, {4,5, 6}, {7, 8, 9},{10, 11, 12}};
    //int a[M][N] = {{1}};
    //int a[M][N] = {{1},{2},{3}};
    //int a[M][N] = {{1, 2, 3}};

    for(i=0; i < M; i++)
    {
        for(j=0; j < N; j++)
        {
            row.push_back(a[i][j]);
        }
        matrix.push_back(row);
        row.clear(); //���row
    }

    //���
    //print_vector(matrix);
*/
    vector<int> res;
    Solution s;
    res = s.spiralOrder(matrix);
    //��ʾ���
    vector<int>::iterator it;
    cout<<"���ս��Ϊ��"<<endl;
    for(it = res.begin(); it != res.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}
