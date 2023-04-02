#include <iostream>
using namespace std;
class Node {
public:
    int Key;
    Node* Next;
    // Node* head;
    // Node* tail;
};
void Add(Node** head, int newValue, Node** tail) {

    Node* newNode = new Node();
    newNode->Key = newValue;
    newNode->Next = NULL;

    Node* last = *head;
    if (last->Next == NULL) {
        last->Next = newNode;
        *tail = newNode;
        return;
    }
    last = *tail;

    last->Next = newNode;

    *tail = newNode;

}
void Delete(Node** head, Node** tail) {
    Node* last = *head;
    while (last->Next->Next != NULL) {
        last = last->Next;
    }
    cout << last->Next->Key << endl;
    delete last->Next;
    last->Next = NULL;
    *tail = last;

}
void Delete2(Node** head, Node** tail) {

    Node* temp = *head;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->Next;
        delete temp;
    }
}


void Get(Node** head, int index)
{
    Node* temp = (*head)->Next;
    for (int i = 0; i < index; i++)
    {
        temp = temp->Next;
    }
    cout << temp->Key << endl;
}
int main()
{
    char sign;
    int number;
    bool end = false;
    Node* head = new Node();
    head->Next = NULL;
    Node* tail = new Node();

    tail->Next = NULL;
    while (!end) {
        cin >> sign;
        if (sign == 'i') {
            cin >> number;
            Add(&head, number, &tail);

        }
        else if (sign == 'd') {
            Delete(&head, &tail);

        }
        else if (sign == 'g') {
            cin >> number;
            Get(&head, number);
        }
        else if (sign == 'q') {

            Delete2(&head, &tail);


            end = true;
        }
    }
}