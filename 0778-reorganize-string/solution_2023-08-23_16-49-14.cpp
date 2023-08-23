class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> charCount;
        for (char c : s) {
            charCount[c]++;
        }
        
        auto cmp = [](pair<char, int>& a, pair<char, int>& b) {
            return a.second < b.second;
        };
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> maxHeap(cmp);
        
        for (auto& entry : charCount) {
            maxHeap.push(entry);
        }
        
        string result = "";
        while (!maxHeap.empty()) {
            pair<char, int> first = maxHeap.top();
            maxHeap.pop();
            
            if (result.empty() || result.back() != first.first) {
                result += first.first;
                if (--first.second > 0) {
                    maxHeap.push(first);
                }
            } else {
                if (maxHeap.empty()) {
                    return ""; // Not possible to rearrange
                }
                
                pair<char, int> second = maxHeap.top();
                maxHeap.pop();
                
                result += second.first;
                if (--second.second > 0) {
                    maxHeap.push(second);
                }
                
                maxHeap.push(first); // Put the first character back to the heap
            }
        }
        
        return result;
    }
};

