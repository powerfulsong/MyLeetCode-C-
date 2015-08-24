/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        vector<int> res;

        if(nums.size() == 1 ) //如果只有一个元素
        {
            res.push_back(nums[0]);
        }
        else if(nums.size() == 2 && (nums[0] != nums[1])) //如果只有2个不同元素
        {
            res.push_back(nums[0]);
            res.push_back(nums[1]);
        }
        else  //多于2个元素
        {
            sort(nums.begin(), nums.end()); //先将原集合中的数据排序
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] == nums[i+1])  //如果相邻两数相同，i+2
                {
                    i++;
                }
                else  //如果相邻两数不同 i+1, 并将 i 加入结果集中
                {
                    // cout<<"res = "<< nums[i] <<endl;
                    res.push_back(nums[i]);
                }
            }
        }
        return res;
    }
};
int main()
{
    vector<int> vec;
    int a[1] = {1};
    vec.push_back(a[0]);
    for(int i = 1; i <1; i++)
    {
        vec.push_back(a[i]);
    }

    Solution s;
    vector<int> res = s.singleNumber(vec);
    cout<<"Final Result : "<<endl;
    vector<int>::iterator it;
    for(it = res.begin(); it != res.end(); it++)
    {
        cout<<*it<<endl;
    }
    return 0;
}
