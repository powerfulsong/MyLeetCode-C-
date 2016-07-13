/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int reverse(int x) {
    double newX=0;
	int a[100],count=0;
	
	if(x==0){
		newX=0;
	}
	else if(x>0){
		while(x>0){
			a[count]=x%10;
			x/=10;
			count++;
		}
		
		for(int i=0; i<count; i++){
			newX+=a[i]*pow(10,count-i-1);		
		}
		
	}else if(x<0){
		x=0-x;  
		while(x>0){
			a[count]=x%10;
			x/=10;
			count++;
		}
		for(int i=0; i<count; i++){			
			newX+=a[i]*pow(10,count-i-1);		
		}
		newX=0-newX;
	}
	
	return (newX<INT_MIN || newX>INT_MAX) ? 0 : newX;
    }
};

int main(){
	Solution s;
	cout<<s.reverse(123)<<endl;	
	return 0;
}
