/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
*/


#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
    	int res = 0;
    	bool noFlags = true;
    	if(str.length() == 0)	return 0; //空字符串
    	if(str[0] < '0' && str[0] > '9' && str[0] != '-') return 0; //第一个字符不是数字
    	while(str[0] == ' ' || str[0] == '0' || str[0] == '+') { //去掉无用字符
    		if(str[0] == '+') {
    			noFlags = false;
    		}
    		if(str[0] == '+' && str[1] == '+') return 0;   //预防”  ++123"情况
    		if(noFlags == false && (str.find(' ') != -1))   return 0;  //预防“  +0 123”之类的情况
    		str = str.substr(1);
    	}
    	
    	if(str[0] == '-' && noFlags){ //负数
    		int i = 0, count = 0;
    		for(i = 1; i < str.length(); i++){
    			if(str[i] >= '0' && str[i] <= '9'){ //该字符是数字
    				count++;
    				if(count > 10) return INT_MIN;
    				else{
    					if(res  > 2147483647/10) return INT_MIN;
    					if(res == 2147483647/10){
    						if(str[10] > '8') return INT_MIN;
    					}
    					res = res * 10 + (str[i]-'0');
    				}
    			}
    			else{ //该字符不是数字
    				break;
    			}
    		}
    		return 0-res;
    	}
    	else{ //正数
    		int i = 0, count = 0;
    		for(i = 0; i < str.length(); i++){
    			if(str[i] >= '0' && str[i] <= '9'){ //该字符是数字
    				count++; //统计字数
    				if(count > 10){ //数越界
    					return INT_MAX;		
    				}
    				else{
    					if(res > 2147483647/10) return INT_MAX;
    					if(res == 2147483647/10){
    						if(str[9] > '7') return INT_MAX;
    					}
    					res = res*10 + (str[i]-'0');		
    				}
    			}
    			else{ //该字符不是数字
    				break;
    			}
    		}
    		 return res;
    	}
    }
};


int main(){
	Solution s;
	string str;
//	str = ""; // 0
//	str = "123"; // 123
//	str = "1234567890123456"; // 2147483647
//	str = "2147483646";  //2147483646
//	str = "2147483647";  //2147483647
//	str = "2147483648" ;  //2147483647
//	str = "1234567890123460"; // 2147483647
//	str = "1234567890#12";  //1234567890
//	str = "12345678#12"; // 12345678
//	str = "12345678901245#12"; // 214783647
//	str = "123456&12" // 123456
//	str = "&12"; // 0
//	str = "-123456"; // -123456
//	str = "-1234567890123456"; // -2147483648
//	str = "-2147483647";  //-2147483647
//	str = "-2147483648";  //-2147483648
//	str = "-2147483649";  //-2147483648
//	str = "+123";  //123;
//	str = "    010";  //10
//	str = "+-2";   //0
//	str = "++2";  //0
//	str = "-+2"; //0
//	str = "--0"; //0
//	str = "   +0 123";  //0
// 	str = "   +0123"; //123
//	str = "   + 1 123"; //0
	str = "     +004500";  //4500
	cout<<s.myAtoi(str)<<endl;
	return 0;
}
