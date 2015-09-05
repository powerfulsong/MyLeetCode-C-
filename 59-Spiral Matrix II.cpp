/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,
You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res_Matrix(n, vector<int>(n));
        if(n == 0) return res_Matrix;

        int column_index_min = 0, column_index_max = n-1;
        int row_index_min = 0, row_index_max = n-1;
        int number = 1;  //矩阵中所填写的数据
        int i, j;
        while((column_index_min < column_index_max) && (row_index_min < row_index_max)){
            //Left -> Right
            for(i = column_index_min; i <= column_index_max; i++){
                res_Matrix[row_index_min][i] = number++; //赋值
                cout<<"res_Matrix["<<row_index_min<<"]["<<i<<"] ="<<res_Matrix[row_index_min][i]<<endl;
            }
            row_index_min++;

            //Up -> Down
            for( j = row_index_min; j <= row_index_max; j++){
                res_Matrix[j][column_index_max] = number++;
                cout<<"res_Matrix["<<j<<"]["<<column_index_max<<"] ="<<res_Matrix[j][column_index_max]<<endl;
            }
            column_index_max--;

            //Right -> Left
            for( i = column_index_max; i >= column_index_min; i--){
                res_Matrix[row_index_max][i] = number++;
                cout<<"res_Matrix["<<row_index_max<<"]["<<i<<"] ="<<res_Matrix[row_index_max][i]<<endl;
            }
            row_index_max--;

            //Down -> Up
            for( j = row_index_max; j >= row_index_min; j--){
                res_Matrix[j][column_index_min] = number++;
                cout<<"res_Matrix["<<j<<"]["<<column_index_min<<"] ="<<res_Matrix[j][column_index_min]<<endl;
            }
            column_index_min++;
        }

        //当n为奇数时，填写最中心的数据
        if(n % 2 ==1){
            res_Matrix[row_index_max][column_index_max] = number++;
        }
        return res_Matrix;
    }
};

//打印输出（输入为：vector<vector<int>）
void print_vector (vector<vector<int>> matrix){
    cout<<"输出的二维矩阵为："<<endl;
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

int main()
{
    Solution s;
    vector<vector<int>> res;
    res = s.generateMatrix(3);
    print_vector(res);
    return 0;
}
