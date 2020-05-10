//
// Created by Aniruddha on 4/25/2020.
//

#ifndef NAVIGATIONSYSTEMREVISION2_CROUTE_H
#define NAVIGATIONSYSTEMREVISION2_CROUTE_H

#include <bits/stdc++.h>
#include "CPoiDatabase.h"
#include "CPoi.h"
#include "CWaypoint.h"
#include "CWaypointDatabase.h"

using namespace std;

class CRoute
{
private:
    CWaypointDatabase *m_WaypointDatabase;
    CPoiDatabase *m_PoiDatabase;
    list<CWaypoint*> m_Route;

public:
    CRoute();
    CRoute(CRoute const &origin);
    ~CRoute();
    void connectToPoiDatabase(CPoiDatabase *pPoiDB);
    void connectToWaypointDatabase(CWaypointDatabase *pWaypointDB);
    void addWaypoint(string name);
    void addPoi(string namePoi, string afterWaypoint);
    void print();
    void operator+=(string name);
    friend CRoute operator+(CRoute &lhs, CRoute &rhs);
};


#endif //NAVIGATIONSYSTEMREVISION2_CROUTE_H
