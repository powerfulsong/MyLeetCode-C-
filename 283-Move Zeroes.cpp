/*
Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_vector(vector<int> &nums);
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int vector_size = (int)nums.size();
        if(nums.size() > 1) {  //对于<=0 或者 =1不用任何操作
            for(int i = 0; i < vector_size; i++){
                if(nums[i] != 0){ //如果不为0，则跳过
                    continue;
                }
                else{
                    for(int j = i ; j < vector_size-1; j ++){  //与它后面的每个元素交换位置
                        swap(nums[j], nums[j+1] );
                    }
                    i--; //指针不能动
                    vector_size = vector_size - 1;  //大小减1
                }
            }
            print_vector(nums);
        }
    }
};

void print_vector(vector<int> &nums){
    vector<int>::iterator it;
    for(it = nums.begin(); it != nums.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

const int ArraySize = 3;

int main()
{
    int test[ArraySize] = {0,0,1};
    vector<int> nums;
    for(auto i = 0; i < ArraySize; i++){
        nums.push_back(test[i]);
    }

    Solution s;
    s.moveZeroes(nums);
    return 0;
}
