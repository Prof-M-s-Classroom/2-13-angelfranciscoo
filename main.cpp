#include <iostream>
using namespace std;

class student {
public:
    string name;
    int age;

    student(string name, int age) {
        this->name = name;
        this->age = age;
    }
    void print() { cout << name << " " << age << endl; }
};

template <typename T> class Node {
public:
    T *value;
    Node<T> *next;
    Node(T *value) {
        this->value = value;
        this->next = NULL;
    }
    void print() { value->print(); }
};

template <typename T> class LinkedList {
private:
    int length;
    Node<T> *head;

public:
    LinkedList(T *value) {
        this->length = 1;
        this->head = new Node<T>(value);
    }

    ~LinkedList() {
        Node<T> *current = this->head;
        while (head) {
            head = head->next;
            delete current;
            current = head;
        }
    }

    Node<T> *get(int index) {
        if (index < 0 || index >= length) {
            return nullptr;
        }

        Node<T> *temp = head;

        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        return temp;
    }

    void add(T *value) {
        Node<T> *newNode = new Node<T>(value);
        Node<T> *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        length++;
    }

    void addhead(T *value) {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        length++;
    }

    void delfirst() {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void dellast() {
        Node<T> *temp = head;
        while (temp->next!=NULL)
            temp = temp->next;
        delete temp;
        length--;
    }

    void deleteNode(int index) {
       //TODO:Write the function to delete at the given index. Reuse the pre-written functions for edge cases. Account for missing index.
        if (index < 0 || index >= length) {
            cout << "Index out of bounds" << endl;
        }
        if (index == 0) {
            delfirst();
            return;
        }
        if (index == length - 1) {
            dellast();
            return;
        }

            Node<T> *delNode = get(index);
            Node<T> *temp = get(index - 1);
            Node<T> *nextNode = temp->next->next;
            temp->next = nextNode;
            delete delNode;

        length--;
    }

   void insert(int index, T *value) {
        //TODO:Write a function to insert a new node at a give index. Reuse the pre-written functions for edge cases. Account for missing index.
        if (index < 0 || index > length) {
            cout << "Index out of bounds" << endl;
        }
        if (index == 0) {
            addHead(value);
        }
        if (index == length) {
            add(value);
        }

        Node<T> *newNode = new Node<T>(value);
        Node<T> *temp = get(index - 1);
        newNode->next = temp->next;
        temp->next = newNode;
        length++;

        cout << "Node inserted at index " << index << "." << endl;
    }

   void reverselist(){
        //TODO:Write a function to reverse the list using the logic from the slide.
        Node<T> *prev = NULL;
        Node<T> *curr = head;
        Node<T> *next = curr->next;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void print() {
        cout << "Printing List.." << endl;
        Node<T> *temp = head;
        while (temp != NULL) {
            temp->print();
            temp = temp->next;
        }
    }
};

int main() {
    student *s1 = new student("A", 20);
    student *s2 = new student("B", 21);
    student *s3 = new student("C", 22);
    student *s4 = new student("D", 22);
    student *s5 = new student("E", 22);
    LinkedList<student> *ll = new LinkedList<student>(s1);
    ll->add(s2);
    ll->add(s3);
    ll->add(s4);
    ll->add(s5);
    ll->print();
    ll->deleteNode(0);
    ll->print();
}