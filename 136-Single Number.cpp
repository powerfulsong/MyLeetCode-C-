/*
Single Number
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

void print_vector(vector<int> nums){
    vector<int>::iterator it;
    for(it= nums.begin(); it != nums.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int nums_size = (int)nums.size();
        if(nums_size == 0) return 0;
        sort(nums.begin(), nums.end()); //����
        stack<int> myStack;
        for(int i = 0; i < nums_size; i++){
            if(myStack.size() == 0){ //ջΪ��
                myStack.push(nums[i]);
            }else{ //ջ����
                if(nums[i] == myStack.top()){ //�����ջ��Ԫ����ͬ���򵯳�
                    myStack.pop();
                }else{
                    myStack.push(nums[i]);
                }
            }
        }
        return myStack.top();
    }
};

const int M = 1;

int main()
{
    int a[M] = {-1};
    vector<int> nums;
    for(int i = 0; i < M; i++){
        nums.push_back(a[i]);
    }
    Solution s;
    cout<<s.singleNumber(nums)<<endl;
    return 0;
}
