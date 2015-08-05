/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
*/

#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        string res= "";
        int temp , temp2;
        if( nRows == 1) return s; //如果只有一行，直接输出

        for(int i = 0; i < s.length(); i++){
           if( i == 0 || i == nRows-1){
            for(temp = i; temp <= s.length()-1; ){
                res += s[temp];
                temp += 2 * (nRows -1);  //第一行、最后一行每个字符下标的编号差（2*(nRows -1)）
            }
           }
           else if( i > 0 && i < nRows-1){
            for( temp = i, temp2 = temp + 2*( nRows - (i +1) ); temp <= s.length()-1; ){ //奇数下标 与 偶数下标 之间差（2*( nRows - (i +1) )）
                //cout<< "temp = "<<temp<<" , temp2="<<temp2<<endl;
                res += s[temp];
                temp += 2 * (nRows -1);
                if( temp2 <= s.length() -1){
                    res += s[temp2];
                    temp2 += 2*(nRows -1);
                }
            }
           }
        }
        return res;
    }
};

int main()
{
    Solution s;
  //  cout<<s.convert("ABCDEFGHIJKLMNOPQRST", 5)<<endl;
   cout<<s.convert("abc", 2)<<endl;
    return 0;
}
