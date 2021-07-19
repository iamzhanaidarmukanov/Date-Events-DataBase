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

// For Sorting my Database
bool compare_Date_Events(const Date_Event& first, const Date_Event& second) {
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


// Parsing Date input from the date string
void parseDate(const string& dateLine, int& y, int& m, int& d) {
    stringstream ss(dateLine);
    string error = "Wrong date format: " + dateLine;
    if(!(ss >> y)) {
        throw invalid_argument(error);
    }
    if (ss.peek() != '-') {
        throw invalid_argument(error);
    }
    ss.ignore(1);
    if(!(ss >> m)) {
        throw invalid_argument(error);
    }
    if (ss.peek() != '-') {
        throw invalid_argument(error);
    }
    ss.ignore(1);
    if(!(ss >> d)) {
        throw invalid_argument(error);
    }
    if(!ss.eof()) {
        throw invalid_argument(error);
    }
    if(m < 1 || m > 12) {
        throw invalid_argument("Month value is invalid: " + to_string(m));
    }
    if(d < 1 || d > 31) {
        throw invalid_argument("Day value is invalid: " + to_string(d));
    }
}


// Assigning Date
Date getDate(const string& dateLine, int& y, int& m, int& d) {
    parseDate(dateLine, y, m, d);
    Date date = {d, m, y};
    return date;
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
                string dateLine;
                string freeSpace;
                getline(cin, freeSpace, ' ');
                getline(cin, dateLine, ' ');
                cin >> input_event;
                Date input_date;
                input_date = getDate(dateLine, y, m, d);
                Date_Event input_date_event = {input_date, input_event};
                
                if (Database.size() == 0) {
                    Database.push_back(input_date_event);
                }
                
                else {
                    bool flag = false;
                    for (const auto& x : Database) {
                        if (x == input_date_event) {
                            flag = true;
                        }
                    }
                    if (!flag) {
                        Database.push_back(input_date_event);
                        sort(Database.begin(), Database.end(), compare_Date_Events);
                    }
                }
            }

            // Implementing Delete Funtion
            else if (query == "Del")
            {
                int d, m, y;
                string input_event;
                string line;
                string freeSpace;
                getline(cin, freeSpace, ' ');
                getline(cin, line);
                stringstream myStream(line);
                bool isThereEvent = true;
                string dateLine;
                myStream >> dateLine;
                if (myStream.eof()) {
                    isThereEvent = false;
                }
                Date input_date;
                input_date = getDate(dateLine, y, m, d);
                Date_Event input_date_event = {input_date, input_event};
                
//                if Del is with event
                if (isThereEvent) {
                    myStream >> input_event;
                    Date_Event input_date_event = {input_date, input_event};
                    bool flag = false;
                    int index = 0;
                    for (int i = 0; i < Database.size(); ++i) {
                        if (Database[i] == input_date_event) {
                            flag = true;
                            index = i;
                            cout << "Deleted successfully" << endl;
                            break;
                        }
                    }
                    if (flag) {
                        Database.erase(Database.begin() + index);
                    } else {
                        cout << "Event not found" << endl;
                    }
                }
                
//                If Del is without event
                else {
                    int start = 0;
                    bool flag = false;
                    for (const auto& x : Database) {
                        if (x.date == input_date) {
                            flag = true;
                        }
                    }
                    
                    if (flag) {
                        while (Database[start].date != input_date) {
                            start++;
                        }
                        int finish = start;
                        while (Database[finish].date == input_date && finish <= Database.size() - 1) {
                            finish++;
                        }
                        Database.erase(Database.begin() + start, Database.begin() + finish);
                        cout << "Deleted " << finish - start << " events" << endl;
                        
                        
                    }
                    else {
                        cout << "Deleted 0 events" << endl;
                    }
                }
            }

            // Implementing Find Function
            else if (query == "Find")
            {
                int d, m, y;
                string dateLine;
                string freeSpace;
                getline(cin, freeSpace, ' ');
                getline(cin, dateLine);
                Date input_date;
                input_date = getDate(dateLine, y, m, d);
                for (const auto& x : Database) {
                    if (x.date == input_date) {
                        cout << x.event << endl;
                    }
                }
            }

            // Implementing Print Function
            else if (query == "Print")
            {
                for (const auto& x : Database) {
                    cout << setfill('0');
                    cout << setw(4) << x.date.year;
                    cout << "-";
                    cout << setw(2) << x.date.month;
                    cout << "-";
                    cout << setw(2) << x.date.day;
                    cout << " " << x.event << endl;
                }
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