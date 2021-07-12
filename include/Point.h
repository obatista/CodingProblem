#ifndef POINT
#define POINT

#include <globals.h>


class Point{

    public:
        Point();
        ~Point();

        void setLat(const global::lat_t& lat);
        void setLong(const global::long_t& lng);
        void setAlt(const global::alt_t& alt);

        void setTime(const double& time);
        void setVelocity(const double& vel);

        void setX(const double& x );
        void setY(const double& y );
        void setZ(const double& z );

        global::lat_t& getLat();
        global::long_t& getLong();
        global::alt_t& getAlt();

        double& getX();
        double& getY();
        double& getZ();

        double& getTime();
        double& getVel();

    private:

        global::lat_t lat_deg;
        global::long_t lng_deg;
        global::alt_t alt_km_meters;

        double x;
        double y;
        double z;

        double time_sec;
        double velocity_km_sec;



};
#endif