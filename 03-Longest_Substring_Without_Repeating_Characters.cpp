/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	if(s.length() == 0)	return 0;

    int length = 0, newlength = 0;
	string s_temp = ""; //用于存放最小字符串
	int i = 0, j = 0; 
	for(i = 0, j = 0; j < s.length(); j++){
		if(s_temp.find(s[j]) != -1){ //包含此元素	
			i++;
			j = i;
			s_temp = s[j];		
			newlength = 1;
		}
		else{
			newlength++;
			s_temp += s[j];
		}
		length = max(length, newlength);
	}
	
	return length;
    }
};

int main(){
	string str = "abcabcbb";
	Solution s;
	cout<<s.lengthOfLongestSubstring(str)<<endl;
	return 0;
}
