/*
Contains Duplicate
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print_vector(vector<int> nums){
    vector<int>::iterator it;
    for(it = nums.begin(); it != nums.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int nums_size = (int)nums.size();
        if(nums_size == 0) return false;

        std::sort(nums.begin(), nums.end());
        print_vector(nums);
        bool b = false;
        int currentValue = nums[0];;
        int myCount = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == currentValue){ //说明和上一个值重复
                b = true;
                break;
            }else{
                currentValue = nums[i];
            }
        }
        return b;
    }
};

const int M = 2;

int main(){
    int a[M] = {3,3};
    vector<int> nums;
    for(int i = 0; i < M; i ++){
        nums.push_back(a[i]);
    }

    Solution s;
    cout<<s.containsDuplicate(nums)<<endl;

    return 0;
}
