class Solution {
private:
    struct CharFrequency {
        char character;
        int frequency;
        
        CharFrequency(char c, int f) : character(c), frequency(f) {}
    };
    
    struct Compare {
        bool operator()(const CharFrequency& a, const CharFrequency& b) {
            return a.frequency < b.frequency;
        }
    };
    
public:
    string reorganizeString(string s) {
        unordered_map<char, int> charCount;
        for (char c : s) {
            charCount[c]++;
        }
        
        priority_queue<CharFrequency, vector<CharFrequency>, Compare> maxHeap;
        
        for (auto& entry : charCount) {
            maxHeap.push(CharFrequency(entry.first, entry.second));
        }
        
        string result = "";
        while (!maxHeap.empty()) {
            CharFrequency first = maxHeap.top();
            maxHeap.pop();
            
            if (result.empty() || result.back() != first.character) {
                result += first.character;
                if (--first.frequency > 0) {
                    maxHeap.push(first);
                }
            } else {
                if (maxHeap.empty()) {
                    return ""; // Not possible to rearrange
                }
                
                CharFrequency second = maxHeap.top();
                maxHeap.pop();
                
                result += second.character;
                if (--second.frequency > 0) {
                    maxHeap.push(second);
                }
                
                maxHeap.push(first); // Put the first character back to the heap
            }
        }
        
        return result;
    }
};

