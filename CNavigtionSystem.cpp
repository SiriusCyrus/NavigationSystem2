//
// Created by Aniruddha on 4/27/2020.
//

#include "CNavigationSystem.h"
#include <bits/stdc++.h>
using namespace std;

CNavigationSystem::CNavigationSystem()
{
    m_File = NULL;
}

void CNavigationSystem::enterRoute()
{
    //Adding Waypoints
    CWaypoint Kolkata("Kolkata",22.5726, 88.3639, WAYPOINT);
    CWaypoint Mumbai("Mumbai", 19.0760, 72.8777, WAYPOINT);
    CWaypoint Karlsruhe("Karlsruhe",49.0069, 8.4037, WAYPOINT);
    CWaypoint Landskronstrasse("Landskronstrasse", 49.853308, 8.646835, WAYPOINT);

    this->m_WpDatabase.addWaypoint(Kolkata);
    this->m_WpDatabase.addWaypoint(Landskronstrasse);
    this->m_WpDatabase.addWaypoint(Mumbai);
    this->m_WpDatabase.addWaypoint(Karlsruhe);
    m_WpDatabase.print();

    cout << "Pointer to waypoint Kolkata: " << m_WpDatabase.getPointerToWaypoint("Kolkata") << endl;
    cout << "Pointer to waypoint Mumbai: " << m_WpDatabase.getPointerToWaypoint("Mumbai") << endl;
    cout << endl;

    //Adding POI to POI Database
    CPoi MotherIndia(RESTAURANT, "Mother India", "Indian Restaurant", 48.1909, 11.8630);
    CPoi CafeIda(RESTAURANT, "Cafe Ida", "Small cafe", 48.1907, 11.8635);
    CPoi Neuschwanstein(TOURISTIC, "Neuschwanstein Castle", "Old heritage castle", 47.5576, 10.7498);
    CPoi Aral(GAS_STATION, "Aral", "Local gas station", 49.1933, 7.6787);
    CPoi Tum(UNIVERSITY, "TUM", "Oldest Uni in Germany", 48.1497, 11.5679);

    this->m_PoiDatabase.addPoi(MotherIndia);
    this->m_PoiDatabase.addPoi(CafeIda);
    this->m_PoiDatabase.addPoi(Neuschwanstein);
    this->m_PoiDatabase.addPoi(Aral);
    this->m_PoiDatabase.addPoi(Tum);
    m_PoiDatabase.print();

    cout << "Pointer to POI Neuschwanstein Castle: " << m_PoiDatabase.getPointerToPoi("Neuschwanstein Castle") << endl;
    cout << "Pointer to POI TUM:" << m_PoiDatabase.getPointerToPoi("TUM") << endl;
    cout << endl;

    //Fetching data from Database and adding them to route
    this->m_route.connectToWaypointDatabase(&m_WpDatabase);
    this->m_route.addWaypoint("Karlsruhe");
    this->m_route.addWaypoint("Landskronstrasse");

    this->m_route.connectToPoiDatabase(&m_PoiDatabase);
    this->m_route.addPoi("Mother India", "Karlsruhe");
    this->m_route.addPoi("Cafe Ida", "Karlsruhe");

    this->m_route.print();
    this->m_route+="Mumbai";
    this->m_route+="Landskronstrasse";

    //Creating the Route
    CWaypointDatabase WayDB2;
    CPoiDatabase PoiDB2;
    CRoute Route2;

    WayDB2.addWaypoint(Karlsruhe);
    cout << "K Added" << endl;
    PoiDB2.addPoi(Tum);
    Route2.connectToWaypointDatabase(&WayDB2);
    Route2.connectToPoiDatabase(&PoiDB2);
    Route2.addPoi("Aral","Landskronstrasse");

    CRoute finalRoute;
    finalRoute=m_route+Route2;
    finalRoute.print();
}

void CNavigationSystem::createDatabase()
{
    CWaypoint CCSVway;
    CWaypointDatabase CCSVwayDB;
    CCSVway.set("Augsburg",48.3705, 10.8978, WAYPOINT);
    CCSVwayDB.addWaypoint(CCSVway);
    CCSVway.set("Stuttgart", 48.7758,9.1829, WAYPOINT);
    CCSVwayDB.addWaypoint(CCSVway);

    CPoiDatabase CCSVPoiDB;
    CPoi UniStuttgart(UNIVERSITY,"Stuttgart University", "German Uni", 48.7815, 9.1736);
    CPoi Losteria(RESTAURANT, "Losteria", "Italian Restaurant", 48.1551,11.5839);
    CCSVPoiDB.addPoi(UniStuttgart);
    CCSVPoiDB.addPoi(Losteria);
}

void CNavigationSystem::writeToFile()
{
   m_File->setMediaName("Database");
   m_File->writeData(m_WpDatabase,m_PoiDatabase);
   m_File=NULL;
}

void CNavigationSystem::readFromFile()
{
    m_File->setMediaName("Database");
    m_File->readData(m_WpDatabase,m_PoiDatabase,REPLACE);
    m_WpDatabase.print();
    m_PoiDatabase.print();
    m_File=NULL;
}

void CNavigationSystem::printRoute()
{
    //this->m_route.print();
}

void CNavigationSystem::run()
{
    this->enterRoute();
    this->printRoute();
}