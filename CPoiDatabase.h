//
// Created by Aniruddha on 4/25/2020.
//

#ifndef NAVIGATIONSYSTEMREVISION2_CPOIDATABASE_H
#define NAVIGATIONSYSTEMREVISION2_CPOIDATABASE_H

#include <bits/stdc++.h>
#include "CPoi.h"

using namespace std;

class CPoiDatabase
{

public:
    CPoiDatabase();
    void addPoi(CPoi const &poi);   //Add POI to CPoiDatabase
    CPoi *getPointerToPoi(string name); //Search for an element in the CPoiDatabase by it's name
    void print();

    map<const string, CPoi> m_PoiMap;
};


#endif //NAVIGATIONSYSTEMREVISION2_CPOIDATABASE_H
