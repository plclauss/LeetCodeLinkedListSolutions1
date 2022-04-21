//
// Created by plcla on 4/14/2022.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
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

ListNode* reverseList(ListNode* head) {
    std::vector<int> vec;
    ListNode* headCopy = head;
    while (headCopy) {
        vec.push_back(headCopy->val);
        headCopy = headCopy->next;
    }

    headCopy = head;
    while (headCopy) {
        headCopy->val = vec.back();
        vec.pop_back();
        headCopy = headCopy->next;
    }

    return head;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* copyL1 = list1;

    while (copyL1) {
        if (copyL1->next == nullptr)
            break;
        copyL1 = copyL1->next;
    }

    if (list1) {
        copyL1->next = list2;
        sortList(list1);
        return list1;
    }
    else if (list2) {
        sortList(list2);
        return list2;
    }
    else
        return nullptr;
}

ListNode* sortList(ListNode* head) {
    std::vector<int> vec;
    ListNode* headCopy = head;

    while (headCopy) {
        vec.push_back(headCopy->val);
        headCopy = headCopy->next;
    }

    std::sort(vec.begin(), vec.end());

    headCopy = head;
    for (auto& it : vec) {
        headCopy->val = it;
        headCopy = headCopy->next;
    }

    return head;
}
