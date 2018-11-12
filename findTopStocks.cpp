/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class StockMarket {
    class StockTrade {
        string stockName;
        int share;
        
        StockTrade(string stockName, int share) : stockName(stockName), share(share) {}
        
        friend StockMarket;
    };

    struct CompareStock {
        bool operator() (const StockTrade *const lhs, const StockTrade * const rhs) const {
            return lhs->share > rhs->share;
        }
        friend StockMarket;
    };

    std::vector<StockTrade*> heap;
    unordered_map<string, StockTrade*> hash;
    
    public:
    
    StockMarket () {
        std::make_heap(heap.begin(), heap.end(), CompareStock());
    }
    
    void addTrade(string stockName, int share){
        StockTrade *trade = new StockTrade(stockName, share);
        
        if (hash.find(stockName) == hash.end()) {
            hash.insert({stockName, trade});
            heap.push_back(trade);
            make_heap(heap.begin(), heap.end(), CompareStock());
            //std::push_heap(heap.begin(), heap.end(), CompareStock());
        }
        else {
            hash[stockName]->share += share;
            //make_heap(heap.begin(), heap.end(), CompareStock());
            //std::push_heap(heap.begin(), heap.end(), CompareStock());
        }
        std::sort_heap(heap.begin(), heap.end(), CompareStock());
    }
    
    void printTop(int numberOfStock) {
        for (int i = 0; i < heap.size() && i < numberOfStock; ++i) {
            StockTrade *top = heap[i];
            cout << top->stockName << " " << top->share << endl;
        }
    }
};


int main()
{
    StockMarket stockMarket;
    stockMarket.addTrade("GOOGLE", 50);
    stockMarket.addTrade("APPLE", 150);
    stockMarket.addTrade("GOOGLE", 100);
    stockMarket.addTrade("MSFT", 250);
    stockMarket.addTrade("GOOGLE", 200);
    stockMarket.addTrade("AMAZON", 1200);
    stockMarket.addTrade("INTEL", 500);
    stockMarket.addTrade("WALMART", 30);

    stockMarket.printTop(5);
    return 0;
}
