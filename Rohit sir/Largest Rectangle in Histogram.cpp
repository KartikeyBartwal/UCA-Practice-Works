#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        // STACK TO STORE THE INDICES OF THE BARS
        stack<int> indexStack;

        int maxArea = 0;
        int n = heights.size();

        // ITERATE THROUGH ALL THE BARS
        for (int i = 0; i < n; ++i) {

            // WHILE THE CURRENT BAR IS LOWER THAN THE BAR AT THE STACK'S TOP, CALCULATE AREA
            while (!indexStack.empty() && heights[i] < heights[indexStack.top()]) {

                // GET THE HEIGHT OF THE BAR AT THE TOP
                int height = heights[indexStack.top()];
                indexStack.pop();

                // CALCULATE WIDTH AS THE DISTANCE BETWEEN THE CURRENT INDEX AND THE INDEX ON THE NEW STACK'S TOP
                int width = indexStack.empty() ? i : i - indexStack.top() - 1;

                // UPDATE THE MAXIMUM AREA
                maxArea = max(maxArea, height * width);
            }

            // PUSH THE CURRENT INDEX ONTO THE STACK
            indexStack.push(i);
        }

        // HANDLE REMAINING BARS IN THE STACK
        while (!indexStack.empty()) {

            int height = heights[indexStack.top()];
            indexStack.pop();

            int width = indexStack.empty() ? n : n - indexStack.top() - 1;

            maxArea = max(maxArea, height * width);
        }

        return maxArea;
    }
};

int main() {

    Solution solution;

    // EXAMPLE HISTOGRAM
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    // PRINT THE LARGEST RECTANGLE AREA
    cout << "The largest rectangle area is: " << solution.largestRectangleArea(heights) << endl;

    return 0;
}
