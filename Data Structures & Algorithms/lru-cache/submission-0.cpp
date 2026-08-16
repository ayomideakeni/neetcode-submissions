class LRUCache {
public:
    unordered_map<int, list<pair<int,int>>::iterator> kv;
    list<pair<int,int>> LRU;
    int cap = 0;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(kv.find(key) != kv.end()){
            auto node = kv[key];
            auto val = node->second;
            LRU.splice(LRU.begin(), LRU, node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = kv.find(key);
        if(it != kv.end()){
            auto node = it->second;
            node->second = value;
            LRU.splice(LRU.begin(), LRU, node);

            return;
        }
            LRU.push_front({key,value});
            kv[key] = LRU.begin();
        
        if(kv.size() > cap){
            auto used = prev(LRU.end());
            kv.erase(used->first);
            LRU.pop_back();
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */