/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;


double median(const std::vector<int> &arr1, const std::vector<int> &arr2)
{
    for (int i : arr1) {
        cout << i << " ";
    }
    cout << endl;
    for (int i : arr2) {
        cout << i << " ";
    }
    cout << endl;
    
    if (arr1.size() == 0 || arr2.size() == 0) throw std::invalid_argument("1");
    if (arr1.size() != arr2.size()) throw std::invalid_argument("2");
    if (arr1.size() == 1) return (arr1[0] + arr2[0]) / 2;
    if (arr1.size() == 2) {
        return (std::max(arr1[0], arr2[0]) + std::min(arr1[1], arr2[1])) / 2;
    }
    
    double median1 = (arr1.size() % 2 == 1) ? arr1[arr1.size() / 2] : 
        (arr1[arr1.size() / 2 - 1] + arr1[arr1.size() / 2]) / 2;
    double median2 = (arr2.size() % 2 == 1) ? arr2[arr2.size() / 2] : 
        (arr2[arr2.size() / 2 - 1] + arr2[arr2.size() / 2]) / 2;
        
    if (median1 == median2) return median1;
    if (median1 < median2) {
        printf("%d %d, %d %d\n",
            (arr1.size() / 2 - 1), arr1.size(), 0, (arr2.size() / 2 + 1));
        return median(std::vector<int>(arr1.begin() + (arr1.size() / 2 - 1), arr1.begin() + arr1.size()),
           std::vector<int>(arr2.begin(), arr2.begin() + (arr2.size() / 2 + 1)));
    }
    return median(std::vector<int>(arr1.begin(), arr1.begin() + (arr1.size() / 2 + 1)),
        std::vector<int>(arr2.begin() + (arr2.size() / 2 - 1), arr2.begin() + arr2.size())); 
}

int main()
{
    std::vector<int> arr1 = {1,3,8,9,15};
    std::vector<int> arr2 = {7,11,18,19,21/*,25*/};
    double m = median(arr1, arr2);
    cout << m;
    
    return 0;
}


/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class SubArray {
    std::vector<int> underlying;
    int start;
    int size;
    
    public:
    SubArray(std::vector<int> arr) {
        underlying = arr;
        start = 0;
        size = arr.size();
    }
    
    SubArray subArray(int i, int j) {
        if (i > j) throw std::invalid_argument("");
        if (j > size) throw std::out_of_range("");
        
        SubArray s(underlying);
        s.start = start + i;
        s.size = j - i;
        return s;
    }
    
    int getSize() {
        return size;
    }
    
    int getFirst() {
        return underlying[start];
    }
    
    int getLast() {
        return underlying[start + (size - 1)];
    }
    
    double getMedian() {
        if (size % 2 == 0) {
            int mid = start + size / 2;
            return (underlying[mid - 1] + 
                    underlying[mid]) / 2.0;
        }
    }
};

double median (SubArray arr1, SubArray arr2) {
    if (arr1.getSize() == 1) return (arr1.getFirst() + arr2.getFirst()) / 2.0;
    if (arr1.getSize() == 2) {
        return (std::max(arr1.getFirst(), arr2.getFirst()) + 
                std::min(arr1.getLast(), arr2.getLast())) / 2.0;
    }
    
    double median1 = arr1.getMedian();
    double median2 = arr2.getMedian();
    
    if (median1 == median2) return median1;
    if (median1 > median2) {
        return median(arr1.subArray(0, arr1.getSize()/2 + 1),
                      arr2.subArray( (arr2.getSize() - 1) / 2, arr2.getSize()));
    }
    return median(arr1.subArray( (arr1.getSize() - 1) / 2, arr1.getSize()),
                  arr2.subArray(0, (arr2.getSize() / 2) + 1)); 
}

double median (std::vector<int> arr1, std::vector<int> arr2) {
    if (arr1.size() == 0 || arr1.size() != arr2.size())
        throw std::invalid_argument("invlid arguments");
        
    return median(SubArray(arr1), SubArray(arr2));
}

int main()
{
    std::vector<int> arr1 = {1,3,8,9,15};
    std::vector<int> arr2 = {7,11,18,19,21/*,25*/};
    double m = median(arr1, arr2);
    cout << m;
    
    return 0;
}
