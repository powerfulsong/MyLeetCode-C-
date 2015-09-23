/*
Remove Duplicates from Sorted Array II
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void print_vector(vector<int> &nums)
{
    vector<int>::iterator it;
    for(it = nums.begin(); it != nums.end(); it++)
        cout<<*it<<" ";
    cout<<endl;
}

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int myCount = 0, currentValue = INT_MIN;
        int DuplicatesNums_MAX = 2; //最大重复次数
        if(nums.size() == 0)
        {
            return 0;
        }
        else   //元素数目 > 1
        {
            vector<int>::iterator it;
            for(it = nums.begin(); it != nums.end(); it++)
            {
                if(it == nums.begin())
                {
                    currentValue = *it;
                    myCount = 1;
                }
                else
                {
                    if(currentValue != *it)  //参考值与当前值不同
                    {
                        currentValue = *it;
                        myCount = 1;
                    }
                    else   //参考值与当前值相同
                    {
                        if(myCount < DuplicatesNums_MAX)
                        {
                            myCount++;
                        }
                        else   //重复次数大于最大允许重复的次数
                        {
                            nums.erase(it); //擦除该元素
                            it--;
                        }
                    }
                }
            }
        }
        return (int)nums.size();
    }
};

const int M = 1;
int main()
{
    vector<int> nums;
    int test[M] = {1};
    for( int  i = 0; i < M; i++)
        nums.push_back(test[i]);
    Solution s;
    cout<<s.removeDuplicates(nums)<<endl;
    return 0;
}
