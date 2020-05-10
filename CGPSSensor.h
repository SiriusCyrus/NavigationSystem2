//
// Created by Aniruddha on 4/25/2020.
//

#ifndef NAVIGATIONSYSTEMREVISION2_CGPSSENSOR_H
#define NAVIGATIONSYSTEMREVISION2_CGPSSENSOR_H

#include<bits/stdc++.h>
#include "CWaypoint.h"

using namespace std;

class CGPSSensor : public CWaypoint
{
public:
    CGPSSensor();
    CWaypoint getCurrentPosition();

};

#endif //NAVIGATIONSYSTEMREVISION2_CGPSSENSOR_H
