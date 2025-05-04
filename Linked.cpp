#include <iostream>
using namespace std;

class Node {
    int data;
    Node* next;

public:
    Node(int value) {
        data = value;
        next = nullptr;
    }

    // دالة لإضافة عنصر في بداية القائمة
    static void insertFront(Node*& head, int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // دالة لإضافة عنصر في نهاية القائمة
    static void insertEnd(Node*& head, int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // دالة لحذف عنصر من القائمة
    static void DelNode(Node*& head, int value) {
        if (head == nullptr) return;

        // إذا كان العنصر في البداية
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // البحث عن العنصر
        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    // دالة لطباعة القائمة
    static void print(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// البرنامج الرئيسي
int main() {
    Node* head = nullptr;

    // إنشاء القائمة 15 -> 30 -> 40 -> 50
    Node::insertEnd(head, 15);
    Node::insertEnd(head, 30);
    Node::insertEnd(head, 40);
    Node::insertEnd(head, 50);

    cout << "القائمة الأصلية:\n";
    Node::print(head);

    // إضافة 10 في البداية
    Node::insertFront(head, 10);
    cout << "\nبعد إضافة 10 في البداية:\n";
    Node::print(head);

    // إضافة 60 في النهاية
    Node::insertEnd(head, 60);
    cout << "\nبعد إضافة 60 في النهاية:\n";
    Node::print(head);

    // حذف 30 من القائمة
    Node::DelNode(head, 30);
    cout << "\nبعد حذف 30:\n";
    Node::print(head);

    return 0;
}
