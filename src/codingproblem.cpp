
#include <cstdlib>
#include <fstream>
#include "Track.h"
#include "Util.h"


int main()
{

    Track* track = new Track();
    std::fstream dataFile(".//data//SciTec_code_problem_data.csv",std::fstream::out | std::fstream::in);
    scitec::Util::loadTrackData(track, dataFile);
    track->convertLLAtoECEF();
    track->computeVelocities();
    track->printTrackData();

   return EXIT_SUCCESS; 
}