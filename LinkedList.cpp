//
// Created by plcla on 4/14/2022.
//

#include <iostream>
#include <vector>
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
    ListNode* list1Copy = list1;
    ListNode* list2Copy = list2;

    while (list1Copy && list2Copy) {
        if (list2Copy->val >= list1Copy->val) {
            ListNode* list1Tracker = list1Copy->next;
            ListNode* list2Tracker = list2Copy->next;

            list1Copy->next = list2Copy;
            list2Copy->next = nullptr;
            list2Copy->next = list1Tracker;

            list1Copy = list1Tracker;
            list2Copy = list2Tracker;
        }
        else {
            ListNode* list2Tracker = list2Copy->next;

            list2Copy->next = nullptr;
            list2Copy->next = list1Copy;

            list1Copy = list1Copy->next;
            list2Copy = list2Tracker;
        }
    }

    return list1;
}

ListNode* sortList(ListNode* head) {
    std::vector<int> vec;
    ListNode* headCopy = head;

    while (headCopy) {
        vec.push_back(headCopy->val);
        headCopy = headCopy->next;
    }

    std::vector<int> sortedVec;

    // binary search
}
