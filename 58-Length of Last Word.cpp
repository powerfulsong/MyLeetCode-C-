/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
If the last word does not exist, return 0.
Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
*/
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        while(s.back() == ' ') { //最后一个字符是" " ------用于防止"b   a    "这种情况
            s.pop_back(); //删除最后一个字符 ----用于防止"a "这种情况
        }
        //cout<<"s = *"<<s<<"*"<<endl;

        int index = s.find_last_of(' '); //寻找最后一次出现' '的位置
        //cout<<"size = "<<s.size()<<endl;
        //cout<<"index = "<<index<<endl;
        length = s.size() - (index + 1);
        return length;
    }
};

int main()
{
    string str;
    str ="b   a    ";
    Solution s;
    cout<<s.lengthOfLastWord(str)<<endl;
    return 0;
}
