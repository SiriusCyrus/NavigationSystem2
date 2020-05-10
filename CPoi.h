//
// Created by Aniruddha on 4/25/2020.
//

#ifndef NAVIGATIONSYSTEMREVISION2_CPOI_H
#define NAVIGATIONSYSTEMREVISION2_CPOI_H

#include <bits/stdc++.h>
#include "CWaypoint.h"

using namespace std;

enum t_poi
{
    RESTAURANT,TOURISTIC, GAS_STATION, UNIVERSITY, NONE
};

class CPoi : public CWaypoint
{
private:
    t_poi m_type;
    string m_description;

public:
    CPoi();
    void print(int format);
    CPoi(t_poi type, string name, string description, double latitude, double longitude);
    void set(t_poi type, string name, string description, double latitude, double longitude);
    ~CPoi();
    string getPoiType();    //Used for Persistent Storage
    string getDescription();    //Used for Persistent Storage
    void getAllDataByReference(t_poi &type, string &name, string &description, double &latitude, double &longitude);
    friend void operator<<(ostream &out, CPoi &m_poip);
};

#endif //NAVIGATIONSYSTEMREVISION2_CPOI_H
