#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Task structure to store task information
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

// Function to add a task to the list
void addTask(vector<Task>& taskList, const string& description) {
    taskList.push_back(Task(description));
    cout << "Task added: " << description << endl;
}

// Function to view tasks in the list
void viewTasks(const vector<Task>& taskList) {
    if (taskList.empty()) {
        cout << "Task list is empty." << endl;
    } else {
        cout << "Task List:" << endl;
        for (size_t i = 0; i < taskList.size(); ++i) {
            cout << "[" << (i + 1) << "] ";
            if (taskList[i].completed) {
                cout << "[X] ";
            } else {
                cout << "[ ] ";
            }
            cout << taskList[i].description << endl;
        }
    }
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& taskList, int index) {
    if (index >= 1 && index <= static_cast<int>(taskList.size())) {
        taskList[index - 1].completed = true;
        cout << "Task marked as completed: " << taskList[index - 1].description << endl;
    } else {
        cout << "Invalid task index. No task marked as completed." << endl;
    }
}

// Function to remove a task from the list
void removeTask(vector<Task>& taskList, int index) {
    if (index >= 1 && index <= static_cast<int>(taskList.size())) {
        cout << "Task removed: " << taskList[index - 1].description << endl;
        taskList.erase(taskList.begin() + (index - 1));
    } else {
        cout << "Invalid task index. No task removed." << endl;
    }
}

int main() {
    vector<Task> taskList;
    int choice;

    cout << "Welcome to the To-Do List Program!" << endl;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore(); // Clear the newline character from the input buffer
                cout << "Enter task description: ";
                string description;
                cin.ignore();
                getline(cin, description);
                addTask(taskList, description);
                break;
            }
            case 2:
                viewTasks(taskList);
                break;
            case 3: {
                int index;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> index;
                markTaskCompleted(taskList, index);
                break;
            }
            case 4: {
                int index;
                cout << "Enter the index of the task to remove: ";
                cin >> index;
                removeTask(taskList, index);
                break;
            }
            case 5:
                cout << "Thank you for using the To-Do List Program!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
