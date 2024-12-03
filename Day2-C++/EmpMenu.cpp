#include <iostream>
#include <limits>
#include <string>
#include "conio.h"
#include "stack.h"
#define UP 65
#define DOWN 66
#define EXTEND 27
#define BACK 127
#define ENTER 10
#define SIZE 100

using namespace std;

int Stack::stacksNum = 0;

Stack::Stack(int size) {
    items = new Employee[size];
    top = -1;
    this->size = size;
    stacksNum++;
}

int Stack::current(){
    return top;
}

int Stack::push(int id, const string& name, int salary) {
    if (top != size - 1) {
        top++;
        items[top].id = id;
        items[top].name = name;  
        items[top].salary = salary;
        return 1;
    } else {
        return 0; 
    }
}

Employee Stack::pop() {
    if (top == -1) {
        throw "Stack is empty";
    } else {
        return items[top--];
    }
}

void Stack::display() {
    clrscr();
    if (top == -1) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "All Employees:\n" << endl;
        for (int i = top; i >= 0; i--) {
            if (items[i].id >= 0){
                cout << " ID : "<< items[i].id <<endl;
                cout << " Name : "<< items[i].name <<endl;
                cout << " Salary : " << items[i].salary << endl;
                cout << "\n-------------------------------------------------------\n";
            }
        }
    }
}

Stack::~Stack() {
    delete[] items;
    stacksNum--;
}

void validPostiveInteger(int &input) {
    char loopExit = 0;
    while (!loopExit) {
        cout << "Enter number (should be a positive integer): ";

        if (cin >> input) {
            if (cin.peek() == '\n' && input > 0) {
                loopExit = 1;
            } else {
                cout << "Error: Input must be a positive integer. Please try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else {
            cout << "Error: Input must be a valid integer. Please try again." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void validAlphaString(string &input) { 
    char valid = 0; 
    while (!valid) {
        cout << "Enter a string (only alphabets and spaces are allowed): ";
        getline(cin, input); 
        
        valid = 1; 

        for (int i = 0; i < input.length() && valid; i++) {

            if (!((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || input[i] == ' ')) {
                cout << "Error: Input can only contain alphabets (A-Z, a-z) and spaces. Please try again." << endl;
                valid = 0; 
            }
        }
    }
}

void homePage(){
    clrscr();
    printf("\033[%d;%dH Employee Panel ", 5,0);
    printf("\033[%d;%dH Push ", 10,0);
    printf("\033[%d;%dH Pop", 15,0);
    printf("\033[%d;%dH Display", 20,0);
    printf("\033[%d;%dH Exit", 25,0);
}

int main() {
    int stackSize;
    cout << "Number of Employees" << endl;
    validPostiveInteger(stackSize);
    Stack emp(stackSize);
    char content = 'h';
    char line = 1;
    homePage();

    while(1) {
        while (kbhit()) { 
            getch();      
        }
        char col = line * 5 + 5;
        if (content == 'h') {
            homePage();
            if (line == 1) {
                printf("\033[%d;%dH \033[1;35m Push \033[0m", col, 0);
            } else if (line == 2) {
                printf("\033[%d;%dH \033[1;35m Pop \033[0m", col, 0);
            } else if (line == 3) {
                printf("\033[%d;%dH \033[1;35m Display \033[0m", col, 0);
            } else if (line == 4) {
                printf("\033[%d;%dH \033[1;35m Exit \033[0m", col, 0);
            }
        }

        char choice = getch();

        if (choice == EXTEND) {
            if (!kbhit()) {
                clrscr();
                return 0;
            }
            choice = getch();
            choice = getch();
        }

        switch(choice) {
        case UP:
            if (content == 'h') {
                line--;
                if (line == 0) line = 4;
            }
            break;

        case DOWN:
            if (content == 'h') {
                line++;
                if (line == 5) line = 1;
            }
            break;

        case ENTER:
            if (content == 'h') {
                clrscr();
                if (line == 1) {
                    if(emp.current() != stackSize-1){
                    
                        content = 'p';
                        clrscr();
                        int id;
                        cout<<"\nEnter ID \n";
                        validPostiveInteger(id);
                        while (kbhit()) { 
                            getch();     
                        }
                        string name;
                        cout<<"\nEnter Name \n ";
                        validAlphaString(name);
                        while (kbhit()) { 
                            getch();     
                        }
                        int salary;
                        cout<<"\nEnter salary \n";
                        validPostiveInteger(salary);
                        while (kbhit()) { 
                            getch();     
                        }
                            emp.push(id, name, salary);
                            cout << "\n Employee added.\n";
                            cout << " ID : "<< id <<endl;
                            cout << " Name : "<< name <<endl;
                            cout << " Salary : " << salary << endl;
                            cout << "\n-------------------------------------------------------\n";
                            cout << " You'll be moved out to the main panel after 10 sec" << endl;
                            fflush(stdout);
                            sleep(10);
                            content = 'h';
                        }
                        else{
                        cout<<"you've reached maximum number of Employees"<<endl;
                        cout << "You'll be moved out to the main panel after 5 sec" << endl;
                        sleep(5);
                        content = 'h';
                        }

                } else if (line == 2) {
                    clrscr();
                    if(emp.current() != -1){
                        Employee test = emp.pop();
                        cout << " ID : "<< test.id <<endl;
                        cout << " Name : "<< test.name <<endl;
                        cout << " Salary : " << test.salary << endl;
                        cout << "\n-------------------------------------------------------\n";
                        cout << "You'll be moved out to the main panel after 10 sec" << endl;
                        fflush(stdout);
                        sleep(10);
                    } else{
                        cout << "No Employees to remove." <<endl;
                        cout << "You'll be moved out to the main panel after 5 sec" << endl;
                        sleep(5);
                        }

     
                } else if (line == 3) {
                    content = 'p';
                    emp.display();
                    printf("\nPress BackSpace key to return to the menu.");
                } else if (line == 4) {
                    clrscr();
                    return 0;
                }
            }
            break;

        case BACK:
            if (content == 'i') {
                clrscr();
                content = 'h';
            } else if (content != 'h') {
                clrscr();
                content = 'h';
                line = 1;
            } else {
                clrscr();
                printf("Invalid Input (BackSpace to back to menu)\n");
                content = 'i';
            }
            break;

        default:
            clrscr();
            printf("Invalid Input (BackSpace to back to menu)\nUp, Down, Enter Only accepted & BackSpace to back");
            if (content != 'i') {
                content = 'i';
            }
            break;
        }
    }
}
