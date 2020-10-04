#include <iostream>
#include <vector>
#include <string>
#include "backlog.h"

using namespace std;

void printMenu(backlog& log);
void addItem(backlog& log);
void complete(backlog& log);

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
            case 1:     //this is adding a item to the backlog
                //cout << "this is choice 1" << endl;

                addItem(log);

                break;
            case 2:     //this is completing an item on the backlog
                //cout << "this is choice 2" << endl;

                complete(log);

                break;
            case 3:     //add directly to the completed list
                cout << "this is choice 3" << endl;
                break;
            case 4:     //display completed items
                cout << "this is choice 4" << endl;
                break;
            case 5:     //exit program
                cout << "this is choice 5 goodbye" << endl;
                looping = false;
                break;
        }//end switch

        cout << endl;
    }//end while

    destroy(log);
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

void addItem(backlog& log) {
    string name;
    string media;

    cout << "please enter the name of the new item: ";
    cin >> name;
    cout << endl;

    cout << "Please enter the name of the kind of media this item is: ";
    cin >> media;
    cout << endl;

    if (addBacklog(name, media, log)) {
        cout << name << " has been added to the backlog" << endl;
    }
    else {
        cout << "backlog addition failed" << endl;
    }
}

void complete(backlog &log) {
    int index;
    int score;

    if (log.numUnfin == 0) {
        cout << "Please add an item to the backlog first" << endl;
    }
    else {
        displayBacklog(log);
        cout << endl;

        cout << "Which item has been completed? Enter the number: ";
        cin >> index;
        cout << endl;

        cout << "What would you rate this title out of 5: ";
        cin >> score;
        cout << endl;

        completeItem(index, score, log);

        cout << getItemName(log, index) << " has been completed!" << endl;
    }
}