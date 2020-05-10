//
// Created by Aniruddha on 5/1/2020.
//

#include "CCSV.h"
#include <bits/stdc++.h>

using namespace std;

/*CCSV::CCSV()
{
    m_PoiFileName = " ";
    m_wayPointFileName = " ";
}*/

void CCSV::setMediaName(string name)
{
    m_PoiFileName = name+"-poi.txt";
    m_wayPointFileName = name+"waypoint.txt";
}

bool CCSV::writeData(const CWaypointDatabase &waypointDB, const CPoiDatabase &poiDB)
{
    CWaypointDatabase wpData = waypointDB;
    CPoiDatabase poiData = poiDB;
    map<string, CWaypoint>::iterator itr_wayptr;
    map<string, CPoi>::iterator itr_poiptr;

    WaypointStorage.open(m_wayPointFileName.data());
    PoiStorage.open(m_PoiFileName.data());

    if(WaypointStorage.is_open() && PoiStorage.is_open())
    {
        for(itr_wayptr=wpData.m_mapWaypoint.begin();itr_wayptr!=wpData.m_mapWaypoint.end();++itr_wayptr)
        {
            WaypointStorage << itr_wayptr->second.getName() << ',' << itr_wayptr->second.getLatitude() << ','
            << itr_wayptr->second.getLongitude() << ',' << itr_wayptr->second.getType() << endl;
        }
        WaypointStorage.close();

        for(itr_poiptr=poiData.m_PoiMap.begin();itr_poiptr!=poiData.m_PoiMap.end();++itr_poiptr)
        {
            PoiStorage << itr_poiptr->second.getType() << ',' << itr_poiptr->second.getName() << ',' <<
            itr_poiptr->second.getDescription() << ',' << itr_poiptr->second.getLatitude() << ';' <<
            itr_poiptr->second.getLongitude() << endl;
        }
        PoiStorage.close();
        return true;
    }
    else
    {
        cout << "Error in opening the files." << endl;
        return false;
    }
}

