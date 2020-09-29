#include <iostream>
#include <vector>
#include "backlog.h"

using namespace std;

void printMenu(backlog& log);

int main() {

    int choice;

    //create a backlog
    backlog log;
    createBacklog(log);

    //boolean variable to control the loop
    bool looping = true;

    while (looping) {
        printMenu(log);

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "this is choice 1" << endl;

                break;
            case 2:
                cout << "this is choice 2" << endl;
                break;
            case 3:
                cout << "this is choice 3" << endl;
                break;
            case 4:
                cout << "this is choice 4" << endl;
                break;
            case 5:
                cout << "this is choice 5 goodbye" << endl;
                looping = false;
                break;
        }//end switch

        cout << endl;
    }//end while


    return 0;
}

void printMenu(backlog& log) {
    cout << "Welcome to your Backlog." << endl;
    cout << endl;

    //display whats on the current backlog
    displayBacklog(log);

    cout << endl;

    cout << "Enter a number to execute that command" << endl;
    cout << "1. Add an item to the backlog" << endl;
    cout << "2. Complete an item" << endl;
    cout << "3. Add an already completed item" << endl;
    cout << "4. Display completed items" << endl;
    cout << "5. End program" << endl;
}