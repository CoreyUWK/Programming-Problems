// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
#include <math.h>  
float dist(int x, int y) {
    return sqrt(pow(x,2) + pow(y,2));
}

bool compareMin(const pair<int,int> &lhs, const pair<int,int> &rhs) {
    //cout << "Comp:" << dist(lhs.first, lhs.second) << " " << dist(rhs.first, rhs.second) << endl;
    return (dist(lhs.first, lhs.second) <= dist(rhs.first, rhs.second));
}

// closest from start
vector<pair<int, int> > ClosestXdestinations(int numDestinations, 
                                             int** allLocations, 
											 int numDeliveries)
{
    std::vector<pair<int,int>> out;
    // WRITE YOUR CODE HERE
    // 1) can sort in O(nlogn)
    // 2) use min heap of O(nlogn)
    
    for (int i = 0; i < numDestinations; ++i) {
        //cout << allLocations[i][0] << " " << allLocations[i][1] << endl;
        //cout << dist(allLocations[i][0], allLocations[i][1]) << endl;
        
        out.push_back(std::make_pair(allLocations[i][0], allLocations[i][1]));
    }
    
    std::partial_sort(out.begin(), out.begin() + numDeliveries, out.end(), compareMin);
    out.erase(out.begin() + numDeliveries, out.end());
    
    return out;
}
// FUNCTION SIGNATURE ENDS