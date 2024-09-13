// ProjectOne_Farino.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Robert Farino
// CS 210 - Project One
// Southern New Hampshire University

#include <iostream>
#include <iomanip>
using namespace std;

// Function InputTime gets the time from the user. 
// It uses reference integers for hours, minutes, and seconds. 
void InputTime(int& hours, int& minutes, int& seconds) {

    // Prompt user for hours and generate error/set hours to 0 if hours are out of scope.
    cout << "Enter hours" << endl;
    cin >> hours;
    if (hours < 0 || hours > 23) {
        hours = 0;
        cout << "Invalid hours, setting to 0" << endl;
    }

    // Prompt user for minutes and generate error/set minutes to 0 if minutes are out of scope.
    cout << "Enter minutes" << endl;
    cin >> minutes;
    if (minutes < 0 || minutes > 59) {
        minutes = 0;
        cout << "Invalid minutes, setting to 0" << endl;
    }

    // Prompt user for seconds and generate error/set seconds to 0 if seconds are out of scope. 
    cout << "Enter seconds" << endl;
    cin >> seconds;
    if (seconds < 0 || seconds > 59) {
        seconds = 0;
        cout << "Invalid seconds, setting to 0" << endl;
    }
}

// This fuction displays 12 and 24-hour clocks based on the
// input hours, minutes, and seconds.
void PrintClock(int hours, int minutes, int seconds) {

    int hours12hrClock;

    // Calculate the hour for the 12-hour clock based
    // on the hours value in the range from 0-23.
    if (hours == 0)
        hours12hrClock = 12;
    else if (hours >= 13)
        hours12hrClock = hours - 12;
    else
        hours12hrClock = hours;

    // Print 12 and 24 hour clocks to screen.  
    cout << endl;
    cout << "**************************    **************************" << endl;
    cout << "*      12-Hour Clock     *    *      24-Hour Clock     *" << endl;
    cout << "*       " << setfill('0')

        // 12-Hour Clock
        << setw(2) << hours12hrClock << ":"
        << setw(2) << minutes << ":"
        << setw(2) << seconds << " "
        << ((hours >= 12) ? "PM" : "AM")
    
        << "      *    *        " 
        
        // 24-Hour Clock
        << setw(2) << hours << ":"
        << setw(2) << minutes << ":"
        << setw(2) << seconds << "        *" << endl;

    cout << "**************************    **************************" << endl;
    cout << endl;
}

// This function adds one hour to the clock time.
// The hours will be set to 0 if the hours exceed 23.
void AddOneHour(int& hours) {
    
    hours++;

    if (hours > 23) {
        hours = 0;
    }
}

// This function adds one minute to the clock time.
// The hours may be updated if the number of minutes exceeds 59,
// at which point the minutes are reset to 0.
void AddOneMinute(int& hours, int& minutes) {
    
    minutes++;

    if (minutes > 59) {
        minutes = 0;
        AddOneHour(hours);
    }
}

// This function adds one second to the clock time.
// The hours and minutes may be updated if the number of seconds exceeds 59,
// at which point the seconds are reset to 0.
void AddOneSecond(int& hours, int& minutes, int& seconds) {
    
    seconds++;

    if (seconds > 59) {
        seconds = 0;
        AddOneMinute(hours, minutes);
    }
}




int main()
{
    int hours;
    int minutes;
    int seconds;
    int menuChoice = 0;

    // Get time from end user.
    InputTime(hours, minutes, seconds);

    while (menuChoice != 4) {
     
        // Display menu for end user to select from.  
        cout << "**************************" << endl;
        cout << "* 1 - Add One Hour       *" << endl;
        cout << "* 2 - Add One Minute     *" << endl;
        cout << "* 3 - Add One Second     *" << endl;
        cout << "* 4 - Exit Program       *" << endl;
        cout << "**************************" << endl;
        
        // Read in menuChoice values provided by end user.
        cin >> menuChoice;

        if (menuChoice == 1) {

            // Add one hour to the clock time.
            AddOneHour(hours);

            // Print 12 and 24-hour clocks.
            PrintClock(hours, minutes, seconds);
        }
        else if (menuChoice == 2) {

            // Add one minute to the clock time.
            AddOneMinute(hours, minutes);

            // Print 12 and 24-hour clocks.
            PrintClock(hours, minutes, seconds);
        }
        else if (menuChoice == 3) {

            // Add one second to the clock time.
            AddOneSecond(hours, minutes, seconds);

            // Print 12 and 24-hour clocks.
            PrintClock(hours, minutes, seconds);
        }
    }
}  
