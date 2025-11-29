#include "AeroflotManager.h"


AeroflotManager::AeroflotManager(){
    size = 0;
    capacity = 10;
    flights = new Aeroflot[capacity];

}

AeroflotManager::~AeroflotManager(){
    cout << "Aeroflot Manager destructor called for Aeroflot Manager system" << endl;
    delete[] flights;
    flights = nullptr;
}

void AeroflotManager::addFlight(){
    try{
        if (size >= capacity){
            resize();
        }

        string dest, type_p;

        cout << "Adding new flight" << endl;
        cout << "Enter the destination: ";
        getline(cin, dest);

        cout << "Enter the type of plane: ";
        getline(cin, type_p);

        if (dest.empty()){
            throw invalid_argument("Error: Destination cant be empty");
        }

        if (type_p.empty()){
            throw invalid_argument("Error: Plane type cant be empty");
        }

        Aeroflot newFlight(dest, size + 1, type_p);

        flights[size] = newFlight;
        size++;


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


void AeroflotManager::sortByDestination() const {
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

    sortByDestination();
    
    cout << "ALL FLIGHTS:" << endl;
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

void AeroflotManager::removeFlight(){
    if (size == 0){
        cout << "No flight to remove" << endl;
        return;
    }

    int flightNumber;
    cout << "Enter flight number to remove: ";
    cin >> flightNumber;

    bool found = false;

    for (int i = 0; i < size; i ++){
        if (flights[i].getFlightNumber() == flightNumber){
            for (int j = i; j < size - 1; j++){
                flights[j] = flights[j + 1];
            }

            size--;
            found = true;
            cout << "Flight " << flightNumber << " successfully removed." << endl;
            break;
        }
    }
}