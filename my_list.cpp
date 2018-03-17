#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class queue {
    node *head, *tail;
    public:
    queue() { // constructor
        head = NULL;
        tail = NULL;
        cout << "Queue is being created\n";
    }
    ~queue() { // destructor
        cout << "Queue is being deleted\n";
    }
    void enqueue(int data) {
        node *tmp = new node;  // tmp is the current node address
        tmp->data = data; // update data field of the current node
        tmp->next = NULL;
        if (head == NULL) {
            head = tmp; // store head pointer address in the very beginning
        } else {
            tail->next = tmp; // update link address of previous node by pointing to the current node address
        }
        tail = tmp; // update tail pointer by pointing to the current node address
    }
    void dequeue() {
        if (head != NULL) {
            head = head->next;
        }
    }
    void push(int data) {
        node *tmp = new node;
        tmp->data = data;
        if (head == NULL) {
            tail = tmp;
        } else {
            tmp->next = head;
        }
        head = tmp;
    }
    void display () {
        node *tmp = head;
        while (tmp != NULL) {
            cout << tmp->data << " -> ";
            tmp = tmp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    int i;
    queue my_queue;
    for (i=0; i<50; i++) {
        my_queue.enqueue(i);
    }
    my_queue.display();
    for (i=0; i<50; i++) {
        my_queue.dequeue();
    }
    my_queue.display();

    for (i=0; i<50; i++) {
        my_queue.push(i);
    }
    my_queue.display();
    return 0;
}
