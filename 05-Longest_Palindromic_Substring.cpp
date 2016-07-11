/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
回文(Palindromic)就是从左右两边读都一样的字符串。例如”aba”是回文，”abc”不是回文。
//此代码有问题，当字符串很长时，会超时
eg:
a -> a
aa -> aa
ab -> a
aba -> aba
aaa -> aaa
abac -> aba
abbbac -> abbbac
abba -> abba
abbac -> abba
cabba -> abba
cabaab -> baab
aab -> aa
abb -> bb
eeeeeeeee -> eeeeeeeee
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string findMaxString(string s, int i){
	string res = "";
	string temp = "";
	int count = 1;
	int length = 0, temp_length = 0;
	
	//s[i-1] = s[i]
	if(s[i-1] == s[i]){
		count = 1;
		temp = s[i-1];
		temp += s[i];
		temp_length = 2;	

		while(i-1-count >= 0 && i + count < s.length() && s[i-1-count] == s[i+count]){
			temp_length += 2;
			temp = s[i-1-count] + temp + s[i+count];
			count++;
		}
		
		if(temp_length > length){
			length = temp_length;
			res = temp;
		}
	}

	//s[i] = s[i+1]
	if(s[i] == s[i+1]){
		count = 1;
		temp = s[i];
		temp += s[i+1];
		temp_length = 2;
		while(i-count >= 0 && i+1+count < s.length() && s[i-count] == s[i+1+count]){
			temp_length += 2;
			temp = s[i-count] + temp + s[i+1+count];
			count++;
		}
		if(temp_length > length){
			length = temp_length;
			res = temp;
		}
	}

	//s[i-1] = s[i+1]
	if(s[i-1] == s[i+1]){
		count = 1;
		temp = s[i-1];
		temp += s[i];
		temp += s[i+1];
		temp_length = 3;
		while(i-1-count >= 0 && i+1+count < s.length() && s[i-1-count] == s[i+1+count]){
			temp_length += 2;
			temp = s[i-1-count] + temp + s[i+1+count];
			count++;
		}
		if(temp_length > length){
			length = temp_length;
			res = temp;
		}
	}

	return res;
    }

    string longestPalindrome(string s) {
	if(s.length() == 0) return "";
	if(s.length() == 1) return s;

	string res = "";
	if(s.length() == 2){
		if(s[0] == s[1]) return s;
		else{
			res += s[0];
			return res;	
		}	
	}

	int i = 0;
	string str_temp = "";
	for(i = 1; i < s.length()-1; i++){
		str_temp = findMaxString(s, i);
		if(str_temp.length() > res.length()){
			res = str_temp;
		}
	}
	return res;
    }
};

int main(){
//	string str = "";
//	string str = "a";
//	string str = "aa";
//	string str = "ab";
//	string str = "aba";
//	string str = "aaa";
//	string str = "abac";
//	string str = "aaaa";
//	string str = "abbbac";
//	string str = "abba";
//	string str = "abbac";
//	string str = "cabba";
//	string str = "cabaab";
//	string str = "abb";
//	string str = "aab";
	string str = "eeeeeeeee";
	
	Solution s;
	cout<<s.longestPalindrome(str)<<endl;
	return 0;
}
