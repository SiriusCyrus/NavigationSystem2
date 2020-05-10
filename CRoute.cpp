//
// Created by Aniruddha on 4/26/2020.
//

#include "CPoi.h"
#include "CPoiDatabase.h"
#include "CWaypoint.h"
#include "CWaypointDatabase.h"
#include "CRoute.h"

using namespace std;

CRoute::CRoute()
{
    m_PoiDatabase = NULL;
    m_WaypointDatabase = NULL;
}

CRoute::CRoute(const CRoute &origin)
{
    m_PoiDatabase = origin.m_PoiDatabase;
    m_WaypointDatabase = origin.m_WaypointDatabase;
    m_Route = origin.m_Route;
}

CRoute::~CRoute()
{
    //Do nothing
}

void CRoute::connectToPoiDatabase(CPoiDatabase *pPoiDB)
{
    cout << pPoiDB << endl;
    if(pPoiDB==NULL)
    {
        cout << "POI Database can't be connected." << endl;
    }
    else
        m_PoiDatabase = pPoiDB;
}

void CRoute::connectToWaypointDatabase(CWaypointDatabase *pWaypointDB)
{
    cout << pWaypointDB << endl;
    if(pWaypointDB==NULL)
    {
        cout << "Waypoint Database can't be connected." << endl;
    }
    else
        m_WaypointDatabase = pWaypointDB;
}

void CRoute::addWaypoint(string name)
{
    if(m_WaypointDatabase!=NULL)
    {
        CWaypoint *dummy = m_WaypointDatabase->getPointerToWaypoint(name);
        if(dummy!= NULL)
        {
            m_Route.push_back(dummy);
        }
        else
        {
            cout << "Data can't be added to Waypoint Database" << endl;
            cout << endl;
        }
    }
    else
    {
        cout << "Waypoint Database is not connected." << endl;
    }
}

void CRoute::addPoi(string namePoi, string afterWaypoint)
{
    CPoi *dummy = m_PoiDatabase->getPointerToPoi(namePoi);
    if(m_PoiDatabase==NULL)
    {
        cout << "POI Database is not connected." << endl;
    }
    else
    {
        if(dummy==NULL)
        {
            cout << namePoi << " is not present in CPOI Database" << endl;
            cout << endl;
        }
        else
        {
            list<CWaypoint*>::iterator itr;
            for(itr=m_Route.begin();itr!=m_Route.end();++itr)
            {
                //CWaypoint *waypointdummy = NULL;
                if(NULL== dynamic_cast<CPoi*>(*itr))
                {
                    if ((**itr).getName() == afterWaypoint)
                    {
                        m_Route.insert(++itr, dummy);
                        --itr;
                        break;
                        //waypointdummy = (*itr);
                    }
                }
            }
        }
    }
}

void CRoute::print()
{
    cout << "Printing all the waypoints and POI of the Navigation System" << endl;
    list<CWaypoint*>::iterator itr;
    CPoi *poiprint;
    if(!m_Route.empty())
    {
        for(itr=m_Route.begin();itr!=m_Route.end();itr++)
        {
            if(dynamic_cast<CPoi*>(*itr)!=NULL)
            {
                (*itr)->print(1);
                poiprint = dynamic_cast<CPoi *>(*itr);
                cout << (*poiprint);
            }
            else
            {
                cout << (**itr);
            }
        }
    }
    else
    {
        cout << "The route is empty" << endl;
    }
}

void CRoute::operator+=(string name)
{
    if(m_WaypointDatabase->getPointerToWaypoint(name)!=NULL)
    {
        cout << "Print data";
        this->addWaypoint(name);
        if(!m_Route.empty())
        {
            addPoi(name, name);
        }
        else
        {
            if(m_PoiDatabase!=NULL)
            {
                if(!m_Route.empty())
                {
                    CPoi *poidummy=m_PoiDatabase->getPointerToPoi(name);
                    if(poidummy!=NULL)
                    {
                        m_Route.push_back(poidummy);
                    }
                    else
                    {
                        cout << "No POI names found in the database" << endl;
                    }
                }
                else
                {
                    cout << "No waypoint names found in the database" << endl;
                }
            }
            else
            {
                cout << "Not connected to POI Database" << endl;
            }
        }
    }
    else
    {
        cout << "Not connected to Waypoint Database" << endl;
    }
}

CRoute operator+(CRoute &lhs, CRoute &rhs)
{
    CRoute FinalRoute;
    if(lhs.m_PoiDatabase == rhs.m_PoiDatabase && lhs.m_WaypointDatabase == rhs.m_WaypointDatabase)
    {
        FinalRoute = lhs;
        list<CWaypoint*>::iterator itr;
        for(itr=rhs.m_Route.begin();itr!=rhs.m_Route.end();++itr)
        {
            FinalRoute.m_Route.push_back(*itr);
        }
        return FinalRoute;
    }
    else
    {
        cout << "Not connected to same Database" << endl;
    }   return FinalRoute;
}
