/*
Valid Parentheses(����ƥ��)
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        for( int i = 0; (unsigned)i < s.length(); i++){
            if(myStack.empty()) //ջΪ��
                myStack.push(s[i]);  //��ջ
            else{ //ջ����
                if( s[i] == '(' || s[i] == '[' || s[i] == '{'){ // ���Ϊ���ߣ�����ջ
                        myStack.push(s[i]);
                   }
                else if( s[i] == ')'){
                    if(myStack.top() == '(')
                        myStack.pop();  //��ջ
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

        if(myStack.empty())  //������ջΪ��
            return true;
        else
            return false;
    }
};