//
// Created by Aniruddha on 4/26/2020.
//

#include "CPoi.h"
#include "CPoiDatabase.h"
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

CPoiDatabase::CPoiDatabase()
{
    //Initialize the PoiDatabase
}

void CPoiDatabase::addPoi(const CPoi &poi)
{
    CPoi dummy = poi;
    map<const string, CPoi>::iterator itr;
    itr = m_PoiMap.find(dummy.getName());
    if(itr==m_PoiMap.end())
    {
        m_PoiMap.insert(pair<string, CPoi>(dummy.getName(),dummy));
    }
    else
    {
        cout << "Point of Interest already exists in the database" << endl;
    }
}

CPoi* CPoiDatabase::getPointerToPoi(string name)
{
    map<const string, CPoi>::iterator itr;
    if(m_PoiMap.empty())
    {
        cout << "Poi Database is empty" << endl;
    }
    else
    {
        for(itr=m_PoiMap.begin();itr!=m_PoiMap.end();++itr)
        {
            itr = m_PoiMap.find(name);
            if (itr->first == name)
            {
                return &(itr->second);
            }
        }
    }
    //return NULL; // abr return null?
}

void CPoiDatabase::print()
{
    map<const string, CPoi>::iterator itr;
    cout << "Following POI are in POI Database" << endl;
    for(itr=m_PoiMap.begin();itr!=m_PoiMap.end();++itr)
    {
        itr->second.print(DEGREE);
    }
}