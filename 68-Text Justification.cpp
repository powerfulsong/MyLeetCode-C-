/*
Text Justification

Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        vector<string> res;
        if(words.size() == 0 || maxWidth <= 0)
        {
            res.push_back("");
            return res;
        }
        vector<string> temp1;
        vector<vector<string>> temp2;

        //�����ݷָ�����ά������
        int i, words_all_size = 0;
        for(i = 0; i < (int)words.size(); i++)
        {
            if(words_all_size + (int)words[i].size() <= maxWidth)
            {
                //cout<<words[i]<<"����temp1"<<endl;
                temp1.push_back(words[i]);
                words_all_size += (words[i].size() + 1);
            }
            else if(words_all_size + (int)words[i].size() > maxWidth)
            {
                //cout<<"temp1����temp2"<<endl;
                temp2.push_back(temp1);
                temp1.clear();  //��ʱvector����
                words_all_size = 0; //��������
                i--;
            }
        }
        if(words_all_size <= maxWidth+1)  //��󼸸����п���ռ����һ��
        {
            //cout<<"temp1����temp2"<<endl;
            temp2.push_back(temp1);
            temp1.clear();  //��ʱvector����
            words_all_size = 0; //��������
        }

        //����άvectorת����һάvector
        res = changeVector(temp2, maxWidth);

        return res;
    }

    //��vector<vector<string>> ת����vector<string>
    vector<string> changeVector(vector<vector<string>> matrix, int maxWidth)
    {
        vector<string> res;
        int i = 0;
        //ǰn-1�д���
        for(i = 0; i < (int)matrix.size()-1; i++)
        {
            int spaceLength, spaceNums;
            string str1 = "";
            int length=0;
            for(int j = 0; j < (int)matrix[i].size(); j++)  //����ÿһ���ܵ��ַ���
            {
                length += (int)matrix[i][j].size();
            }
            spaceLength = maxWidth - length; //��������Ŀո���
            spaceNums = (int)matrix[i].size() - 1;

            for(int j = 0; j < (int)matrix[i].size(); j++)
            {
                if((int)matrix[i].size() == 1)  //ֻ��һ��Ԫ��
                {
                    str1 += matrix[i][j] + printSpace(maxWidth-(int)matrix[i][j].size());
                }
                else //��ֻһ��Ԫ��
                {
                    if(j == 0) //��һ��Ԫ��
                        str1 += matrix[i][j];
                    else  //����Ԫ��
                    {
                        str1 += printSpace(space_Nums(spaceLength, spaceNums)) + matrix[i][j];
                        spaceLength -= space_Nums(spaceLength, spaceNums); //�µĿո���Ŀ
                        spaceNums--;
                    }
                }

            }
            //cout<<"str1 = "<<str1<<endl;
            res.push_back(str1);
        }

        //���һ�е�������
        string str2;
        for(int j = 0; j <(int)matrix[i].size(); j++)  //�����ַ���
        {
            if(j ==  (int)matrix[i].size()-1)
            {
                str2+=matrix[i][j];
            }
            else
            {
                str2 += matrix[i][j] +" ";
            }
        }
        str2 = str2+printSpace(maxWidth-str2.size());
        res.push_back(str2);
        return res;
    }

    //���㵱ǰ����еĿո���Ŀ
    //spaceLength: �ո��ܳ���  spaceNums: ����ĸ���
    int space_Nums(int spaceLength, int spaceNums)
    {
        int res = 0;
        if((spaceLength % 2 != 0) && (spaceNums % 2 != 0))  //�������ո���������
        {
            if(spaceLength % spaceNums == 0)  //eg:3���ո�1����
            {
                res = spaceLength/spaceNums;
            }
            else //eg: 5���ո�3����
                res = spaceLength/spaceNums + 1;
        }
        else if((spaceLength % 2 != 0) && (spaceNums % 2 == 0))  //�������ո�ż������
        {
            res = spaceLength/spaceNums + 1;
        }
        else if((spaceLength % 2 == 0) && (spaceNums % 2 != 0))  //ż�����ո���������
        {
            if(spaceLength % spaceNums == 0)  //eg:2���ո�1����
            {
                res = spaceLength/spaceNums;
            }
            else //eg: 4���ո�3����
                res = spaceLength/spaceNums + 1;
        }
        else if((spaceLength % 2 == 0) && (spaceNums % 2 == 0))  //ż�����ո�ż������
        {
            if(spaceLength % spaceNums == 0)  //eg:4���ո�2����
            {
                res = spaceLength/spaceNums;
            }
            else //eg: 6���ո�4����
                res = spaceLength/spaceNums + 1;
        }
        return res;
    }

    //��ӡn���ո�
    string printSpace(int n)
    {
        //cout<<"n = "<<n<<endl;
        string res;
        for(int i=0; i<n; i++)
        {
            res = res + " ";
        }
        return res;
    }
};


void print_string(vector<string> words)
{
    vector<string>::iterator it;
    for(it = words.begin(); it != words.end(); it++)
    {
        cout<<"*"<<*it<<"*"<<endl;
    }
}

int main()
{
    vector<string> words;

/*
    //maxWidth = 16
    words.push_back("This");
    words.push_back("is");
    words.push_back("an");
    words.push_back("example");
    words.push_back("of");
    words.push_back("text");
    words.push_back("justification");
    words.push_back("oh.");
*/

/*
        //maxWidth = 3
        words.push_back("a");
        words.push_back("b");
        words.push_back("c");
        words.push_back("d");
        words.push_back("e");
*/

/*
        //maxWidth = 12;
       words.push_back("What");
        words.push_back("must");
        words.push_back("be");
        words.push_back("shall");
        words.push_back("be.");
*/

/*
        //maxWidth = 1;
        words.push_back("a");
*/

/*
        //maxWidth = 20;
        words.push_back("My");
        words.push_back("momma");
        words.push_back("always");
        words.push_back("said,");
        words.push_back("\"Life");
        words.push_back("was");
        words.push_back("like");
        words.push_back("a");
        words.push_back("box");
        words.push_back("of");
        words.push_back("chocolates.");
        words.push_back("You");
        words.push_back("never");
        words.push_back("know");
        words.push_back("what");
        words.push_back("you're");
        words.push_back("gonna");
        words.push_back("get.");
*/


        //maxWidth = 30;
        words.push_back("Don't");
        words.push_back("go");
        words.push_back("around");
        words.push_back("saying");
        words.push_back("the");
        words.push_back("world");
        words.push_back("owes");
        words.push_back("you");
        words.push_back("a");
        words.push_back("living;");
        words.push_back("the");
        words.push_back("world");
        words.push_back("owes");
        words.push_back("you");
        words.push_back("nothing;");
        words.push_back("it");
        words.push_back("was");
        words.push_back("here");
        words.push_back("first.");


    //print_string(words);
    vector<string> res;
    Solution s;
    res = s.fullJustify(words, 30);
    print_string(res);

    return 0;
}
