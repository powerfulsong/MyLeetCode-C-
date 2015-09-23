/*
Remove Duplicates from Sorted List
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/
#include <iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

//打印链表
void print_List(ListNode *TestList){
    ListNode *p = TestList;
    while(p){
        cout<<p->val;
        if(p->next) cout<<"->";
        p = p->next;
    }
    cout<<endl;
}

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;

        ListNode *p, *q;
        int currentVal = 0;
        p = head;
        currentVal = p->val;
        while(p->next != nullptr){
            if(p->next->val == currentVal){ //删除该节点
                q = p->next;
                p->next = q->next;
                delete(q);
            }else{ //p后移一次
                 p = p->next;
                 currentVal = p->val; //更新当前值
            }
        }
        return head;
    }
};

int main()
{
    int a[] = {1,1,2,3,3};
    ListNode *TestList = new ListNode(a[0]);
    ListNode *p, *q;
    p = TestList;
    for(int i = 1; i < 5; i++){
        q = new ListNode(a[i]);
        p->next = q;
        p = p->next;
    }
    print_List(TestList);
    Solution s;
    ListNode *res = s.deleteDuplicates(TestList);
    print_List(res);
    return 0;
}
