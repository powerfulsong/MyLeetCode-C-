/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0

Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5

Example 3:
nums1 = [4,5,6,8,9]
nums2 = []
The median is 6

Example 4:
nums1 = [1,1];
nums2 = [1,3]
The median is 1 ===>归并排序
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	double findMedian(vector<int> &nums){ //获取每个数组的平均值
		if(nums.size() == 0)	return 0;
		double median = 0.0;
		int size = nums.size();
		if(nums.size() % 2 == 0){ //偶数个元素
			median = 1.0*(nums[size/2] + nums[(size/2)-1])/2;
		}
		else{
			median = nums[(size-1)/2];
		}
		return median;
	}

	double mergeSort(vector<int> &nums1, vector<int> &nums2){
		int size = nums1.size() + nums2.size();
		vector<int> res = vector<int>(size);
		double median = 0.0;
		int i = 0, j = 0, count = 0;
		while(i < nums1.size() && j < nums2.size()){
			if(nums1[i] < nums2[j]){
				res[count++] = nums1[i++];
			}
			else if(nums1[i] >= nums2[j]){
				res[count++] = nums2[j++];
			}
		}
		while(i < nums1.size()){ //第一个数组还有元素
			res[count++] = nums1[i++];
		}
		while(j < nums2.size()){ //第二个数组还有元素
			res[count++] = nums2[j++];
		}
		
		median = findMedian(res);
		return median;
	}

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	double median = 0.0;
	if(nums1.size() == 0){
		median = findMedian(nums2);
	}
	else if(nums2.size() == 0){
		median = findMedian(nums1);
	}
	else{ //归并排序找中间值
		median = mergeSort(nums1, nums2);
	}
	return median;
    }
};

int main(){
	vector<int> nums1, nums2;

	nums1.push_back(1);
	nums1.push_back(3);
	nums1.push_back(5);
	nums1.push_back(7);
	//nums1.push_back(9);

	nums2.push_back(2);
	//nums2.push_back(4);
	nums2.push_back(6);
	nums2.push_back(8);

	Solution s;
	cout<<s.findMedianSortedArrays(nums1, nums2)<<endl;
}
