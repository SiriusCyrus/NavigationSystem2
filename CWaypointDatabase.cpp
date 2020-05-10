//
// Created by Aniruddha on 4/26/2020.
//

#include <bits/stdc++.h>
#include "CWaypointDatabase.h"
#include "CWaypoint.h"

using namespace std;

CWaypointDatabase::CWaypointDatabase()
{
    //Do nothing here
}

void CWaypointDatabase::addWaypoint(const CWaypoint &waypoint)
{
    CWaypoint localvalue = waypoint;
    map<const string, CWaypoint>::iterator itr;
    itr = m_mapWaypoint.find(localvalue.getName());
    if(itr==m_mapWaypoint.end())
    {
        m_mapWaypoint.insert(pair<string,CWaypoint>(localvalue.getName(),localvalue));
    }
    else
    {
        cout << "Waypoint already exists in the database" << endl;
    }
}

CWaypoint* CWaypointDatabase::getPointerToWaypoint(string name)
{
    map<const string, CWaypoint>::iterator itr;
    if(m_mapWaypoint.empty())
    {
        cout << "Waypoint Database is empty" << endl;
    }
    else
    {
        for(itr=m_mapWaypoint.begin();itr!=m_mapWaypoint.end();++itr)
        {
            itr = m_mapWaypoint.find(name);
            if(itr->first == name)
                return &(itr->second);
        }
    }
    return m_pointerWayPoint;
}

void CWaypointDatabase::print()
{
    cout << endl;
    cout << "The Waypoint Database has the following waypoints." << endl;
    map<const string, CWaypoint>::iterator itr;
    for(itr=m_mapWaypoint.begin();itr!=m_mapWaypoint.end();++itr)
    {
        itr->second.print(DEGREE);
    }
    cout << endl;
}

/*void CWaypointDatabase::empty()
{
    m_mapWaypoint.empty();
}*/