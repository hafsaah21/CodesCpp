#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 10;
string tasks[MAX_TASKS];
bool taskDone[MAX_TASKS] = {false};
int numTasks = 0;

void addTask(const string& task) {
    if (numTasks < MAX_TASKS) {
        tasks[numTasks] = task;
        numTasks++;
        cout << "Task added successfully!\n";
    } else {
        cout << "Task list is full. Cannot add more tasks.\n";
    }
}

void showList() {
    cout << "To-Do List:\n";
    for (int i = 0; i < numTasks; i++) {
        cout << i + 1 << ". ";
        if (taskDone[i]) {
            cout << "[X] ";
        } else {
            cout << "[ ] ";
        }
        cout << tasks[i] << endl;
    }
}

void markDone(int index) {
    if (index >= 1 && index <= numTasks) {
        taskDone[index - 1] = true;
        cout << "Task marked as done!\n";
    } else {
        cout << "Invalid task number. Please try again.\n";
    }
}

void deleteTask(int index) {
    if (index >= 1 && index <= numTasks) {
        for (int i = index - 1; i < numTasks - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        numTasks--;
        cout << "Task deleted successfully!\n";
    } else {
        cout << "Invalid task number. Please try again.\n";
    }
}

int main() {
    int choice;
    string task;
    int taskNum;

    do {
        cout << "\n1. Add Task\n2. Show List\n3. Mark Task as Done\n4. Delete a Task \n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore(); 
                cout << "Enter task description: ";
                getline(cin, task);
                addTask(task);
                break;
            case 2:
                showList();
                break;
            case 3:
                cout << "Enter the task number to mark as done: ";
                cin >> taskNum;
                markDone(taskNum);
                break;
            case 4:
                cout << "Enter the task number to delete: ";
                cin >> taskNum;
                deleteTask(taskNum);
                break;

            case 5:
                cout << "Terminating program.\nProgram Terminated!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
