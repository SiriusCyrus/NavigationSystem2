#include<bits/stdc++.h>
#include<cstdio>
#include "CNavigationSystem.h"
#include "CRoute.h"
#include "CGPSSensor.h"
#include "CWaypoint.h"
#include "CPoi.h"
#include "CCSV.h"
#include "CPersistentStorage.h"

using namespace std;

int main()
{
    //Entering the data manually
    string getName;
    double getLatitude, getLongitude;
    wp_type getType;

    cout << "Navigation System started" << endl;
    //Creating parameters for Waypoints
    CWaypoint Amsterdam, GrossGerau, MarktSchwaben, Berlin;

    //Setting the values in the waypoints
    Amsterdam.set("Amsterdam", 52.3702, 4.8952, WAYPOINT);
    GrossGerau.set("Gross-Gerau", 49.92139, 8.48255, WAYPOINT);
    MarktSchwaben.set("Markt Schwaben", 48.1909, 11.8630, WAYPOINT);
    Berlin.set("Berlin",52.5200, 13.4050, WAYPOINT);
    cout << endl;

    //Printing the values in both formats
    GrossGerau.print(DEGREE);
    MarktSchwaben.print(MINUTES_SECONDS);
    cout << endl;

    //Test all the functions
    string print_name = Berlin.getName();
    double print_latitude = Berlin.getLatitude();
    double print_longitude = Berlin.getLongitude();
    cout << "Place name is: " << print_name << " with Latitude: " << print_latitude << " and longitude: " << print_longitude << endl;
    cout << endl;

    //Get all data by reference
    Amsterdam.getAllDataByReference(getName, getLatitude, getLongitude);
    cout << endl;
    MarktSchwaben.getAllDataByReference(getName, getLatitude, getLongitude);
    cout << endl;
    GrossGerau.getAllDataByReference(getName, getLatitude, getLongitude);
    cout << endl;

    //Calculate distance
    double distance1 = MarktSchwaben.calculateDistance(GrossGerau);
    cout << "The distance between Markt Schwaben & Gross-Gerau is: " << distance1 << "km" << endl;
    double distance2 = Berlin.calculateDistance(GrossGerau);
    cout << "The distance between Berlin & Gross-Gerau is: " << distance2 << "km" << endl;
    double distance3 = Amsterdam.calculateDistance(Berlin);
    cout << "The distance between Amsterdam & Berlin is: " << distance3 << "km"<< endl;

    // Testing the GPS Sensor class
    cout << endl;
    cout << "Testing GPS Sensor Class" << endl;
    CGPSSensor sensor;
    CWaypoint Waypointobj1 = sensor.getCurrentPosition();
    Waypointobj1.print(DEGREE);
    cout << endl;

    //Testing the CPOI class
    CPoi Mensa(RESTAURANT,"Mensa", "Campus canteen", 11.9076, 9.5322);
    Mensa.print(1);

    //Testing the CCSV class
    CWaypoint Wayobj;
    CWaypointDatabase WayDBobj;
    Wayobj.set("Ulm",48.4011,9.9876, WAYPOINT);
    WayDBobj.addWaypoint(Wayobj);
    Wayobj.set("Hannover", 52.3759,9.7320, WAYPOINT);
    WayDBobj.addWaypoint(Wayobj);

    CPoiDatabase PoiDBobj;
    CPoi StuFrank(UNIVERSITY,"Studentenwerk Frankfurt", "Student Center", 50.1197, 8.6518);
    PoiDBobj.addPoi(StuFrank);
    CPoi TK(GAS_STATION, "Tech Gas", "Expensive Gas station", 49.8757,8.6580);

    CCSV *obj;
    obj->setMediaName("Database");
    obj->writeData(WayDBobj,PoiDBobj);
    obj->readData(WayDBobj,PoiDBobj,MERGE);
    WayDBobj.print();
    PoiDBobj.print();

    //Run Navigation System
    CNavigationSystem Navsys;
    Navsys.run();
}