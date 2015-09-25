/*
Single Number II
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int nums_size = (int)nums.size();
        if(nums_size == 0) return 0;
        sort(nums.begin(), nums.end()); //先排序
        int count = 0;
        int currentValue = nums[0];
        for(int i = 0; i < nums_size; i++){
            if(currentValue == nums[i]){
                count ++;
            }else{
                if(count == 1) {
                return currentValue;
                }
                currentValue = nums[i]; //更换标准值
                count = 1;
            }
        }
        if(count == 1) { //考虑最后一个元素只有一个的情况
            return currentValue;
        }
    }
};

const int M = 7;

int main()
{
    int a[M] = {2,1,1,1,3,3,3};
    vector<int> nums;
    for(int i = 0; i < M; i++){
        nums.push_back(a[i]);
    }
    Solution s;
    cout<<s.singleNumber(nums)<<endl;
    return 0;
}
