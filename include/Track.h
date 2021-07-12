#ifndef TRACK
#define TRACK

#include <vector>
#include <Point.h>


class Track{

    public:
        Track();
        ~Track();

        std::vector<Point*>& getData();
        void convertLLAtoECEF();
        void computeVelocities();
        void printTrackData();

    private:
        std::vector<Point*> data;


};

#endif

