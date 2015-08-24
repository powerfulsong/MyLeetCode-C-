/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
For example,
Given nums = [0, 1, 3] return 2.
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());  //先对原来的数据进行排序
        for(int i = 0; i <= nums.size(); i++){
            if( i != nums[i])
                return i;
        }
    }
};

int main()
{
    vector<int> vec;
    int a[1] = {1};
    vec.push_back(a[0]);
    for(int i = 1; i <1; i++){
        vec.push_back(a[i]);
    }

    vector<int>::iterator it;
  /*  for(it = vec.begin(); it != vec.end(); it++){
        cout<<*it<<endl;
    }
*/
    Solution s;
    cout<<s.missingNumber(vec);
    return 0;
}
