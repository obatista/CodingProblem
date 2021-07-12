#include "Util.h"
#include "globals.h"
#include <cmath>
#include "Track.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

scitec::Util::Util()
{

}

scitec::Util::~Util()
{

}

void scitec::Util::latlogToEcef(global::lat_t& lat,global::long_t& lng, global::alt_t& alt, double& x, double& y, double& z)
{
    double cosLat = std::cos(lat * global::CONVERT_DEGREES_RADIANS);
    double cosLong = std::cos(lng * global::CONVERT_DEGREES_RADIANS);
    double sinLat = std::sin(lat * global::CONVERT_DEGREES_RADIANS);
    double sinLong = std::sin(lng * global::CONVERT_DEGREES_RADIANS);

    double radiusOfCurvature = global::SEMI_MAJOR_KM / (std::sqrt(1 - (global::E_2 * sinLat * sinLat)));
    double curvatureHeight = radiusOfCurvature + alt;

    x = curvatureHeight * cosLat * cosLong;
    y = curvatureHeight * cosLat * sinLong;
    z = ((global::MINOR_SQ_MAJOR_SQ * radiusOfCurvature) + alt) * sinLat; 
    //std::cout<<"X: "<<x<<" Y: "<<y<<" Z: "<<z<<"\n";
}

void scitec::Util::loadTrackData(Track* track, std::istream& stream)
{
    std::string line;
    while (std::getline(stream, line))
    {
        Point* point = new Point();
        std::stringstream ss(line);
        std::string tempValue;

        std::getline(ss,tempValue,global::DELIM_COMMA);
        point->setTime(std::stod(tempValue));
        std::getline(ss,tempValue,global::DELIM_COMMA);
        point->setLat(std::stod(tempValue));
        std::getline(ss,tempValue,global::DELIM_COMMA);
        point->setLong(std::stod(tempValue));
        std::getline(ss,tempValue,global::DELIM_COMMA);
        point->setAlt(std::stod(tempValue));

        track->getData().push_back(std::move(point));     
    }
}

double scitec::Util::computeDistance(const global::lat_t& latA, const global::long_t& longA, const global::alt_t& altA,
                       const global::lat_t& latB, const global::long_t& longB, const global::alt_t& altB)
{
    double latDis = global::CONVERT_DEGREES_RADIANS * (latB - latA);
    double lonDis = global::CONVERT_DEGREES_RADIANS * (longB - longA);
    double a = std::sin(latDis/2) * std::sin(latDis/2) + std::cos(global::CONVERT_DEGREES_RADIANS * latA) * std::cos(global::CONVERT_DEGREES_RADIANS * latB)
                * std::sin(lonDis / 2) * std::sin(lonDis / 2);
    double c = 2 * std::atan2(std::sqrt(a),std::sqrt(1 - a));
    double dis = global::RADIUS_EARTH * c;
    double height = altA - altB;
    dis = dis * dis + height * height;
    
    return std::sqrt(dis);
}

double scitec::Util::computeVelocity(double distance, double t1, double t2)
{
    return distance / (t2 - t1);
}