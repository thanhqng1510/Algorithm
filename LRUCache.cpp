/*
 Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

 get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

 The cache is initialized with a positive capacity.

 Follow up:
 Could you do both operations in O(1) time complexity?
 */


// ---------------------------------------


#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;


class LRUCache {
private:
    typedef list<pair<int,int>> list_pair;    // pair of { key, value }, key is only used in put method
    
    list_pair m_cache;
    unordered_map<int, list_pair::iterator> m_addr_map;    // map from key to a node reference
    int m_capacity;
    
public:
    LRUCache(int capacity)
    : m_capacity(capacity) {}
    
    int get(int key) {
        int res = -1;
        auto it = m_addr_map.find(key);
        
        if (it != m_addr_map.end()) {
            res = it->second->second;
            m_cache.erase(it->second);
            m_cache.push_front({ key, res });
            it->second = m_cache.begin();
        }
    
        return res;
    }
    
    void put(int key, int value) {
        auto it = m_addr_map.find(key);
        
        if (it == m_addr_map.end()) {   // insert
            if (m_cache.size() == m_capacity) {
                m_addr_map.erase(m_cache.back().first);
                m_cache.pop_back();
            }
            m_cache.push_front({ key, value });
            m_addr_map.insert({ key, m_cache.begin() });
        }
        else {    // update
            m_cache.erase(it->second);
            m_cache.push_front({ key, value });
            it->second = m_cache.begin();
        }
    }
};


int main() {
    LRUCache cache(2);
    
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << "\n";
    cache.put(3, 3);
    cout << cache.get(2) << "\n";   // -1
    cache.put(4, 4);
    cout << cache.get(1) << "\n";   // -1
    cout << cache.get(3) << "\n";
    cout << cache.get(4) << "\n";
}
