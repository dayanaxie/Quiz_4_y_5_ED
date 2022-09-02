#include <iostream>
#include <string>
#include <ctime>


using namespace std;

#ifndef EVENT

#define EVENT 1


class Event {
private:
    tm eventTime;
    string title;
    string location;
    string organizer;

public:
    Event(string pTitle, string pLocation, string pOrganizer) {
        this->title = pTitle;
        this->location = pLocation;
        this->organizer = pOrganizer;
    }

    string getTitle() {
        return title;
    }

    string getLocation() {
        return location;
    }
};

#endif