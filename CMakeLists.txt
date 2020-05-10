cmake_minimum_required(VERSION 3.16)
project(NavigationSystemRevision2)

set(CMAKE_CXX_STANDARD 98)

add_executable(NavigationSystemRevision2 main.cpp CGPSSensor.h CGPSSensor.cpp CWaypoint.h CPoi.h CPoiDatabase.h CNavigationSystem.h CWaypointDatabase.h CRoute.h CWaypoint.cpp CWaypointDatabase.cpp CPoi.cpp CPoiDatabase.cpp CRoute.cpp CNavigtionSystem.cpp CPersistentStorage.h CCSV.h CCSV.cpp)