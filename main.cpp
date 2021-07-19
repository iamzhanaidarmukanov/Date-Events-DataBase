//
//  Created by Zhanaidar Mukanov
//  Copyright © 2021 Zhanaidar Mukanov. All rights reserved.
//

// All Required Libraries
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;



// Creating Date structure
struct Date
{
    int day;
    int month;
    int year;
};

// Operator for same dates
bool operator == (const Date& first, const Date& second) {
    return (first.day == second.day && first.month == second.month && first.year == second.year);
}
// Operator for different dates
bool operator != (const Date& first, const Date& second) {
    return (first.day != second.day || first.month != second.month || first.year != second.year);
}
// Operator for comparing dates
bool operator < (const Date& first, const Date& second) {
    if (first.year == second.year) {
        if (first.month == second.month) {
            return first.day < second.day;
        }
        return first.month < second.month;
    }
    return first.year < second.year;
}



// Creating Date - Event structure
struct Date_Event
{
    Date date;
    string event;
};

// Operator for same date-event
bool operator == (const Date_Event& first, const Date_Event& second) {
    return (first.date.day == second.date.day 
    && first.date.month == second.date.month 
    && first.date.year == second.date.year 
    && first.event == second.event);
}

bool operator != (const Date_Event& first, const Date_Event& second) {
    return (first.date.day != second.date.day 
    || first.date.month != second.date.month 
    || first.date.year != second.date.year 
    || first.event != second.event);
}

// Operator for comparing date-event
bool operator < (const Date_Event& first, const Date_Event& second) {
    if (first.date.year == second.date.year) {
        if (first.date.month == second.date.month) {
            if (first.date.day == second.date.day) {
                return first.event < second.event;
            }
            return first.date.day < second.date.day;
        }
        return first.date.month < second.date.month;
    }
    return first.date.year < second.date.year;
}



// Start of the main function
int main(int argc, const char *argv[])
{

    // For database will be using
    // vector data structure
    vector<Date_Event> Database;

    // Queries will be assined to this variable
    string query;

    // In the infinite loop will be catching exceptions
    try
    {
        // Start of the infinite loop
        while (cin >> query)
        {

            // Implementing Add Function
            if (query == "Add")
            {
                int d, m, y;
                string input_event;
            }

            // Implementing Delete Funtion
            else if (query == "Del")
            {
                int d, m, y;
                string input_event;
            }

            // Implementing Find Function
            else if (query == "Find")
            {
                int d, m, y;
                string dateLine;
            }

            // Implementing Print Function
            else if (query == "Print")
            {
            }

            // If query is invalid
            else
            {
                throw invalid_argument("Unknown command: " + query);
            }
        }
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
        return -1;
    }
    return 0;
}