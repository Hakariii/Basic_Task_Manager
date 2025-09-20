#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void addTask(std::vector<std::string>& tasks, const std::string& task) {
    tasks.push_back(task);
    std::cout << "Task added: " << task << std::endl;
}
void showTasks(std::vector<std::string>& tasks){
    std::cout<<"Your tasks"<<std::endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i] << std::endl;
    }
}
void deleteTask(std::vector<std::string>& tasks, int taskNumber){
    if (taskNumber > 0 && taskNumber <= tasks.size()){
        std::cout<<"Task deleted:"<<tasks[taskNumber-1]<<std::endl;
        tasks.erase(tasks.begin()+taskNumber-1);
    }
    else{
        std::cout<<"Invalid task number"<<std::endl;
}
}
void findTask(std::vector<std::string>& tasks, std::string task){
    std::cout<<"Search results:"<<std::endl;
    for( size_t i= 0; i< tasks.size();i++){
        if(tasks[i].find(task) != std::string::npos){
            std::cout<<i+1<<". "<<tasks[i]<<std::endl;
        }
    }

}

int main(){
    std::ifstream readFile("tasks.txt");

    int choice, taskNumber;
    std::vector<std::string> tasks;
    std::string task;
    while (std::getline(readFile, task)) {
        tasks.push_back(task);
    }
    while(true){
    std::cout<<"Hi, this is Task Manager"<<std::endl<<"1 - Add Task"<<std::endl<<"2 - View Tasks"<<std::endl<<"3 - Delete Task"<<std::endl<<"4 - Find Task:"<<std::endl<<"5 - Exit"<<std::endl;
    std::cin>>choice;
    std::cin.ignore();
    switch (choice){
    case 1: {
        std::cout<<"Enter your task:";
        std::getline(std::cin, task);
        addTask(tasks, task);
        break;
    }
    case 2: {
        showTasks(tasks);
        break;
    }
    case 3: {
        std::cout<<"Enter task number to delete:";
        std::cin>>taskNumber;
        std::cin.ignore();
        deleteTask(tasks, taskNumber);
        break;
    }
    case 4: {
        std::cout<<"Enter task name to find:";
        std::getline(std::cin, task);
        findTask(tasks, task);
        break;
    }
    case 5: {
        readFile.close();
        std::ofstream file("tasks.txt");
        for (size_t i = 0; i < tasks.size(); i++) {
            file << tasks[i] << std::endl;

        }
        file.close();

        std::cout<<"Exiting Task Manager. Goodbye!"<<std::endl;
        return 0;
        break;
    }
    default: {
        std::cout<<"Invalid choice, please try again."<<std::endl;
        break;
    }
}
}
}
