#include "Point.h"
#include "Track.h"
#include "Util.h"
#include <iostream>

Track::Track()
{

}

Track::~Track()
{
    for(auto& point : data)
    {
        delete point;
    }

}

std::vector<Point*>& Track::getData()
{
    return this->data;
}

void Track::convertLLAtoECEF()
{
    for(auto &point: data)
    {
        auto lat = point->getLat();
        auto lng = point->getLong();
        auto alt = point->getAlt();
        auto x = point->getX();
        auto y = point->getY();
        auto z = point->getZ();

        scitec::Util::latlogToEcef(lat,lng,alt,x,y,z);
        point->setX(x);
        point->setY(y);
        point->setZ(z);
        //std::cout<<"Lat: " <<lat <<" Long: "<<lng<<" Alt: "<<alt<<" X: "<<x<<" Y: "<<y<<" Z: "<<z<<"\n";

    }
}

void Track::computeVelocities()
{
    std::size_t indexP1 = 0;
    std::size_t indexP2 = 1;
    std::size_t numPoints = data.size();

    for(;indexP2 < numPoints; ++indexP1,++indexP2)
    {
        auto latA = data[indexP1]->getLat();
        auto longA = data[indexP1]->getLong();
        auto altA = data[indexP1]->getAlt();
        auto time1 = data[indexP1]->getTime();

        auto latB = data[indexP2]->getLat();
        auto longB = data[indexP2]->getLong();
        auto altB = data[indexP2]->getAlt();
        auto time2 = data[indexP2]->getTime();


        auto distance = scitec::Util::computeDistance(latA,longA,altA,latB,longB,altB);

        if (indexP1 == 0)
        {
            data[indexP1]->setVelocity(0.0);
        }

        double vel = scitec::Util::computeVelocity(distance,time1,time2);
        data[indexP2]->setVelocity(vel);
        

    }
}

void Track::printTrackData()
{
    for(auto& point : data)
    {
        std::cout<<"X: "<<point->getX()<<" Y: "<<point->getY()<<" Z: "<<point->getZ()<<" Vel: "<<point->getVel()<<" km/sec\n";
    }
}
