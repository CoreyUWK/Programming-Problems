/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <list>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/* 
virtual memory: decoples virtual address space (programmer) and physical address space (RAM)
- each process maintins a mapping between virtual address and physical address, and every memory access passes through this map, hence its own page table
- The MMU is the physical contraption that does ths mapping (pages to page frames)
- virtual address divided into pages (a contiguous span of addresses) 4K
- physical addresses divided into page frames (same size as page)

- page table is simply maps virtual to physical address

Page Table(page # -> frame #) -> if not in page table checks TLB (Translation lookaside buffer) in MMU (cache) (page # -> frame #)

LRU Cache Design
- evict least recently used cache entry
- fast and efficent way of retrieving data
- fixed size (limit memory)
- fast access, O(1) insert and lookup
- replacement when memory limit reached, effienct way to evict entry when memory full

For O(1) lookup we think of hashmap
to track recentness of entry need an ordering that can change (double linked list) -> O(1) delete, insert

map(virtual address (page number) to )
*/

class LRUCache {
    /* Using hashmap for fast lookups and list for order maintaining of LRU */
    
    list<unsigned int> dqueue; // Stores keys (page #'s') of cache (fornt = old, back = new)
    unordered_map<unsigned int, list<unsigned int>::iterator> map; // Stores reference of key in cache
    int csize; // Maximum capacity of cache
    
    public:
    LRUCache(int capacity) : csize(capacity) {}
    
    void insert(unsigned int entry) {
        // Check if map contains entry
        if (map.find(entry) == map.end()) {
            // If not contained -> add new entry, and if full apply LRU
            if (csize == dqueue.size()) {
                map.erase(dqueue.front()); // remove least recent entry
                dqueue.pop_front();
            }
        }
        else {
             // If contains -> update to most recent in list
             dqueue.erase(map[entry]); // remove entries old position
        }
        
        // Common code (found after writing code)
        // Add new entry or move entry to end (recent)
        dqueue.push_back(entry);
        map[entry] = std::prev(dqueue.end()); // Update map to point to new position
    }
    
    void display() {
        cout << "Least -> Most" << endl;
        for (auto entry : dqueue) {
            cout << entry << " ";
        }
        cout << endl;
    }
};

int main()
{
    LRUCache cache(4);
    cache.insert(1);
    cache.insert(2);
    cache.insert(3);
    cache.insert(1);
    cache.insert(4);
    cache.insert(5);
    cache.display();
    
    return 0;
}
