class LRUCache {
public:
    LRUCache(int capacity) {
        c = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) 
            return -1;

        lru.splice(lru.begin(), lru, cache[key].second);
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            cache[key].first = value;
            lru.splice(lru.begin(), lru, cache[key].second);
        }
        else {
            lru.push_front(key);
            cache[key] = {value,lru.begin()};
            if((int)cache.size() > c) {
                cache.erase(lru.back());
                lru.pop_back();
            }
        }
    }
    
    private:
        unordered_map<int, pair<int,list<int>::iterator>> cache;
        list<int> lru;
        int c;
};
