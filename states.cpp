// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED

// O(days*states), Calculates each of the states for each day
vector<int> cellCompete(int* states, int days) 
{
    std::vector<int> statesOut;
    int cellsSize = 8;
    if (NULL == states) return statesOut;
        
    // WRITE YOUR CODE HERE  
    for (int day = 0; day < days; ++day) {
        int lastState = states[0];
        for (int i = 0; i < cellsSize; ++i) {
            //cout << "Last:" << lastState << endl;
            if (i == 0) { // front
                if (states[i + 1] == 0) {
                    lastState = states[i];
                    states[i] = 0;
                }
                else {
                    lastState = states[i];
                    states[i] = 1;
                }
            }
            else if (i == cellsSize - 1) { // end
                if (lastState == 0) {
                    lastState = states[i];
                    states[i] = 0;
                }
                else {
                    lastState = states[i];
                    states[i] = 1;
                }
            }
            else {
                if (lastState == states[i+1]) {
                    lastState = states[i];
                    states[i] = 0;
                }
                else {
                    lastState = states[i];
                    states[i] = 1;
                }
            }
            //cout << states[i] << " ";
        }
        //cout << endl;
    }
    
    for (int i = 0; i < cellsSize; ++i) {
        statesOut.push_back(states[i]);
    }
    
    return statesOut;
}
// FUNCTION SIGNATURE ENDS