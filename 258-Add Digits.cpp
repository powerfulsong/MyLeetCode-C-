/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
For example:
Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
Follow up:
Could you do it without any loop/recursion in O(1) runtime?
*/
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        /*
        //��һ�ַ���
        int temp = 0;
        if(num < 10) return num;
        else{
            while(num != 0){
                temp += (num%10);
                num/=10;
            }
            addDigits(temp);
        }
        */

        //�ڶ��ַ���
        //��ʽ�� dr(n) = n - 9*ȡ����((n-1)/9);
        //�ο���https://en.wikipedia.org/wiki/Digital_root
        return (num - 9*((num-1)/9));
    }
};

int main()
{
    Solution s;
   cout<<s.addDigits(1234)<<endl;
    return 0;
}
