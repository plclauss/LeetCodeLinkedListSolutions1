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

bool hasCycle(ListNode* head) {
    // KEY = address of node
    // MAPPED = position
    std::unordered_map<ListNode*, int> map;
    int32_t pos = -1;

    ListNode* headCopy = head;

    uint32_t index = 0;
    while (headCopy) {
        map.insert(std::make_pair(headCopy, index));
        if (map.find(headCopy->next) != map.end()) {
            pos = map.find(headCopy->next)->second;
            return map.find(headCopy->next) != map.end();
        }
        headCopy = headCopy->next;
        index++;
    }

    return false;
}
