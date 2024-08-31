#include <iostream>
#include <queue>
#include <vector>

// Alias for the pair
typedef std::pair<int, std::string> KeyValuePair;

int main() {
    // Min-heap (priority queue) based on the first element of the pair (the key)
    std::priority_queue<KeyValuePair, std::vector<KeyValuePair>, std::greater<KeyValuePair>> minHeap;

    // Add items to the heap
    minHeap.push(std::make_pair(5, "apple"));
    minHeap.push(std::make_pair(3, "banana"));
    minHeap.push(std::make_pair(8, "cherry"));
    minHeap.push(std::make_pair(1, "date"));

    // Print and pop elements from the heap
    while (!minHeap.empty()) {
        KeyValuePair top = minHeap.top();
        std::cout << "Key: " << top.first << ", Value: " << top.second << std::endl;
        minHeap.pop();
    }

    return 0;
}