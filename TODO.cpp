#include <iostream>
using namespace std;

const int MAX_TASKS = 10;
struct Task
{
    string description;
    bool completed;
};

Task todoList[MAX_TASKS];
int taskCount = 0;

void addTask()
{
    if (taskCount >= MAX_TASKS)
    {
        cout << "Task list is full!\n";
        return;
    }
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, todoList[taskCount].description);
    todoList[taskCount].completed = false;
    taskCount++;
    cout << "Task added!\n";
}

void viewTasks()
{
    if (taskCount == 0)
    {
        cout << "No tasks available.\n";
    }
    else
    {
        for (int i = 0; i < taskCount; i++)
        {
            cout << i + 1 << ". " << todoList[i].description;
            cout << (todoList[i].completed ? " [Completed]" : " [Pending]") << endl;
        }
    }
}

void markCompleted()
{
    int taskNumber;
    cout << "Enter task number to mark as completed: ";
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= taskCount)
    {
        todoList[taskNumber - 1].completed = true;
        cout << "Task marked as completed.\n";
    }
    else
    {
        cout << "Invalid task number.\n";
    }
}

void deleteTask()
{
    int taskNumber;
    cout << "Enter task number to delete: ";
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= taskCount)
    {

        for (int i = taskNumber - 1; i < taskCount - 1; i++)
        {
            todoList[i] = todoList[i + 1];
        }
        taskCount--;
        cout << "Task deleted.\n";
    }
    else
    {
        cout << "Invalid task number.\n";
    }
}

int main()
{
    int choice;
    do
    {
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Delete Task\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addTask();
            break;
        case 2:
            viewTasks();
            break;
        case 3:
            markCompleted();
            break;
        case 4:
            deleteTask();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
