//Reverse Linked List II
//Reverse a linked list from position m to n. Do it in-place and in one-pass.
//Solution: elements at m and n positions partion the linked list into at most 3 parts. we need to reverse the middle one and link back to 
// the two remain ones. To keep track the last pointer of the first partion we use a pointer fromStartingPt. We don't need to use the pointer
// to link to the last partion since it is natually linked when we reverse the sequences in the middle partion.
// to reverse the middle partion, we use 3 pointers: p,c,n. p and n help to maintain the links to the head and the tail of the partion. At
// each iteration, we try to reverse the link p -> c to c->p and update the p,c, and n.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL || m==n)
            return head;
        ListNode *fromStartingPt = NULL;
        ListNode *p=head, *c = NULL, *next = NULL;
        int num = 0;
       
        while (num < m-1 && p) {
            fromStartingPt = p;
            p = p->next;
            num = num + 1;
        }
         cout<<p->val<<endl;
        if (p == NULL) return head;
        c = p->next;
        if(c) next = c->next;
        int number_of_iterations = n - m;
        
        ListNode *dummy1=p, *dummy2=NULL;
        int ith = 0;
        while (ith < number_of_iterations){
            cout<<p->val<<endl;
            c->next = p;
            p=c;
            c=next;
            if(c) next = c->next;
            
            ith = ith + 1;
            
        }
        
        if(fromStartingPt)
            fromStartingPt->next = p;
        else head = p;
        dummy1->next = c;
        //if(c) c->next = NULL;
        return head;
       
    }
};
