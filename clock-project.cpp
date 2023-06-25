// Name: Mahtab Masud Beplab
// 12 hour and 24 hour clock format project


#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

class Clock {
private:
    int hour;
    int minute;
    int second;

public:
    Clock(int h, int m, int s) : hour(h), minute(m), second(s) {}

    // Function to add a second
    void addSecond() {
        second++;
        if (second >= 60) {
            second = 0;
            addMinute();
        }
    }

    // Function to add a minute
    void addMinute() {
        minute++;
        if (minute >= 60) {
            minute = 0;
            addHour();
        }
    }

    // Function to add an hour
    void addHour() {
        hour++;
        if (hour >= 24) {
            hour = 0;
        }
    }

    // Function to format numbers as two digits
    string format(int num) {
        stringstream ss;
        ss << setw(2) << setfill('0') << num;
        return ss.str();
    }

    // Function to display time in 24-hour format
    void display24HourFormat() {
        cout << format(hour) << ":" << format(minute) << ":" << format(second) << " (24 hour format)" << endl;
    }

    // Function to display time in 12-hour format
    void display12HourFormat() {
        int displayHour = hour;
        string am_pm = "AM";
        if (displayHour >= 12) {
            am_pm = "PM";
            if (displayHour > 12) displayHour -= 12;
        }
        if (displayHour == 0) displayHour = 12;
        cout << format(displayHour) << ":" << format(minute) << ":" << format(second) << " " << am_pm << " (12 hour format)" << endl;
    }
};



// Function to repeat '*' for formatting output
void printStarLine(int count) {
    for (int i = 0; i < count; i++) {
        cout << "*";
    }
    cout << endl;
}

// Function to display menu
void displayMenu() {
    printStarLine(30);
    cout << "1. Add Hour\n";
    cout << "2. Add Minute\n";
    cout << "3. Add Second\n";
    cout << "4. Exit\n";
    printStarLine(30);
}

int main() {
    int h, m, s;

    cout << "Enter initial time (HH MM SS): ";
    cin >> h >> m >> s;

    Clock clock(h, m, s);

    while (true) {
        clock.display12HourFormat();
        clock.display24HourFormat();

        displayMenu();

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            clock.addHour();
            break;
        case 2:
            clock.addMinute();
            break;
        case 3:
            clock.addSecond();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}



