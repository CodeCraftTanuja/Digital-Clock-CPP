#include <iostream>
#include <ctime>
#include <iomanip>
#include <windows.h>

using namespace std;

// Function to print customized border
void drawHorizontalBorder(int width, char symbol) {
    for (int idx = 0; idx < width; idx++) {
        cout << symbol;
    }
    cout << endl;
}

int main() {
    bool use24HourFormat = false;
    char userChoice;

    cout << "========================================" << endl;
    cout << "    REAL-TIME DIGITAL DASHBOARD SETUP   " << endl;
    cout << "========================================" << endl;
    cout << "Do you prefer 24-hour layout? (y/n): ";
    cin >> userChoice;

    if (userChoice == 'y' || userChoice == 'Y') {
        use24HourFormat = true;
    }

    cout << "\n[Initializing core layout engine... Please wait]" << endl;
    
    
    Sleep(800);

    while (true) {
        
        system("cls");

        // Fetching system calendar & time metrics
        time_t rawSystemTime = time(0);
        tm* localizedTime = localtime(&rawSystemTime);

        int rawHour = localizedTime->tm_hour;
        int currentMinute = localizedTime->tm_min;
        int currentSecond = localizedTime->tm_sec;
        string amPmIndicator = "";

        // Converting logic for 12-hour setting
        if (!use24HourFormat) {
            amPmIndicator = (rawHour >= 12) ? " PM" : " AM";
            rawHour = rawHour % 12;
            if (rawHour == 0) {
                rawHour = 12; // Adjusting midnight/noon index
            }
        }

        // Custom ASCII-style Dashboard rendering
        cout << "\n\n";
        cout << "\t"; drawHorizontalBorder(33, '*');
        cout << "\t* SYSTEM CHRONOMETER STATUS     *" << endl;
        cout << "\t"; drawHorizontalBorder(33, '-');
        
        // Formatted Time output
        cout << "\t* " 
             << setfill('0') << setw(2) << rawHour << " : "
             << setfill('0') << setw(2) << currentMinute << " : "
             << setfill('0') << setw(2) << currentSecond
             << amPmIndicator << "      *" << endl;
             
        cout << "\t"; drawHorizontalBorder(33, '-');
        
        // Date tracking logic
        cout << "\t* Date: " 
             << setfill('0') << setw(2) << localizedTime->tm_mday << "/"
             << setfill('0') << setw(2) << (localizedTime->tm_mon + 1) << "/"
             << (localizedTime->tm_year + 1900) << "            *" << endl;
             
        cout << "\t"; drawHorizontalBorder(33, '*');
        cout << "\n\t[Press Ctrl + C inside Terminal to exit]" << endl;

        
        Sleep(1000);
    }

    return 0;
}