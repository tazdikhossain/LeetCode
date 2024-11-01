#include <vector>
#include <unordered_map>
#include <cstdlib> 

class RandomizedSet {
    std::vector<int> nums; 
    std::unordered_map<int, int> valToIndex; 

public:
    RandomizedSet() {
  
    }
    
    bool insert(int val) {
      
        if (valToIndex.find(val) != valToIndex.end()) {
            return false;
        }
        
       
        nums.push_back(val);
        valToIndex[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
       
        if (valToIndex.find(val) == valToIndex.end()) {
            return false;
        }
        
       
        int index = valToIndex[val];
        int lastElement = nums.back();
        
        
        nums[index] = lastElement;
        valToIndex[lastElement] = index;
        
     
        nums.pop_back();
        valToIndex.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
