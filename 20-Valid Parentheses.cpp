/*
Valid Parentheses(括号匹配)
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        for( int i = 0; (unsigned)i < s.length(); i++){
            if(myStack.empty()) //栈为空
                myStack.push(s[i]);  //入栈
            else{ //栈不空
                if( s[i] == '(' || s[i] == '[' || s[i] == '{'){ // 如果为左半边，则入栈
                        myStack.push(s[i]);
                   }
                else if( s[i] == ')'){
                    if(myStack.top() == '(')
                        myStack.pop();  //出栈
                    else
                        myStack.push(s[i]);
                }
                else if( s[i] == ']'){
                    if(myStack.top() == '[')
                        myStack.pop();
                    else
                        myStack.push(s[i]);
                }
                else if( s[i] == '}'){
                    if(myStack.top() == '{')
                        myStack.pop();
                    else
                        myStack.push(s[i]);
                }
            }
        }

        if(myStack.empty())  //如果最后栈为空
            return true;
        else
            return false;
    }
};