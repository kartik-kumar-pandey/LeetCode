class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int n = height.size();
        int left = 0;
        int right = n - 1;

        while (left < right) {
            int width = right - left;
            int h = min(height[left], height[right]);
            int current = width * h;
            area = max(area, current);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return area;
    }
};