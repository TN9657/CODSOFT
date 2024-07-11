#include <iostream>
#include <string>

using namespace std;

class Task {
public:
    string task;
    int Priority;
    Task* next;

    Task(string S, int a) {
        task = S;
        Priority = a;
        next = nullptr;
    }
};

void create(Task*& head) {
    string Task_name;
    int Priority;
    cout << "Enter the Task Name: ";
    cin >> Task_name;
    cout << "Enter the Priority: ";
    cin >> Priority;

    Task* temp = new Task(Task_name, Priority);

    if (head == nullptr || temp->Priority < head->Priority) {
        temp->next = head;
        head = temp;
    } else {
        Task* current = head;
        while (current->next != nullptr && current->next->Priority <= temp->Priority) {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
}

void display(Task* head) {
    if (head == nullptr) {
        cout << "The Stack is Empty" << endl;
        return;
    }

    Task* temp = head;
    while (temp != nullptr) {
        cout << "____________________________________________________" << endl;
        cout << temp->Priority << "|\t" << temp->task << endl;
        cout << "----------------------------------------------------" << endl;
        temp = temp->next;
    }
}

void del(Task*& head, string Name_task) {
    if (head == nullptr) {
        cout << "The Stack is Empty" << endl;
        return;
    }

    Task* prev = nullptr;
    Task* current = head;
    while (current != nullptr && current->task != Name_task) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "The Task is not in the Stack" << endl;
        return;
    }

    if (prev == nullptr) {
        head = current->next;
    } else {
        prev->next = current->next;
    }
    delete current;
}

int main() {
    Task* head = nullptr;
    char C;

    do {
        int choice;
        cout << "1. Create a Task\n2. Display Task's\n3. Delete Task\nEnter the Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            create(head);
            break;
        case 2:
            display(head);
            break;
        case 3: {
            string name;
            cout << "Enter the Task Name: ";
            cin >> name;
            del(head, name);
            break;
        }
        default:
            cout << "Invalid Choice" << endl;
        }

        cout << "Do You Want to add any Other Task(Y/N): ";
        cin >> C;
    } while (C == 'Y');

    return 0;
}