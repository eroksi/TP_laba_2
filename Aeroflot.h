#pragma once 

#include <iostream>
#include <string>
using namespace std;

class Aeroflot{
    private:
        string destination;
        int flight_number;
        string type_aeroplane;

    public:
        Aeroflot();
        Aeroflot(
            string destination,
            int flight_number,
            string type_aeroplane
        );
        Aeroflot(const Aeroflot& other);
        ~Aeroflot();

        void print() const;

        string getDestination() const;
        int getFlightNumber() const;
        string getTypePlane() const;

        void setDestination(string end_point);
        void setFlightNumber(int num);
        void setTypePlane(string type_p);

        friend istream& operator>>(istream& in, Aeroflot& aero);
        friend ostream& operator<<(ostream& out, const Aeroflot& aero);


};

