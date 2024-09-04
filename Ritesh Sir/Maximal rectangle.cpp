#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// FUNCTION TO FIND THE LARGEST RECTANGLE AREA IN A HISTOGRAM
int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    int i = 0;

    while (i <= heights.size()) {
        int currentHeight = (i == heights.size()) ? 0 : heights[i];

        // PUSH INDEX IF STACK IS EMPTY OR CURRENT HEIGHT IS GREATER THAN THE HEIGHT AT STACK TOP
        if (s.empty() || currentHeight >= heights[s.top()]) {
            s.push(i++);
        } 
        // POP FROM STACK AND CALCULATE AREA WITH THE POPPED HEIGHT AS THE SHORTEST BAR
        else {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
    }

    return maxArea;
}

// FUNCTION TO FIND THE MAXIMAL RECTANGLE AREA
int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    
    int cols = matrix[0].size();
    vector<int> heights(cols, 0);
    int maxRectangleArea = 0;

    // ITERATE THROUGH EACH ROW IN THE MATRIX
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < cols; j++) {
            // UPDATE THE HEIGHTS BASED ON CURRENT ROW VALUES
            heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
        }
        // FIND THE MAXIMAL RECTANGLE AREA FOR THE UPDATED HEIGHTS
        maxRectangleArea = max(maxRectangleArea, largestRectangleArea(heights));
    }

    return maxRectangleArea;
}

int main() {
    // SAMPLE BINARY MATRIX
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    // ASSERTION TO CHECK IF THE MAXIMAL RECTANGLE AREA IS CORRECT
    int result = maximalRectangle(matrix);
    cout << "Maximal Rectangle Area: " << result << endl;

    return 0;
}
