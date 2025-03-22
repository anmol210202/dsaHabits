#include <vector>
#include <unordered_map>
#include <chrono>
using namespace std;

// Custom hash function to help reduce collisions (from Codeforces blog)
struct CustomHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
  
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Use unordered_map with custom hash to protect against worst-case input.
        unordered_map<uint64_t, int, CustomHash> hashMap;
        for (int i = 0; i < nums.size(); i++) {
            // Calculate complement (cast to unsigned for safe hashing)
            uint64_t complement = static_cast<uint64_t>(target) - static_cast<uint64_t>(nums[i]);
            if (hashMap.find(complement) != hashMap.end()) {
                return { hashMap[complement], i };
            }
            // Insert current number with its index.
            hashMap[nums[i]] = i;
        }
        return {}; // Guaranteed to have a solution per problem constraints.
    }
};

