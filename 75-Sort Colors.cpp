/*
Sort Colors
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int nums_size = (int)nums.size();
        if(nums_size > 1){
            //Ã°ÅÝÅÅÐò
            for(int i = 0; i < nums_size; i++){
                for( int j = i+1; j < nums_size; j++){
                        if(nums[i] > nums[j]){ //½»»»ÔªËØ
                            nums[i] = nums[i] + nums[j];
                            nums[j] = nums[i] - nums[j];
                            nums[i] = nums[i] - nums[j];
                        }
                }
            }
        }
    }
};

const int M = 2;

int main()
{
    int test[M] = {1, 0};
    vector<int> nums;
    for(int i = 0; i < M; i++){
        nums.push_back(test[i]);
    }

    Solution s;
    s.sortColors(nums);

    vector<int>::iterator it;
    for(it = nums.begin(); it != nums.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}
