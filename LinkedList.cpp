//
// Created by plcla on 4/14/2022.
//

#include <iostream>
#include <unordered_map>
#include "LinkedList.h"

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* headCopy = head;
    while (headCopy && headCopy->next) {
        if (headCopy->val == headCopy->next->val)
            headCopy->next = headCopy->next->next;
        else
            headCopy = headCopy->next;
    }

//    free(headCopy);
    return head;
}
