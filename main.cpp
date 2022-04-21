#include <iostream>
#include <vector>
#include "LinkedList.h"

int main() {
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(4);

    node1.next = &node2;
    node2.next = &node3;

    ListNode node4(1);
    ListNode node5(3);
    ListNode node6(4);

    node4.next = &node5;
    node5.next = &node6;

    mergeTwoLists(&node1, &node4);

    return 0;
}
