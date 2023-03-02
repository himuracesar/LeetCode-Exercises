class Solution {
public:
    int maxArea(vector<int>& height) {
       int start = 0;
       int end = height.size() - 1;
       int maxa = 0;

       while(start < end)
       {
           if(height[start] >= height[end])
           {
               int area = ((end + 1) - (start + 1)) * height[end];
               maxa = max(area, maxa);
               end--;
           }
           else
           {
               int area = ((end + 1) - (start + 1)) * height[start];
               maxa = max(area, maxa);
               start++;
           }
       }

       return maxa;
    }
};