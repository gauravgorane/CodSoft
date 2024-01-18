#include<iostream>
#include<fstream>

using namespace std;

void addtask(const string& task){
    ofstream outfile("tasks.txt", ios::app);
    if(outfile.is_open()) {
        outfile << "PENDING\t" << task << endl;
        outfile.close();
        cout << "\nTask added succesfully." << endl;
    }
    else{
        cout << "Error opening the file" << endl;
    }
}

void viewtasks(){
    ifstream inFile("tasks.txt");
    if(inFile.is_open()){
        cout << "\n===Tasks===\n" << endl;
        string line;
        int tasknumber = 1;
        while (getline(inFile, line))
        {
            cout << tasknumber << ". " << line << endl;
            tasknumber++;
        }
        inFile.close();
    }
    else{
        cout << "Error opening the file" << endl;
    }
}

void marktaskcompleted(int tasknumber){
    ifstream infile("tasks.txt");
    ofstream outfile("temp.txt");

    if(infile.is_open() && outfile.is_open()){
        string line;
        int currenttask = 1;

        while (getline(infile, line))
        {
            if(currenttask == tasknumber){
                outfile << "COMPLETED\t" << line.substr(line.find('\t') + 1) << endl;
                cout << "\nTask marked as completed.\n";
            }
            else{
                outfile << line << endl;
            }
            currenttask++;
        }
        infile.close();
        outfile.close();
        remove("tasks.txt");
        rename("temp.txt", "tasks.txt");
        viewtasks();
    }
    else{
        cout << "Error opening the file" << endl;
    }
}

void removetask(int tasknumber){
    ifstream infile("tasks.txt");
    ofstream outfile("temp.txt");

    if (infile.is_open() && outfile.is_open())
    {
        string line;
        int currenttask = 1;

        while (getline(infile, line)){
            if (currenttask != tasknumber){
                outfile << line << endl;
            }
            else {
                cout << "\nTask removed successfully.\n";
            }
            currenttask++;
        }
        infile.close();
        outfile.close();
        remove("tasks.txt");
        rename("temp.txt", "tasks.txt");
        viewtasks();
    }
    else{
        cout << "Error opening the file\n";
    }
    
}

int main(){

        int choice;
        string task;

    do{

        cout << "\n\t_____TO DO LIST_____\n" << endl;

        cout << "\t1. Add Task" << endl;
        cout << "\t2. View Task" << endl;
        cout << "\t3. Mark Task as completed" << endl;
        cout << "\t4. Remove Task" << endl;
        cout << "\t5. Exit" << endl;

        cout << "\n\tEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter new task: " << endl;
            cin.ignore();
            getline(cin, task);
            addtask(task);
            break;

        case 2:
            viewtasks();
            break;

        case 3:
            int tasknumber;
            cout << "\nEnter the task number to mark as completed: ";
            cin >> tasknumber;
            marktaskcompleted(tasknumber);
            break;

        case 4:
            cout << "\nEnter the task number to remove: ";
            cin >> tasknumber;
            removetask(tasknumber);
            break;

        case 5:
            cout << "\nExiting the program." << endl;
            break;
        
        default:
            cout << "\nInvalid Choice! Please enter a valid option." << endl;
        }
        
    } while (choice != 5);
    
    return 0;
}