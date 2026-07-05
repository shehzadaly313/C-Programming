#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int number;
    int amount = 0, count = 0;
    int r = 0, b = 0, c = 0, j = 0, v = 0;
    const int totalSpaces = 50;  // Max parking capacity
    bool slots[totalSpaces] = {false};  // false = free, true = occupied

    while (true) {
        cout << "\n--- Parking Menu ---" << endl;
        cout << "Press 1 for Rikshaw" << endl;
        cout << "Press 2 for Car" << endl;
        cout << "Press 3 for Bus" << endl;
        cout << "Press 4 for Jeep" << endl;
        cout << "Press 5 for Van" << endl;
        cout << "Press 6 to Show Records of the Day" << endl;
        cout << "Press 7 to Delete Records of the Day" << endl;
        cout << "Enter your choice: ";
        cin >> number;

        if (count >= totalSpaces && number >= 1 && number <= 5) {
            cout << "Parking full! No space available.\n";
            continue;
        }

        time_t now = time(0);
        char* dt = ctime(&now);  // current time as string

        // Find next available slot
        int slot = -1;
        for (int i = 0; i < totalSpaces; i++) {
            if (!slots[i]) {
                slot = i + 1; // slot number (1-indexed)
                slots[i] = true;
                break;
            }
        }

        if (number == 1) {
            amount += 100;
            count++;
            r++;
            cout << "Rikshaw parked successfully." << endl;
        }
        else if (number == 2) {
            amount += 200;
            count++;
            c++;
            cout << "Car parked successfully." << endl;
        }
        else if (number == 3) {
            amount += 300;
            count++;
            b++;
            cout << "Bus parked successfully." << endl;
        }
        else if (number == 4) {
            amount += 150;
            count++;
            j++;
            cout << "Jeep parked successfully." << endl;
        }
        else if (number == 5) {
            amount += 250;
            count++;
            v++;
            cout << "Van parked successfully." << endl;
        }
        else if (number == 6) {
            cout << "\n--- Parking Records ---" << endl;
            cout << "Total amount collected: " << amount << " Rs" << endl;
            cout << "Total vehicles parked: " << count << " out of " << totalSpaces << endl;
            cout << "Rikshaws parked: " << r << endl;
            cout << "Cars parked: " << c << endl;
            cout << "Buses parked: " << b << endl;
            cout << "Jeeps parked: " << j << endl;
            cout << "Vans parked: " << v << endl;
            continue;
        }
        else if (number == 7) {
            amount = 0;
            count = 0;
            r = b = c = j = v = 0;
            for (int i = 0; i < totalSpaces; i++) {
                slots[i] = false;
            }
            cout << "All records cleared!" << endl;
            continue;
        }
        else {
            cout << "Invalid option. Please try again." << endl;
            continue;
        }
        // Show time and slot number
        cout << "Time parked: " << dt;
        cout << "Vehicle assigned to slot number: " << slot << endl;
    }

    return 0;
}
