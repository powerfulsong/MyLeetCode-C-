/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,?1,2,1] has the largest sum = 6.
*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        int temp = 0;
        int res = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            temp = max(temp+nums[i], nums[i]);
            res = max(res, temp);
        }
        return res;
    }
};

int main()
{
    //int a[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int a[3] = {-2, 1, 3};
    vector<int> nums;
    for(int i = 0; i <3; i++ ){
        nums.push_back(a[i]);
    }

    /*
    vector<int>::iterator it;
    for(it = nums.begin(); it != nums.end(); it++){
        cout<<*it<<endl;
    }
    */

    Solution s;
    cout<<s.maxSubArray(nums)<<endl;
    return 0;
}
