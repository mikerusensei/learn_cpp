// Todo List Application
// January 10, 2024
// By: mikerusensei

#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class Task {
    public:
        string name, date;
        // Constructor
        Task(string todo_name, string todo_date){
            name = todo_name;
            date = todo_date;
        }
};

void Enter_Task(vector<Task>& taskList){
    // Variables
    string todo_name, todo_date;

    // Inputs
    cout << "[ENTER TASK]\n" << endl;

    cout << "Enter task name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, todo_name);

    cout << "Enter task date: ";
    getline(cin, todo_date);

    Task newTask(todo_name, todo_date);
    taskList.push_back(newTask);
    cout << "Task added successfully!" << endl;
};

void View_Tasks(const vector<Task>& taskList){
    if (taskList.empty()){
        cout << "No task available!" << endl;
    } else{
        cout << "[VIEWING TASK]" << endl;
        for (const Task& task: taskList){
            cout << "Name: " << task.name << endl;
            cout << "Date: " << task.date << endl;
        }
    }
};

int main(){
    int user_choice;
    vector<Task> taskList;

    while (true){
        cout << "Welcome to Task Manager" << endl << endl;

        cout << "[1] Enter Task" << endl;
        cout << "[2] View Task" << endl;
        cout << "[3] Exit Program" << endl;
        cout << "Enter Choice: ";
        //cin >> user_choice;

        while (!(cin >> user_choice)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a numeric choice: ";
        }

        if (user_choice == 1){
            Enter_Task(taskList);
        } else if (user_choice == 2){
            View_Tasks(taskList);
        } else if (user_choice == 3){
            cout << "Exiting Program";
            break;
        }else{
            cout << "Error: Invalid input" << endl;
        }
    }
    return 0;
}