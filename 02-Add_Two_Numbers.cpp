/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Input: (5) + (5)
Output: 0->1

Input: (3->7) + (9->2)
Output: 2->0->1
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
void printList(ListNode *l){
	if(l == NULL) return ;
	cout<<l->val;
	ListNode *p;
	p = l;
	while(p->next != NULL){
		cout<<"->";
		p = p->next;
		cout<<p->val;	
	}
	cout<<endl;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	if(l1 == NULL) return l2;
	if(l2 == NULL) return l1;

	ListNode *res;
	ListNode *p, *q; //l1,l2的临时指针
	ListNode *res_m, *res_n; //res的临时指针
	p = l1;
	q = l2;
	int addSum_gewei, addSum_jinwei; //记录个位和进位
	addSum_gewei = (l1->val + l2->val)%10;
	addSum_jinwei = (l1->val + l2->val)/10;
	
	res = new ListNode(addSum_gewei);  //记录第一个值
	res_m = res;

	while(p->next != NULL && q->next != NULL){
		p = p->next;
		q = q->next;
		addSum_gewei = (p->val + q->val + addSum_jinwei)%10; //计算新的个位
		addSum_jinwei = (p->val + q->val + addSum_jinwei)/10; //计算新的进位
		res_n = new ListNode(addSum_gewei); //新建节点
		res_m->next = res_n;
		res_m = res_m->next;
	}

	if(p->next == NULL && q->next == NULL && addSum_jinwei == 1){ //两个队列都结束，但存在进位
		res_n = new ListNode(addSum_jinwei);
		res_m->next = res_n;
		res_m = res_m->next;
	}
		
	while(p->next != NULL){ //l1链表还有元素
		p = p->next;
		if(p->next == NULL && p->val == 9 && addSum_jinwei == 1){ //存在进位
			addSum_gewei = (p->val + addSum_jinwei)%10;
			res_n = new ListNode(addSum_gewei);
			res_m->next = res_n;
			res_m = res_m->next;
			
			addSum_jinwei = (p->val + addSum_jinwei)/10;
			res_n = new ListNode(addSum_jinwei);
			res_m->next = res_n;
			res_m = res_m->next;
		}
		else{
			addSum_gewei = (p->val + addSum_jinwei)%10;
			addSum_jinwei = (p->val + addSum_jinwei)/10;
			res_n = new ListNode(addSum_gewei);
			res_m->next = res_n;
			res_m = res_m->next;
		}
	}

	while(q->next != NULL){ //l2链表还有元素
		q = q->next;
		if(q->next == NULL & q->val == 9 && addSum_jinwei == 1){	
			addSum_gewei = (q->val + addSum_jinwei)%10;
			res_n = new ListNode(addSum_gewei);
			res_m->next = res_n;
			res_m = res_m->next;
			
			addSum_jinwei = (q->val + addSum_jinwei)/10;
			res_n = new ListNode(addSum_jinwei);
			res_m->next = res_n;
			res_m = res_m->next;
		}
		else{
			addSum_gewei = (q->val + addSum_jinwei)%10;
			addSum_jinwei = (q->val + addSum_jinwei)/10;
			res_n = new ListNode(addSum_gewei);
			res_m->next = res_n;
			res_m = res_m->next;
		}
	}

	return res;
    }
};


int main(){
	int a[2] = {3, 7};
	int b[2] = {9, 2};
	ListNode *l1 = new ListNode(a[0]);
	int i = 0;
	ListNode *p, *q;
	p = l1;
	for(i = 1; i < 2; i++){
		q = new ListNode(a[i]);
		p->next = q;
		p = p->next;	
	}
//	printList(l1);

	ListNode *l2 = new ListNode(b[0]);
	p = l2;
	for(i = 1; i < 2; i++){
		q = new ListNode(b[i]);
		p->next = q;
		p = p->next;
	}
//	printList(l2);
	
	ListNode *final;
	Solution s;
	final = s.addTwoNumbers(l1,l2);
	printList(final);

	return 0;
}
