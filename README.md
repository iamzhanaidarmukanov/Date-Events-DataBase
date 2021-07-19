# Date-Events-DataBase
A simple Date - Events Database in C++
Write a C ++ program that implements work with a simple database (abbreviated as "DB"). The program will communicate with the user via standard input and output (stdin and stdout streams).

We will store pairs of the following type in our database: date, event. Let's define the date as a string of the Year-Month-Day type, where Year, Month and Day are integers.

The event is defined as a string of arbitrary printable characters without delimiters inside (spaces, tabs, etc.). The event cannot be an empty string. Many different events can occur on the same date, the database must be able to save them all. It is not necessary to save identical events that occurred on the same day: it is enough to save only one of them.

Our database must understand certain commands in order to interact with it:

- adding an event: Add Date Event
- delete event: Del Date Event
- deleting all events for a specific date: Del Date
- search for events for a specific date: Find Date
- printing of all events for all dates: Print

All commands, dates and events are separated by spaces as you type. Commands are read from standard input. There can be exactly one command on one line, but you can enter multiple commands on multiple lines. Blank lines can also come in - ignore them and continue processing new commands on subsequent lines.

Add event (Add Date Event)
When adding an event, the database must remember it and then show it when searching (using the Find command) or printing (using the Print command). If the specified event already exists for the given date, re-adding it should be ignored. If the input is correct (see the section "Handling Input Errors"), the program should not display anything on the screen.

Delete event (Del Date Event)
The command must remove the previously added event with the specified name on the specified date, if it exists. If the event is found and deleted, the program should print the string "Deleted successfully" (without quotes). If the event is not found on the specified date, the program should display the string "Event not found" (without quotes).

Delete multiple events (Del Date)
The command removes all previously added events for the specified date. The program should always output a string like "Deleted N events", where N is the number of all found and deleted events. N can be zero if there were no events on the specified date.

Event Search (Find Date)
Find and print previously added events on a specified date. The program should only print the events themselves, one per line. Events must be sorted in ascending order in the order of string comparison among themselves (string type).

Print all events (Print)
Using this command, you can show the complete contents of our database. The program should print all Date Event pairs, one per line. All pairs must be sorted by date, and events within the same date must be sorted in ascending order in the order of comparing strings with each other (string type). Dates must be formatted in a special way: YYYY-MM-DD, where G, M, D are the numbers of the numbers of the year, month and day, respectively. If a number has fewer digits, then it must be padded with zeros, for example, 0001-01-01 - January 1st of the first year. You don't need to output a date with a negative year value.

Handling Input Errors
The input in this task is not always correct: your program must handle some input errors correctly.

What input errors need to be handled
If the user entered an unknown command, then the program should report this by displaying the line "Unknown command: COMMAND", where COMMAND is the command entered by the user. The command is the first word in the line (up to a space).

If the date does not correspond to the Year-Month-Day format, where Year, Month and Day are arbitrary integers, then the program should print "Wrong date format: DATE", where DATE is what the user entered instead of the date (before a space). Please note that the parts of the date are separated by exactly one hyphen, and the date itself should not contain extra characters either before the year or after the day. Date parts cannot be empty, but can be zero or even negative.

Example input:
Add 0-1-2 event1

Add 1-2-3 event2

Find 0-1-2

Del 0-1-2

Print

Del 1-2-3 event2

Del 1-2-3 event2


Output:

event1

Deleted 1 events

0001-02-03 event2

Deleted successfully

Event not found
