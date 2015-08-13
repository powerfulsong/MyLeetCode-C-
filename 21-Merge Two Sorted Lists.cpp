/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

#include <iostream>
#include <cstddef>
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode *head, *p, *q;

        if(l1->val < l2 ->val)   //第一个链表的第一个结点值 <  第二个链表的第一个结点值
        {
            head = new ListNode(l1 -> val);
            l1 = l1->next;
        }
        else
        {
            head = new ListNode(l2->val);
            l2 = l2->next;
        }

        p = head; //将p指针指向头结点

        while(true)
        {
            if(l1 == nullptr){ //l1指针到末尾
                p->next = l2;  //连接l2的剩余节点
                return head; //从链表开始返回
            }
            else if(l2 ==nullptr){
                p ->next =l1;  //连接l1的剩余节点
                return head; //从链表开始返回
            }

            if(l1->val < l2->val)  //l1指针当前值 < l2指针的当前值
            {
                q = new ListNode(l1 ->val); //创建新结点

                l1 = l1->next;  //l1向后移一位
                p ->next = q;
                p  = p ->next;
            }
            else
            {
                q = new ListNode(l2 ->val);

                l2 = l2->next;
                p ->next = q;
                p  = p ->next;
            }

        }

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
}

int main()
{
    ListNode * l1, *l2;
    int a[] = {1,3,5,7};
    int b[] = {2,4,6,8};
    /*
    l1 = new ListNode(a[0]);
    ListNode *p, *q;
    p = l1;
    for(int i = 1; i < 4; i++)
    {
        q = new ListNode(a[i]);
        p ->next = q;
        p = q;
    }


    l2 = new ListNode(b[0]);
    p = l2;
    for ( int  i = 1; i <4; i++)
    {
        q = new ListNode(b[i]);
        p ->next = q;
        p = q;
    }

    printList(l1);
    cout<<endl;
    printList(l2);
    cout<<endl;
*/
    l1 = new ListNode(2);
    l2 = new ListNode(1);

    Solution s;
    ListNode * res;
    res = s.mergeTwoLists(l1, l2);
    printList(res);

    return 0;
}
