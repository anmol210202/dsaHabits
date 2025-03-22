#include <vector>
#include <unordered_map>
#include <chrono>
using namespace std;

// Custom hash to avoid potential worst-case performance in unordered_map
// Reference: https://codeforces.com/blog/entry/62393 :contentReference[oaicite:0]{index=0}
struct CustomHash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
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
        // Use an unordered_map with our custom hash function.
        unordered_map<uint64_t, int, CustomHash> hashMap;
        for (int i = 0; i < nums.size(); i++) {
            // Calculate complement; cast to uint64_t to use with our custom hash safely.
            uint64_t comp = static_cast<uint64_t>(target) - static_cast<uint64_t>(nums[i]);
            if (hashMap.find(comp) != hashMap.end()) {
                // Return indices if found
                return { hashMap[comp], i };
            }
            // Insert the current value with its index.
            hashMap[nums[i]] = i;
        }
        return {}; // Per problem constraints, there is always one solution.
    }
};

