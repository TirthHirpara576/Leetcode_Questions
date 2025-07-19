class RandomizedSet {
    vector <int> v;
    unordered_map <int,int> mp;  // <element,index of that element in vector>
public:
    RandomizedSet() {
        
    }

    // my own created function
    bool search(int ele){ 
        if(mp.find(ele) != mp.end()) return true; // element is already present in map
        return false;
    }
    
    bool insert(int val) {
        if(search(val))    return false;

        v.push_back(val);
        mp[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!search(val))
            return false;

       
        auto it = mp.find(val);
        v[it->second] = v.back(); // I want element should remove from vector in O(1). so, I am put that element at last/back , so that  pop_back() is worked fine.
        v.pop_back();
        mp[v[it->second]] = it->second;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/*   Q] if i write mp.erase(it->first);  insted of    mp[v[it->second]] = it->second; 
        mp.erase(val);      then what happen ?

If you replace these two lines:

mp[v[it->second]] = it->second;
mp.erase(val);
with just:


mp.erase(it->first);
Then you’ll break the consistency of your unordered_map and vector.

🔍 Let's break it down with an example:
Assume:
v = [10, 20, 30, 40]
mp = {
    10 → 0,
    20 → 1,
    30 → 2,
    40 → 3
}
You call remove(20)

Now it->first = 20, it->second = 1

✅ Working version:

v[it->second] = v.back();         // v[1] = 40 → v = [10, 40, 30, 40]
v.pop_back();                     // v = [10, 40, 30]
mp[v[it->second]] = it->second;   // mp[40] = 1
mp.erase(val);                    // mp.erase(20)

Result:

v = [10, 40, 30]
mp = {
    10 → 0,
    30 → 2,
    40 → 1
}
✅ Correct. Both v and mp are in sync.

❌ Your version:

v[it->second] = v.back(); // OK: v[1] = 40
v.pop_back();             // OK: remove last 40
mp.erase(it->first);      // only erase 20
// ❌ You didn't update mp[40] = 1
Now:

v = [10, 40, 30]
mp = {
    10 → 0,
    30 → 2,
    40 → 3 ❌ WRONG!
}
This is the issue — the index of 40 changed from 3 → 1, but you didn’t update it. So the next time you use the map (like to remove 40), it will look in the wrong place in the vector, and you may:

Delete wrong value

Cause out-of-bounds access

OR fail to find the value

*/



/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */