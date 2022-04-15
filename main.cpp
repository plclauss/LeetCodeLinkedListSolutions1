#include <iostream>
#include "LinkedList.h"

int main() {
    ListNode node1(1);
    ListNode node2(1);
    ListNode node3(2);

    node1.next = &node2;
    node2.next = &node3;

    deleteDuplicates(&node1);

    node1.val = 1;
    node2.val = 1;
    node3.val = 2;

    node1.next = &node2;
    node2.next = &node3;

    ListNode node4(3);
    ListNode node5(3);

    node3.next = &node4;
    node4.next = &node5;

    deleteDuplicates(&node1);

    free(node1.next);
    free(node2.next);
    free(node3.next);
    free(node4.next);

    return 0;
}
