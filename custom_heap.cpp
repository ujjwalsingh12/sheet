#include <iostream>
#include <queue>
#include <vector>

// Define the data structure
struct Item {
    int key;
    std::string value;

    // Constructor
    Item(int k, std::string v) : key(k), value(v) {}
};

// Comparator for the min-heap based on the key
struct Compare {
    bool operator()(const Item& a, const Item& b) {
        return a.key > b.key;  // For min-heap, reverse for max-heap
    }
};

int main() {
    // Create a priority queue (min-heap) with the custom comparator
    std::priority_queue<Item, std::vector<Item>, Compare> minHeap;

    // Add items to the heap
    minHeap.push(Item(5, "apple"));
    minHeap.push(Item(3, "banana"));
    minHeap.push(Item(8, "cherry"));
    minHeap.push(Item(1, "date"));

    // Print and pop elements from the heap
    while (!minHeap.empty()) {
        Item top = minHeap.top();
        std::cout << "Key: " << top.key << ", Value: " << top.value << std::endl;
        minHeap.pop();
    }

    return 0;
}