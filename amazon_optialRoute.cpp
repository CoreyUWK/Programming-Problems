// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
vector<pair<int, int> > optimalUtilization(int maxTravelDist,
							        vector<pair<int, int> > forwardRouteList,
							        vector<pair<int, int> > returnRouteList)
{
    vector<pair<int, int> > optList;
    int opt = 0;
    int tmpOpt = 0;
    
    // Note could have tried with recursion and dynamic programming
    
    // WRITE YOUR CODE HERE
    for (int i = 0; i < forwardRouteList.size(); ++i) {
        for (int j = 0; j < returnRouteList.size(); ++j) {
            tmpOpt = forwardRouteList[i].second + returnRouteList[j].second;
            //cout << "tmpOpt: " << tmpOpt <<endl;
            if (tmpOpt <= maxTravelDist && tmpOpt > opt) {
                opt = tmpOpt;
                optList.clear();
                optList.push_back(std::make_pair(forwardRouteList[i].first, returnRouteList[j].first));
                //cout << "Max:" << maxTravelDist << " Opt:" << opt << endl;
            }
            else if (tmpOpt <= maxTravelDist && tmpOpt == opt) {
                opt = tmpOpt;
                optList.push_back(std::make_pair(forwardRouteList[i].first, returnRouteList[j].first));
                //cout << "Max:" << maxTravelDist << " Opt:" << opt << endl;
            }
        }
    }
    
    return optList;
}
// FUNCTION SIGNATURE ENDS