//
// Created by Aniruddha on 5/1/2020.
//

#ifndef NAVIGATIONSYSTEMREVISION2_CCSV_H
#define NAVIGATIONSYSTEMREVISION2_CCSV_H

#include "CPoiDatabase.h"
#include "CWaypointDatabase.h"
#include "CWaypoint.h"
#include "CPoi.h"
#include "CPersistentStorage.h"
#include <bits/stdc++.h>

class CCSV : public CPersistenceStorage
{
public:
    CCSV();
    virtual ~CCSV();
    void setMediaName(string name) = 0;
    bool writeData(const CWaypointDatabase &waypointDB, const CPoiDatabase &poiDB);
    bool readData(const CWaypointDatabase &waypointDB, const CPoiDatabase &poiDB, MergeMode Mode);

private:
    string m_wayPointFileName;
    string m_PoiFileName;
    ofstream WaypointStorage;
    ifstream WaypointRead;
    ofstream PoiStorage;
    ifstream PoiRead;
};


#endif //NAVIGATIONSYSTEMREVISION2_CCSV_H
