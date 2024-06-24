#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to merge two sorted linked lists
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

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Helper function to create a linked list from a vector of values
ListNode* createList(std::vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Create two sorted linked lists
    std::vector<int> vals1 = {1, 2, 4};
    std::vector<int> vals2 = {1, 3, 4};

    ListNode* list1 = createList(vals1);
    ListNode* list2 = createList(vals2);

    // Merge the lists
    ListNode* mergedList = mergeTwoLists(list1, list2);

    // Print the merged list
    std::cout << "Merged list: ";
    printList(mergedList);

    return 0;
}
