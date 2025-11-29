#include <iostream>
#include "AeroflotManager.h"
#include "FileManager.h"
using namespace std;

//g++ -o program menu.cpp Aeroflot.cpp AeroflotManager.cpp FileManager.cpp

void showMenu() {
    cout << "\n=== MAIN MENU ===" << endl;
    cout << "1. Add flight" << endl;
    cout << "2. Show all flights" << endl;
    cout << "3. Find flight by type" << endl;
    cout << "4. Find flight by number" << endl;
    cout << "5. Find flight by destination" << endl;
    cout << "6. Remove flight" << endl;
    cout << "7. Process file (reverse sentences)" << endl;
    cout << "8. Exit" << endl;
    cout << "Choose option: ";
}

int main() {
    AeroflotManager manager;
    int choice;
    
    do {
        showMenu();
        cin >> choice;
        cin.ignore(); 
        
        switch (choice) {
            case 1:
                manager.addFlight();
                break;
            case 2:
                manager.showAllFlights();
                break;
            case 3:
                manager.findFlightByType();
                break;
            case 4:
                manager.findFlightByNumber();
                break;
            case 5:
                manager.findFlightByDestination();
                break;
            case 6:
                manager.removeFlight();
                break;
            case 7: {
                string filename;
                cout << "Enter filename: ";
                getline(cin, filename);
                FileManager::reverseSentences(filename);
                break;
            }
            case 8:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
        }
    } while (choice != 8);
    
    return 0;
}