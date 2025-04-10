
#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }
    
};




// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
void insert_node(SinglyLinkedList* llist, const int& newData) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(newData);

    if (!llist->head) {
        llist->head = llist->tail = newNode;
        return;
    }

    llist->tail->next = newNode;
    llist->tail = newNode;
}

void reverseLinkedList(SinglyLinkedList* llist) {
    SinglyLinkedListNode* p1 = llist->head;
    SinglyLinkedListNode* p2 = new SinglyLinkedListNode(p1->data);

    SinglyLinkedListNode* newTail = p2;

    while (p1->next != nullptr) {
        p1 = p1->next;
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(p1->data);
        newNode->next = p2;
        p2 = newNode;
    }

    llist->head = p2;
    llist->tail = newTail;
}

void printLinkedList(SinglyLinkedList* llist) {
    SinglyLinkedListNode* p = llist->head;
    while (p != nullptr) {
        cout << p->data << ' ';
        p = p->next;
    }
}

int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;


    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

        insert_node(llist,llist_item);
    }
    
    
    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}
