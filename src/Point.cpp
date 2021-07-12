
#include "Point.h"



Point::Point()
{

}

Point::~Point()
{

}

void Point::setLat(const global::lat_t& lat)
{
    this->lat_deg = lat;
}

void Point::setLong(const global::long_t& lng)
{
    this->lng_deg = lng;
}

void Point::setAlt(const global::alt_t& alt)
{
    this->alt_km_meters = alt;
}

void Point::setTime(const double& time)
{
    this->time_sec = time;
}

void Point::setVelocity(const double& vel)
{
    this->velocity_km_sec = vel;
}

void Point::setX(const double& x )
{
    this->x = x;
}

void Point::setY(const double& y )
{
    this->y = y;
}

void Point::setZ(const double& z )
{
    this->z = z;
}

global::lat_t& Point::getLat()
{
    return this->lat_deg;
}

global::long_t& Point::getLong()
{
    return this->lng_deg;
}

global::alt_t& Point::getAlt()
{
    return this->alt_km_meters;
}

double& Point::getX()
{
    return this->x;
}

double& Point::getY()
{
    return this->y;
}

double& Point::getZ()
{
    return this->z;
}

double& Point::getTime()
{
    return this->time_sec;
}

double& Point::getVel()
{
    return this->velocity_km_sec;
}