//
// Created by Aniruddha on 4/25/2020.
//

#ifndef NAVIGATIONSYSTEMREVISION2_CNAVIGATIONSYSTEM_H
#define NAVIGATIONSYSTEMREVISION2_CNAVIGATIONSYSTEM_H

#include <bits/stdc++.h>
#include "CPoi.h"
#include "CWaypoint.h"
#include "CPoiDatabase.h"
#include "CRoute.h"
#include "CWaypointDatabase.h"
#include "CGPSSensor.h"
#include "CCSV.h"
#include "CPersistentStorage.h"

using namespace std;

class CNavigationSystem
{
private:
    CGPSSensor m_GPSSensor;
    CRoute m_route;
    CPoiDatabase m_PoiDatabase;
    CWaypointDatabase m_WpDatabase;
    CPersistenceStorage *m_File;

public:
    CNavigationSystem();
    void run();
    void enterRoute();
    void printRoute();
    void createDatabase();
    void writeToFile();
    void readFromFile();
};

#endif //NAVIGATIONSYSTEMREVISION2_CNAVIGATIONSYSTEM_H
