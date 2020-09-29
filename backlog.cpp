//
// Created by aidan on 9/21/2020.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "backlog.h"
#include <vector>
using namespace std;

const string ONE_STAR =     "(*    )";
const string TWO_STAR =     "(**   )";
const string THREE_STAR =   "(***  )";
const string FOUR_STAR =    "(**** )";
const string FIVE_STAR =    "(*****)";



bool createBacklog(backlog &log) {
    //first lets initialize the number of finished and unfinished items to 0
    log.numFin = 0;
    log.numUnfin = 0;

    //also intialize the complete percentage to 0 since nothing has been completed
    log.completionPercent = 0.0;

    return true;
}

void destroy(backlog &log) {
    //sets the finished and unfinished counters back to zero to destroy the backlog
    log.numUnfin = 0;
    log.numFin = 0;
}

bool addBacklog(string name, string media, backlog &log) {

    //creates an item to be added to the unfinished list
    backlogItem newItem;
    newItem.name = name;
    newItem.media = media;

    //adds item to the unfinished list
    log.unfinished[log.numUnfin] = newItem;

    //iterate the number of unfinished items now in the list
    log.numUnfin++;

    return true;
}

bool completeItem(int itemIndex, int score, backlog &log) {

    //add the backlog item at itemIndex to the finished list
    log.finished[log.numFin] = log.unfinished[itemIndex];

    //delete from the unfinished list
    log.unfinished.erase(log.unfinished.begin()+(itemIndex-1));
    cleanUpList(log, itemIndex);

    //edit the newly finished item to have a score and change completion status to true;
    log.finished[log.numFin].score = score;
    log.finished[log.numFin].completionStatus = true;

    //decrement number of unfinished, increment num finished
    log.numUnfin--;
    log.numFin++;

    return true;
}

bool addCompleted(std::string name, std::string media, int score, backlog &log) {

    //creates new backlog item and gives it its name media etc
    backlogItem newItem;
    newItem.name = name;
    newItem.media = media;
    newItem.score = score;
    newItem.completionStatus = true;

    //adds the new item to finished list
    log.finished[log.numFin] = newItem;

    //iterates the number finished
    log.numFin++;

    return true;
}

void displayBacklog(backlog &log) {

    //prints out all the items on the backlog, name and media type

    if (log.numUnfin > 0) {
        for (int i = 0; i < log.unfinished.size(); i++) {
            cout << (i + 1) << ". " << log.unfinished[i].name << "\t" << log.unfinished[i].media << "\t" << endl;
        }
    }
    else {
        cout << "There is nothing on the backlog! Add something new." << endl;
    }
}

void displayCompleted(backlog &log) {

    //displays all items in the finished log, name media and score
    for (int i = 0; i < log.finished.size(); i++) {
        cout << (i+1) << ". " << log.finished[i].name << "\t" << log.finished[i].media << "\t";

        //switch case for printing the right amount of stars for the score :)
        switch (log.finished[i].score) {

            case 1:
                cout << ONE_STAR << endl;
                break;
            case 2:
                cout << TWO_STAR << endl;
                break;
            case 3:
                cout << THREE_STAR << endl;
                break;
            case 4:
                cout << FOUR_STAR << endl;
                break;
            case 5:
                cout << FIVE_STAR << endl;
                break;
        }
    }
}

double calcPercentage(int completed, int uncompleted) {
    double percentComplete = completed / uncompleted;

    return percentComplete;
}

void cleanUpList(backlog &log, int itemIndex) {

    //create temp backlog item to help getting all data continuous
    backlogItem temp;

    //moves the recently deleted backlog item down to the bottom of the list and putting all filled elements next to each other
    for (int i = itemIndex; i < log.unfinished.size(); i++) {

        temp = log.unfinished[i];
        log.unfinished[i] = log.unfinished[i+1];
        log.unfinished[i+1] = temp;
    }

}









