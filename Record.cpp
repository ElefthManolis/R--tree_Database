#include <vector>

using namespace std;

#ifndef RECORD_CPP
#define RECORD_CPP

class Record{
public:
    Record(){
        
    }

    Record(long long aId, vector <double> aCoords) {
        id = aId;
        coords = aCoords;
    }

    long long getId() {
        return id;
    }

    vector<double> getCoords() {
        return coords;
    }

    

private:
    long long id;
    vector <double> coords;
};
#endif