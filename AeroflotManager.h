#pragma once 

#include <iostream>
#include <string>
#include "Aeroflot.h"
using namespace std;

class AeroflotManager{
    private:
        Aeroflot* flights;
        int size;
        int capacity;

    public:
        AeroflotManager();
        ~AeroflotManager();
        void addFlight();
        void sortByDestination() const;
        void findFlightByType()  const;
        void findFlightByNumber()  const;
        void findFlightByDestination()  const;
        void showAllFlights() const;
        void resize();
        void removeFlight();


};