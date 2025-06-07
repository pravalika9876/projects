#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ANSI color codes
const string GREEN = "\033[1;32m";
const string RED = "\033[1;31m";
const string YELLOW = "\033[1;33m";
const string CYAN = "\033[1;36m";
const string RESET = "\033[0m";

// Task structure
struct Task {
    string description;
    bool completed;
};

// Task list
vector<Task> tasks;

void addTask() {
    cout << CYAN << "Enter task description: " << RESET;
    string desc;
    getline(cin >> ws, desc);
    tasks.push_back({desc, false});
    cout << GREEN << "Task added successfully.\n" << RESET;
}

void viewTasks() {
    if (tasks.empty()) {
        cout << RED << "No tasks in the list.\n" << RESET;
        return;
    }
    cout << YELLOW << "\n--- To-Do List ---\n" << RESET;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". ";
        if (tasks[i].completed) {
            cout << GREEN << "[Completed] " << tasks[i].description << RESET << "\n";
        } else {
            cout << RED << "[Pending] " << tasks[i].description << RESET << "\n";
        }
    }
}

void markCompleted() {
    int index;
    viewTasks();
    if (tasks.empty()) return;
    cout << CYAN << "Enter task number to mark as completed: " << RESET;
    cin >> index;
    if (index < 1 || index > tasks.size()) {
        cout << RED << "Invalid task number.\n" << RESET;
        return;
    }
    tasks[index - 1].completed = true;
    cout << GREEN << "Task marked as completed.\n" << RESET;
}

void removeTask() {
    int index;
    viewTasks();
    if (tasks.empty()) return;
    cout << CYAN << "Enter task number to remove: " << RESET;
    cin >> index;
    if (index < 1 || index > tasks.size()) {
        cout << RED << "Invalid task number.\n" << RESET;
        return;
    }
    tasks.erase(tasks.begin() + index - 1);
    cout << GREEN << "Task removed.\n" << RESET;
}

void menu() {
    int choice;
    do {
        cout << YELLOW << "\n==== To-Do List Menu ====\n" << RESET;
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        cout << CYAN << "Enter your choice: " << RESET;
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markCompleted(); break;
            case 4: removeTask(); break;
            case 5: cout << GREEN << "Exiting To-Do List Manager.\n" << RESET; break;
            default: cout << RED << "Invalid choice. Try again.\n" << RESET;
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}