bool CCSV:: readData(const CWaypointDatabase &waypointDB, const CPoiDatabase &poiDB, MergeMode Mode)
{
    string readname, readdesc, line_loc, readlongitude, readlatitude, readtype;
    t_poi type2;
    wp_type type1;
    unsigned int line_num1=0,line_num2=0,line_num3=0,line_num4=0;
    WaypointRead.open(m_wayPointFileName.data());
    PoiRead.open(m_PoiFileName.data());

    CWaypointDatabase dummyway = waypointDB;
    CPoiDatabase dummypoi = poiDB;

    if(WaypointRead.is_open() && PoiRead.is_open())
    {
        if(Mode==MERGE)
        {
            while(getline(WaypointRead,line_loc))
            {
                vector<string> mergeVector;
                string merge;
                stringstream input(line_loc);   //Read line one by one
                line_num1++;
                char *c;

                if(line_loc==" ")
                {
                    cerr << "BLANK SPACE ON TEXT FILE AT: " << line_num1 << endl;
                    continue;
                }
                while(getline(input,merge,';'))
                {
                    mergeVector.push_back(merge);
                }

                if(mergeVector.size()>=1)   //Read name
                {
                    readname=mergeVector[0];
                }
                if(mergeVector.size()>=2)   //Read latitude
                {
                    readlatitude=mergeVector[1];
                }
                double printlat=strtod(readlatitude.data(),&c);

                if(mergeVector.size()>=3)   //Read longitude
                {
                    readlongitude=mergeVector[2];
                }
                double printlon=strtod(readlongitude.data(),&c);

                if(mergeVector.size()>=4)   //Read type
                    readtype = mergeVector[3];

                if(readtype=="WAYPOINT")
                {
                    type1 = WAYPOINT;
                }
                else if(readtype == "ERROR")
                {
                    type1 = ERROR;
                }

                //Exception handling in case of more than 4 fields
                if(mergeVector.size()>4)
                {
                    cerr << "TOO MANY INPUTS: " << line_num1 << line_loc << endl;
                }
                //Exception handling in case of blank space
                for(unsigned int i=0;i<mergeVector.size();i++)
                {
                    if(mergeVector[i]==" ")
                    {
                        cerr << "BLANK SPACE AT: " << line_num1 << endl;
                    }
                }
                CWaypoint mergeway = CWaypoint(readname, printlat, printlon, type1);
                dummyway.addWaypoint(mergeway);
            }
            WaypointRead.close();

            while(getline(PoiRead,line_loc))
            {
                vector<string> mergeVector;
                string merge;
                stringstream input(line_loc);   //Read line one by one
                line_num2++;
                char *c;

                if(line_loc==" ")
                {
                    cerr << "BLANK SPACE ON TEXT FILE AT: " << line_num2 << endl;
                    continue;
                }
                while(getline(input,merge,';'))
                {
                    mergeVector.push_back(merge);
                }

                if(mergeVector.size()>=1)   //Read type
                    readtype=mergeVector[0];
                if(readtype=="RESTAURANT")
                {
                    type2 = RESTAURANT;
                }
                else if(readtype=="TOURISTIC")
                {
                    type2 = TOURISTIC;
                }
                else if(readtype=="GAS_STATION")
                {
                    type2 = GAS_STATION;
                }
                else if(readtype=="UNIVERSITY")
                {
                    type2 = UNIVERSITY;
                }
                else
                    type2 = NONE;

                if(mergeVector.size()>=2)   //Read name
                {
                    readname=mergeVector[1];
                }
                if(mergeVector.size()>=3)   //Read description
                {
                    readdesc=mergeVector[2];
                }
                if(mergeVector.size()>=4)   //Read latitude
                {
                    readlatitude=mergeVector[3];
                }
                double lat=strtod(readlatitude.data(),&c);
                if(mergeVector.size()>=5)   //Read longitude
                {
                    readlongitude=mergeVector[4];
                }
                double lon=strtod(readlongitude.data(),&c);

                //Exception handling in case of more than 5 fields
                if(mergeVector.size()>5)
                {
                    cerr << "TOO MANY INPUTS: " << line_num2 << line_loc << endl;
                }
                //Exception handling in case of blank space
                for(unsigned int i=0;i<mergeVector.size();i++)
                {
                    if(mergeVector[i]==" ")
                    {
                        cerr << "BLANK SPACE AT: " << line_num1 << endl;
                    }
                }
                CPoi mergepoi = CPoi(type2, readname,readdesc, lat,lon);
                dummypoi.addPoi(mergepoi);
            }
        }
        else if(Mode==REPLACE)
        {
            waypointDB.m_mapWaypoint.empty();
            poiDB.m_PoiMap.empty();

            while(getline(WaypointRead,line_loc))
            {
                vector<string> replaceVector;
                string replace;
                stringstream input(line_loc);   //Read line one by one
                line_num3++;
                char *c;

                if(line_loc==" ")
                {
                    cerr << "BLANK SPACE ON TEXT FILE AT: " << line_num3 << endl;
                    continue;
                }
                while(getline(input,replace,';'))
                {
                    replaceVector.push_back(replace);
                }

                if(replaceVector.size()>=1)   //Read name
                {
                    readname=replaceVector[0];
                }
                if(replaceVector.size()>=2)   //Read latitude
                {
                    readlatitude=replaceVector[1];
                }
                double printlat=strtod(readlatitude.data(),&c);

                if(replaceVector.size()>=3)   //Read longitude
                {
                    readlongitude=replaceVector[2];
                }
                double printlon=strtod(readlongitude.data(),&c);

                if(replaceVector.size()>=4)   //Read type
                    readtype = replaceVector[3];

                if(readtype=="WAYPOINT")
                {
                    type1 = WAYPOINT;
                }
                else if(readtype == "ERROR")
                {
                    type1 = ERROR;
                }

                //Exception handling in case of more than 4 fields
                if(replaceVector.size()>4)
                {
                    cerr << "TOO MANY INPUTS: " << line_num3 << line_loc << endl;
                }
                //Exception handling in case of blank space
                for(unsigned int i=0;i<replaceVector.size();i++)
                {
                    if(replaceVector[i]==" ")
                    {
                        cerr << "BLANK SPACE AT: " << line_num1 << endl;
                    }
                }
                CWaypoint replaceway = CWaypoint(readname, printlat, printlon, type1);
                dummyway.addWaypoint(replaceway);
            }
            WaypointRead.close();

            while(getline(PoiRead,line_loc))
            {
                vector<string> replaceVector;
                string replace;
                stringstream input(line_loc);   //Read line one by one
                line_num4++;
                char *c;

                if (line_loc == " ")
                {
                    cerr << "BLANK SPACE ON TEXT FILE AT: " << line_num4 << endl;
                    continue;
                }

                while (getline(input, replace, ';'))
                {
                    replaceVector.push_back(replace);
                }

                if (replaceVector.size() >= 1)   //Read type
                    readtype = replaceVector[0];
                if (readtype == "RESTAURANT")
                {
                    type2 = RESTAURANT;
                }
                else if (readtype == "TOURISTIC")
                {
                    type2 = TOURISTIC;
                }
                else if (readtype == "GAS_STATION")
                {
                    type2 = GAS_STATION;
                }
                else if (readtype == "UNIVERSITY")
                {
                    type2 = UNIVERSITY;
                }
                else
                    type2 = NONE;

                if (replaceVector.size() >= 2)   //Read name
                {
                    readname = replaceVector[1];
                }
                if (replaceVector.size() >= 3)   //Read description
                {
                    readdesc = replaceVector[2];
                }
                if (replaceVector.size() >= 4)   //Read latitude
                {
                    readlatitude = replaceVector[3];
                }
                double lat = strtod(readlatitude.data(), &c);
                if (replaceVector.size() >= 5)   //Read longitude
                {
                    readlongitude = replaceVector[4];
                }
                double lon = strtod(readlongitude.data(), &c);

                //Exception handling in case of more than 5 fields
                if (replaceVector.size() > 5)
                {
                    cerr << "TOO MANY INPUTS: " << line_num4 << line_loc << endl;
                }
                //Exception handling in case of blank space
                for(unsigned int i=0;i<replaceVector.size();i++)
                {
                    if(replaceVector[i]==" ")
                    {
                        cerr << "BLANK SPACE AT: " << line_num1 << endl;
                    }
                }
                CPoi replacepoi = CPoi(type2, readname, readdesc, lat, lon);
                dummypoi.addPoi(replacepoi);
            }
            PoiRead.close();
        }
        return true;
    }
    else
    {
        cerr << "ERROR IN OPENING THE FILE" << endl;
        return false;
    }
}


