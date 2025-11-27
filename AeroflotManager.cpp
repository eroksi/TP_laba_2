#include "AeroflotManager.h"


AeroflotManager::AeroflotManager(){
    size = 0;
    capacity = 10;
    flights = new Aeroflot[capacity];

}

AeroflotManager::~AeroflotManager(){
    cout << "Hero destructor called for Aeroflot Manager system" << endl;
    delete[] flights;
    flights = nullptr;
}

void AeroflotManager::addFlight(){
    try{
        if (size >= capacity){
            resize();
        }

        Aeroflot newFlight;

        cout << "Adding new flight" << endl;
        cin >> newFlight;

        if (newFlight.getFlightNumber() < 0){
            throw invalid_argument("Error: Number of flight must be pozitive");
        }

        if (newFlight.getDestination().empty()){
            throw invalid_argument("Error: Destination cant be empty");
        }

        if (newFlight.getTypePlane().empty()){
            throw invalid_argument("Error: Plane type cant be empty");
        }

        flights[size] = newFlight;
        size++;

        sortByDestination();

        cout << "Flight is saved!!" << endl;
        }

    catch(const exception& e){
        cout << e.what() << endl;
        cout << "Error: Flight wasn't saved." << endl;
        cin.clear();
        cin.ignore(10000, '\n');

    }

  
}

void AeroflotManager::resize(){

    try{
    int newCapacity = capacity * 2;
    Aeroflot* newFlights = new Aeroflot[newCapacity];

    for (int i = 0; i < size; i++){
        newFlights[i] = flights[i];
    }

    delete[] flights;

    flights = newFlights;
    capacity = newCapacity;
}

catch(const bad_alloc& e){
    throw runtime_error("Error of increasing massive");
}
}


void AeroflotManager::sortByDestination() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (flights[j].getDestination() > flights[j + 1].getDestination()) {
                Aeroflot temp = flights[j];
                flights[j] = flights[j + 1];
                flights[j + 1] = temp;
            }
        }
    }
}

void AeroflotManager::showAllFlights() const {
    if (size == 0) {
        cout << "There is no flights" << endl;
        return;
    }
    
    cout << "ALL FLIGHTS" << endl;
    for (int i = 0; i < size; i++) {
        cout << (i + 1) << ". " << flights[i];
    }

}

void AeroflotManager::findFlightByType() const {
    if (size == 0) {
        cout << "No flights" << endl;
        return;
    }
    
    string searchType;
    cout << "Enter the type of plane: ";
    cin.ignore();
    getline(cin, searchType);
    
    bool found = false;
    cout << "Flights: " << searchType << endl;
    
    for (int i = 0; i < size; i++) {
        if (flights[i].getTypePlane() == searchType) {
            cout << flights[i];
            found = true;
        }
    }
    
    if (!found) {
        cout << "There is no flights with '" << searchType << "' type of plane" << endl;
    }
}

void AeroflotManager::findFlightByNumber() const {
    if (size == 0) {
        cout << "There is no flights." << endl;
        return;
    }
    
    int searchNumber;
    cout << "Enter the number of flight: ";
    cin >> searchNumber;
    
    bool found = false;
    cout << "Search for flight № " << searchNumber << endl;
    
    for (int i = 0; i < size; i++) {
        if (flights[i].getFlightNumber() == searchNumber) {
            cout << flights[i];
            found = true;
            break;  
        }
    }
    
    if (!found) {
        cout << "Flight with number " << searchNumber << " not found." << endl;
    }

}

void AeroflotManager::findFlightByDestination() const {
    if (size == 0) {
        cout << "No flights for search." << endl;
        return;
    }
    
    string searchDest;
    cout << "Enter destination for search: ";
    cin.ignore();
    getline(cin, searchDest);
    
    bool found = false;
    cout << "Flights to" << searchDest << endl;
    
    for (int i = 0; i < size; i++) {
        if (flights[i].getDestination() == searchDest) {
            cout << flights[i];
            found = true;
        }
    }
    
    if (!found) {
        cout << "Flights to destination '" << searchDest << "' not found." << endl;
    }
}