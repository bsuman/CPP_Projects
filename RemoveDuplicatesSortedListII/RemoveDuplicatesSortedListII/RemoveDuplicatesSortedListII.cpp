// RemoveDuplicatesSortedListII.cpp : Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
//

#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};


ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr)
        return nullptr;

    ListNode* current(head);
    ListNode* savedptr(nullptr);

    int deletedval = -99999;
    while (current != nullptr && current->next != nullptr) {
        if (current->val == current->next->val || current->val == deletedval)
        {
            if (head == current) {
                head = current->next;
            }
            else if (savedptr != nullptr) {
                savedptr->next = current->next;
            }
            deletedval = current->val;
        }
        else {
            if (current->next != nullptr && current->next->next != nullptr)
            {
                if (current->next->val == current->next->next->val)
                {
                    savedptr = current;
                }
            }
        }
        current = current->next;
    }
    if (current->next == nullptr && current->val == deletedval)
    {
        if (head == current) {
            head = nullptr;
        }
        else if (savedptr != nullptr) {
            savedptr->next = current->next;
        }
        deletedval = current->val;
    }
    return head;
}


int main()
{
    std::cout << "Hello World!\n";
}
