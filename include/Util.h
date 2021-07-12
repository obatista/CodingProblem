#ifndef UTIL
#define UTIL

#include "globals.h"
#include "Track.h"
#include <iostream>

namespace scitec{
class Util{

    public:
        Util();
        ~Util();

        static void latlogToEcef(global::lat_t& lat,global::long_t& lng, global::alt_t& alt, double& x, double& y, double& z);
        static void loadTrackData(Track* track, std::istream& stream);
        static double computeDistance(const global::lat_t& latA, const global::long_t& longA, const global::alt_t& altA,
                                      const global::lat_t& latB, const global::long_t& longB, const global::alt_t& altB);
        static double computeVelocity(double distance, double time1, double time2);
};

}
#endif
