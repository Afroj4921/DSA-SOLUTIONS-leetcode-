class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxA = 0;
        stack<int> s;
        for(int i=0; i<=n; i++){
            while(!s.empty() && (i == n || heights[s.top()] >= heights[i])){
                int h = heights[s.top()];
                s.pop();
                int w;
                if(s.empty()){
                    w = i;
                }else{
                    w = i - s.top() - 1;
                }
                maxA = max(maxA, h*w);
            }
            s.push(i);
        }
        return maxA;
    }
};