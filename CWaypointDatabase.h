//
// Created by Aniruddha on 4/25/2020.
//

#ifndef NAVIGATIONSYSTEMREVISION2_CWAYPOINTDATABASE_H
#define NAVIGATIONSYSTEMREVISION2_CWAYPOINTDATABASE_H

#include <bits/stdc++.h>
#include "CWaypoint.h"
using namespace std;

class CWaypointDatabase
{
private:
    CWaypoint *m_pointerWayPoint;

public:
    CWaypointDatabase();
    void addWaypoint(CWaypoint const &waypoint);
    CWaypoint *getPointerToWaypoint(string name);
    void print();
    //void empty();

    map<const string, CWaypoint> m_mapWaypoint;
};

#endif //NAVIGATIONSYSTEMREVISION2_CWAYPOINTDATABASE_H
