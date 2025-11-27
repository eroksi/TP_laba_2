#include "Aeroflot.h"

Aeroflot::Aeroflot(){
    destination = "Unknown";
    flight_number = -1;
    type_aeroplane = "Unknown";
}

Aeroflot::Aeroflot(string end_point, int num, string type){
    destination = end_point;
    flight_number = num;
    type_aeroplane = type;
}

Aeroflot::Aeroflot(const Aeroflot& other){
    destination = other.destination;
    flight_number = other.flight_number;
    type_aeroplane = other.type_aeroplane;

}

Aeroflot::~Aeroflot(){
    cout << "Hero destructor called for the flight number: " << getFlightNumber() << endl;
}

int Aeroflot::getFlightNumber() const{
    return flight_number;
}

string Aeroflot::getDestination() const {
    return destination;
}

string Aeroflot::getTypePlane() const {
    return type_aeroplane;
}


void Aeroflot::print() const{
    cout << "FLIGHT INFO" << endl;
    cout << "Number of the flight is " << flight_number << endl;
    cout << "Destination of the flight is " << getDestination() << endl;
    cout << "Type of plane is " << getTypePlane() << endl;
    
}

void Aeroflot::setTypePlane(string type_p){
    type_aeroplane = type_p;
}

void Aeroflot::setDestination(string end_point){
    destination = end_point;
}

void Aeroflot::setFlightNumber(int num){
        flight_number = num;
}

istream& operator>>(istream& in, Aeroflot& aero){
    cout << "Enter the destination: ";
    getline(in, aero.destination);

    cout << "Enter the number of flight: ";
    in >> aero.flight_number;

    cout << "Enter the type of plane: ";
    in.ignore();
    getline(in, aero.type_aeroplane);

    return in;
}

ostream& operator<<(ostream& out, const Aeroflot& aero){
    out << "Flight: " << aero.flight_number << " to " << aero.destination << " (Plane: " << aero.type_aeroplane << ")" << endl;
    return out;
}