/*
Given an integer, convert it to a roman numeral.
Input is guaranteed to be within the range from 1 to 3999.
*/
#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string res;
        int nums[4];
        int index = 3;
        while(num != 0){
            nums[index] = num %10;
            num /= 10;
            index --;
        }

        for(int i = 0 ; i < 4; i++){
            //cout <<"nums["<<i<<"]= " << nums[i]<<endl;
            switch(i){
            case 0:  //千位
                if(nums[i] == 1) res+="M";
                else if(nums[i] ==2) res+="MM";
                else if(nums[i] ==3) res+= "MMM";
                break;
            case 1: //百位
                if(nums[i] == 1) res+="C";
                else if( nums[i] == 2) res+="CC";
                else if( nums[i] == 3) res+="CCC";
                else if( nums[i] == 4) res+="CD";
                else if( nums[i] == 5) res+="D";
                else if( nums[i] == 6) res+="DC";
                else if( nums[i] == 7) res+="DCC";
                else if( nums[i] == 8) res+="DCCC";
                else if( nums[i] == 9) res+="CM";
                break;
            case 2: //十位
                if(nums[i] == 1) res+="X";
                else if( nums[i] == 2) res+="XX";
                else if( nums[i] == 3) res+="XXX";
                else if( nums[i] == 4) res+="XL";
                else if( nums[i] == 5) res+="L";
                else if( nums[i] == 6) res+="LX";
                else if( nums[i] == 7) res+="LXX";
                else if( nums[i] == 8) res+="LXXX";
                else if( nums[i] == 9) res+="XC";
                break;
            case 3: //个位
                if(nums[i] == 1) res+="I";
                else if( nums[i] == 2) res+="II";
                else if( nums[i] == 3) res+="III";
                else if( nums[i] == 4) res+="IV";
                else if( nums[i] == 5) res+="V";
                else if( nums[i] == 6) res+="VI";
                else if( nums[i] == 7) res+="VII";
                else if( nums[i] == 8) res+="VIII";
                else if( nums[i] == 9) res+="IX";
                break;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.intToRoman(1888)<<endl;
    return 0;
}
