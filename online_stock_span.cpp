#include <stack>
#include <utility>

class StockSpanner {
private:
    std::stack<std::pair<int, int>> s; // pair of (price, span)

public:
    StockSpanner() {
        
    }
    /*
    if the element are being added one by one then this is a good method to keep track of all the numbers which are
    lesser than the current number
    */
    int next(int price) {
        int span = 1; 
        while (!s.empty() && s.top().first <= price) { 
            span += s.top().second;
            s.pop();
        }
        s.push({price, span});
        return span;
    }
};

