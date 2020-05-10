//
// Created by Aniruddha on 4/26/2020.
//

#include <bits/stdc++.h>
#include "CPoi.h"
#include "CWaypoint.h"

using namespace std;

CPoi::CPoi()
{
    m_name = " ";
    m_latitude = 0.0;
    m_longitude = 0.0;
    m_type = NONE;
    m_description = " ";
}

CPoi::CPoi(t_poi type, string name, string description, double latitude, double longitude)
{
    this->m_type = type;
    this->m_name = name;
    this->m_description = description;
    this->m_latitude = latitude;
    this->m_longitude = longitude;
}

void CPoi::set(t_poi type, string name, string description, double latitude, double longitude)
{
    m_type = type;
    m_description = description;
    if(latitude>=-90 && latitude<=90 && longitude>=-180 && longitude<=180)
    {
        m_latitude = latitude;
        m_longitude = longitude;
        m_name = name;
    }
    else
    {
        m_name = "Imaginary POI";
        m_latitude = 0.0;
        m_longitude = 0.0;
    }
}

void CPoi::getAllDataByReference(t_poi &type, string &name, string &description, double &latitude, double &longitude)
{
    name = m_name;
    description = m_description;
    latitude = m_latitude;
    longitude = m_longitude;
    switch (m_type)
    {
        case RESTAURANT:
            type = RESTAURANT;
            break;

        case GAS_STATION:
            type = GAS_STATION;
            break;

        case TOURISTIC:
            type = TOURISTIC;
            break;

        case UNIVERSITY:
            type = UNIVERSITY;
            break;

        case NONE:
            cout << "Not a POI in this case" << endl;
            break;
    }
}

string CPoi::getDescription()
{
    return m_description;
}

string CPoi::getPoiType()
{
    switch (m_type)
    {
        case RESTAURANT:
            return "RESTAURANT";
            break;
        case TOURISTIC:
            return "TOURISTIC";
            break;
        case GAS_STATION:
            return "GAS STATION";
            break;
        case UNIVERSITY:
            return "UNIVERSITY";
            break;
        case NONE:
            return "NONE";
            break;
        default:
            return "Not a POI TYPE";
            break;
    }
}

/*
 * DEGREE: 1
 * MINUTE_SECONDS: 2
 */
void CPoi::print(int format)
{
    switch(m_type)
    {
        case RESTAURANT:
            cout << "Type: RESTAURANT" << endl;
            cout << "Description: " << m_description << endl;
            CWaypoint::print(format);
            cout << endl;
            break;

        case TOURISTIC:
            cout << "Type: TOURISTIC" << endl;
            cout << "Description: " << m_description << endl;
            CWaypoint::print(format);
            cout << endl;
            break;

        case GAS_STATION:
            cout << "Type: GAS STATION" << endl;
            cout << "Description: " << m_description << endl;
            CWaypoint::print(format);
            cout << endl;
            break;

        case UNIVERSITY:
            cout << "Type: UNIVERSITY" << endl;
            cout << "Description: " << m_description << endl;
            CWaypoint::print(format);
            cout << endl;
            break;

        case NONE:
            cout << "Enter a valid POI type." << endl;
            cout << endl;
            break;

        default:
            cout << "Wrong input of POI type." << endl;
            break;
    }
}

void operator<<(ostream &out, CPoi &m_poip)
{
    int deg1, deg2, min1, min2;
    double sec1, sec2;

    m_poip.transformLongitude2degmmss(deg1,min1,sec1);
    m_poip.transformLatitude2degmmss(deg2,min2,sec2);
    cout << "Printing all the Point of Interest using Operator Overloading" << endl;
    out << m_poip.getName() << endl;
    out << m_poip.getType() << endl;
    out << "Latitude for POI in DEG_MIN_SEC: " << deg2 << ' ' << min2 << ' ' << sec2 << endl;
    out << "Longitude for POI in DEG_MIN_SEC: " << deg1 << ' ' << min1 << ' ' << sec1 << endl;
}

CPoi::~CPoi()
{
    //Do nothing here
}