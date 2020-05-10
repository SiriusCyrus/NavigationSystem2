//
// Created by Aniruddha on 4/25/2020.
//

#include <bits/stdc++.h>
#include "CWaypoint.h"

using namespace std;
double R = 6378.18;
const double PI = 3.141592653589793238463;

CWaypoint::CWaypoint()
{
    m_name = " ";
    m_latitude = 0.0;
    m_longitude = 0.0;
    m_type = ERROR;
}

CWaypoint::CWaypoint(string name, double latitude, double longitude, wp_type type)
{
    m_name = name;
    m_latitude = latitude;
    m_longitude = longitude;
    m_type = type;
    cout << "The objects generated at: " << this->m_name << ' ' << this->m_latitude << ' ' << this->m_longitude << ' ' << this->m_type << endl;
}

void CWaypoint::set(string name, double latitude, double longitude, wp_type type)
{
    m_name = name;
    m_type = type;
    if(latitude>=-90 && latitude<=90 && longitude>=-180 && longitude<=180)
    {
        m_latitude = latitude;
        m_longitude = longitude;
    }
    else
    {
        m_latitude = 0.0;
        m_longitude = 0.0;
    }
    cout << "Waypoint name: " << name << " with type: " << type << " with latitude: " << latitude << " and longitude: " << longitude << endl;
}

string CWaypoint::getName()
{
    return m_name;
}

double CWaypoint::getLatitude()
{
    return m_latitude;
}

double CWaypoint::getLongitude()
{
    return m_longitude;
}

string CWaypoint::getType()
{
    switch (m_type)
    {
        case WAYPOINT:
            return "WAYPOINT";
            break;

        case ERROR:
            return "ERROR";
            break;

        default:
            return "Not recognised by the parameters";
            break;
    }
}

void CWaypoint::getAllDataByReference(string &name, double &latitude, double &longitude)
{
    name = m_name;
    latitude = m_latitude;
    longitude = m_longitude;

    cout << "The name " << name << " is stored at: " << &name << endl;
    cout << "The latitude " << latitude << " is stored at: " << &latitude << endl;
    cout << "The longitude " << longitude << " is stored at: " << &longitude << endl;
    cout << endl;
}

void CWaypoint::transformLatitude2degmmss(int &deg, int &mm, double &ss)
{
    deg = m_latitude;
    cout << deg << endl;
    mm = (m_latitude-deg)*60;
    cout << mm << endl;
    ss = (m_latitude-deg-(mm/60)/3600);
    cout << ss << endl;
}

void CWaypoint::transformLongitude2degmmss(int &deg, int &mm, double &ss)
{
    deg = m_longitude;
    mm = (m_longitude-deg)*60;
    ss = (m_longitude-deg-(mm/60)/3600);
}

void CWaypoint::print(int format)
{
    int deg, mm;
    double ss;
    switch(format)
    {
        case 1:
            cout << m_name << ' ' << m_latitude << ' ' << m_longitude << endl;
            break;

        case 2:
            cout << "Name is: " << m_name;
            transformLatitude2degmmss(deg,mm,ss);
            cout << " Latitude with degree: " << deg << " minutes: " << mm << " and seconds: " << ss;
            transformLongitude2degmmss(deg, mm, ss);
            cout << ", Longitude with degree: " << deg << " minutes: " << mm << " and seconds: " << ss << endl;
            break;

        default:
            cout << "Wrong choice." << endl;
            break;
    }
}

double CWaypoint::calculateDistance(const CWaypoint &wp)
{
    string name1 = m_name;
    double latitude1 = m_latitude;
    double longitude1 = m_longitude;

    string name2 = wp.m_name;
    double latitude2 = wp.m_latitude;
    double longitude2 = wp.m_longitude;

    latitude1 = latitude1*(PI/180);
    longitude1 = longitude1*(PI/180);
    latitude2 = latitude2*(PI/180);
    longitude2 = longitude2*(PI/180);

    double distance = R*acos((sin(latitude1)*sin(latitude2))+cos(latitude1)*cos(latitude2)*cos(longitude2-longitude1));
    return distance;
}

void operator<<(ostream &out, CWaypoint &m_wayp)
{
    int deg1,deg2,min1,min2;
    double sec1,sec2;

    m_wayp.transformLatitude2degmmss(deg1,min1,sec1);
    m_wayp.transformLongitude2degmmss(deg2,min2,sec2);

    cout << "Printing the Waypoint using Operator overloading" << endl;
    out << m_wayp.getName() << endl;
    out << "Latitude for Waypoint in DEG_MIN_SEC: " << deg1 << ' ' << min1 << ' ' << sec1 << endl;
    out << "Longitude for Waypoint in DEG_MIN_SEC: " << deg2 << ' ' << min2 << ' ' << sec2 << endl;
}


CWaypoint::~CWaypoint()
{
    //Do nothing here
}