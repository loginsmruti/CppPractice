class ListNode {
public:
    int value;
    ListNode* next;

    // Constructor with default values
    ListNode(int val = 0, ListNode* nxt = nullptr) : value(val), next(nxt) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // Create a dummy node to form the new sorted list
    ListNode dummy(0);
    ListNode* current = &dummy;

    // Traverse through both lists
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // Attach the remaining part of the list that is not yet finished
    if (list1 != nullptr) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    // Return the merged list, which starts from dummy.next
    return dummy.next;
}

int main() {
    // Example usage
    // Example 1
    ListNode* head1 = new ListNode(15);
    head1->next = new ListNode(10);
    head1->next->next = new ListNode(5);
    head1->next->next->next = new ListNode(20);
    head1->next->next->next->next = new ListNode(3);
    head1->next->next->next->next->next = new ListNode(2);
    

    
    return 0;
}