//
// Created by aidan on 9/21/2020.
//

#ifndef BACKLOG_BACKLOG_H
#define BACKLOG_BACKLOG_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

struct backlogItem {
    std::string name;           //name of game, movie, show, etc
    std::string media;          //the type of media it is
    bool completionStatus;      //true for finished false for unfinished
    int score;                  //score out of 5 so i can display it as stars for fun :)
    int index;
};

struct backlog {
    std::vector <backlogItem> finished;         //vector that holds the finished items
    std::vector <backlogItem> unfinished;       //vector that holds the unfinished items
    int numUnfin;                           //number of items unfinished
    int numFin;                             //number of items finished
    double completionPercent;               //percentage of finished items over initial size of backlog
};

//function prototypes--------------------

//constructor
bool createBacklog(backlog &log);

//desctructor
void destroy(backlog &log);

//create a new backlog item, give it its name and media type. Also it to the array of unfinished items
bool addBacklog(std::string name, std::string media, backlog &log);

//edits a given backlogItem to be completed and give it a score. Item will be moved to the finished array
bool completeItem(int itemIndex, int score, backlog &log);

//manually add an item to the completed array
bool addCompleted(std::string name, std::string media, int score, backlog &log);

//display the contents of the backlog
void displayBacklog(backlog &log);

//display contents of the completed log
void displayCompleted(backlog &log);

//calculate the percentage of completed items
double calcPercentage(int completed, int uncompleted);

//clean up any blank spaces in the list
void cleanUpList(backlog &log, int itemIndex);

//return the name of an item at the index in the backlog
std::string getItemName(backlog &log, int index);



#endif //BACKLOG_BACKLOG_H
