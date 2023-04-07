// TestBL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <cstdlib>
using namespace std;


string ltrim(const string&);
string rtrim(const string&);

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
public:
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;

    SinglyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data) {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

        if (!this->head) {
            this->head = node;
        }
        else {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
}

SinglyLinkedListNode * condense(SinglyLinkedListNode * head) {
    // using the two pointer method
    SinglyLinkedListNode* second_ptr(nullptr);
    SinglyLinkedListNode*  first_ptr(nullptr);
    // first pointer points to first node in the list
    first_ptr = head;
    // if the first node is not null i.e. list not empty, and there is another node
    while (first_ptr != nullptr && first_ptr->next != nullptr) {
        // point the second pointer to the same place as the first pointer
        second_ptr = first_ptr;
        // check if second_ptr is not null and there is another node
        while (second_ptr!= nullptr && second_ptr->next != nullptr) {
            // check if the first node and next node value are the same
            // if yes then delete the next node
            if (first_ptr->data == second_ptr->next->data) {
                second_ptr->next = second_ptr->next->next;;
            }
            // if not then forward the second pointer
            else {
                second_ptr = second_ptr->next;
            }
            // by end of while loop all the duplicates of the first pointer will be removed
        }
        // forward the first pointer
        first_ptr = first_ptr->next;
    }
    // return the head of the linked list
    return head;
}

int main()
{
   //ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList* head = new SinglyLinkedList();

    string head_count_temp;
    getline(cin, head_count_temp);

    int head_count = stoi(ltrim(rtrim(head_count_temp)));

    for (int i = 0; i < head_count; i++) {
        string head_item_temp;
        getline(cin, head_item_temp);

        int head_item = stoi(ltrim(rtrim(head_item_temp)));

        head->insert_node(head_item);
    }

    SinglyLinkedListNode* result = condense(head->head);

    print_singly_linked_list(result, "\n");
    //fout << "\n";

    //fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
