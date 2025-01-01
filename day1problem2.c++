
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();        // Number of rows in the image
        int n = img[0].size();     // Number of columns in the image

        // Initialize the smoothed image with the same dimensions as the input image
        vector<vector<int>> smoothImg(m, vector<int>(n));

        // Iterate over every cell in the input image
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;       // To calculate the sum of the neighboring cells
                int count = 0;     // To count valid neighbors

                // Check all cells in the 3x3 grid centered around (i, j)
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        // Ensure (x, y) is within valid grid boundaries
                        if (x >= 0 && x < m && y >= 0 && y < n) {
                            sum += img[x][y];  // Add value of the valid neighbor
                            count++;           // Increment valid neighbor count
                        }
                    }
                }

                // Calculate the smoothed value for cell (i, j) and store it
                smoothImg[i][j] = sum / count; // Rounded down automatically as we're using integer division
            }
        }

        // Return the smoothed image
        return smoothImg;
    }
};
