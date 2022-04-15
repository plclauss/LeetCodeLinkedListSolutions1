//
// Created by plcla on 4/14/2022.
//

#ifndef LINKEDLISTLEETCODEPROBLEMS_LINKEDLIST_H

typedef struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

ListNode* deleteDuplicates(ListNode* head);
bool hasCycle(ListNode* head);
ListNode* reverseList(ListNode* head);
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
ListNode* sortList(ListNode* head);

#define LINKEDLISTLEETCODEPROBLEMS_LINKEDLIST_H

#endif //LINKEDLISTLEETCODEPROBLEMS_LINKEDLIST_H
