//
// Created by Aniruddha on 4/25/2020.
//

#ifndef NAVIGATIONSYSTEMREVISION2_CWAYPOINT_H
#define NAVIGATIONSYSTEMREVISION2_CWAYPOINT_H

#include <bits/stdc++.h>
#define DEGREE 1
#define MINUTES_SECONDS 2
using namespace std;

enum wp_type
{
    WAYPOINT, ERROR
};

class CWaypoint
{
protected:
    string m_name;
    double m_latitude;
    double m_longitude;
    wp_type m_type;

    void transformLongitude2degmmss(int &deg, int &mm, double &ss);
    void transformLatitude2degmmss(int &deg, int &mm, double &ss);

public:
    CWaypoint();
    CWaypoint(string name, double latitude, double longitude, wp_type type);
    void set(string name, double latitude, double longitude, wp_type type);
    string getName();
    double getLatitude();
    double getLongitude();
    string getType();
    void print(int format);     //Print Degree or Minute_Seconds format
    void getAllDataByReference(string& name, double& latitude, double& longitude);
    double calculateDistance(const CWaypoint &wp);  //Calculate distance
    virtual ~CWaypoint();
    friend void operator<<(ostream &out, CWaypoint &m_wayp);


};
#endif //NAVIGATIONSYSTEMREVISION2_CWAYPOINT_H
