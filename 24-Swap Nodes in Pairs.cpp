/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr) return head; //��ָ��

        ListNode *p, *q, *temp;
        p = head; //pָ���һ���ڵ�
        q = head->next; //qָ��ڶ����ڵ�
        head = head->next; //��ͷָ��ָ��ڶ����ڵ�
        bool b = true;

        if(p->next->next == nullptr) //ֻ�������ڵ�
        {
            p->next = q->next;
            q ->next = p;
        }
        else //���������ڵ�
        {
            while(q->next != nullptr && p->next != nullptr)
            {
                if(b)  //��һ��ִ��
                {
                    p->next = q->next;
                    q->next = p;
                    temp = p; //�����ʱָ��
                    p = p->next;
                    if(p->next != nullptr){ //���p���滹�нڵ㣬�ų��������ڵ�����
                        q = p->next;
                    }
                    b = false;
                }
                else   //ʣ��ִ��
                {
                    temp->next = q;
                    p->next = q->next;
                    q->next = p;
                    temp = p;
                    p = p->next;
                    if(p->next != nullptr){
                        q = p->next;
                    }
                }

            }
            if(q->next == nullptr) //qΪ���һ��Ԫ��
            {
                p->next = q->next;
                temp->next = q;
                q ->next = p;
            }
        }

        return head;
    }
};

void printList(ListNode *l)
{
    ListNode *p = l;
    while(p)
    {
        cout<<p->val;
        if(p->next) cout<<",";
        p = p->next;
    }
    cout<<endl;
}

int main()
{
    ListNode * l1;
    int a[] = {1,2,3,4,5,6,7,8};
    l1 = new ListNode(a[0]);
    ListNode *p, *q;
    p = l1;

   for(int i = 1; i < 5; i++)
    {
        q = new ListNode(a[i]);
        p ->next = q;
        p = q;
    }

    printList(l1);

    Solution s;
    ListNode *res = s.swapPairs(l1);
    printList(res);

    return 0;
}
