// LeetCode 160 - Intersection of Two Linked Lists
// Topic: Hash Table + Linked List + Two Pointers
// Difficulty: Easy
// Time Complexity: O(n + m)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while( t1 != t2 ){
            t1 = (t1 == NULL) ? headB : t1 -> next;
            t2 = (t2 == NULL) ? headA : t2 -> next;
        }
        return t1;
    }
};
