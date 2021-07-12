#ifndef GLOBAL_
#define GLOBAL_

#include <cmath>
#include <string>

namespace global
{   //KNOWLEDGE
    //  
    //  
    //  

 

    //Constants
    const double SEMI_MAJOR_KM = 6378.137;
    const double SEMI_MINOR_KM = 6356.75231424518;
    const double RADIUS_EARTH = 6371;

    const double SEMI_MAJOR_KM_SQ = SEMI_MAJOR_KM * SEMI_MAJOR_KM;
    const double SEMI_MINOR_KM_SQ = SEMI_MINOR_KM * SEMI_MINOR_KM;

    const double MINOR_SQ_MAJOR_SQ = SEMI_MINOR_KM_SQ / SEMI_MAJOR_KM_SQ;

    const double PI = 3.14159265;
    const double E = std::sqrt((SEMI_MAJOR_KM_SQ - SEMI_MINOR_KM_SQ)/SEMI_MAJOR_KM_SQ);
    const double E_2 = E * E;
    const double CONVERT_DEGREES_RADIANS = PI/180;
    

    //typedefs
    typedef double lat_t;
    typedef double long_t;
    typedef double alt_t;


    //Char
    const char DELIM_COMMA = ',';
   

    //

    
} // namespace name
#endif //GLOBAL_
