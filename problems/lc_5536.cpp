class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> citySize(n);
        vector<vector<int>> commonRoads(n, vector<int>(n));
        for (auto& i : roads) {
            int a = i[0], b = i[1];
            citySize[a]++;
            citySize[b]++;
            commonRoads[a][b]++;
            commonRoads[b][a]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(ans, citySize[i] + citySize[j] - commonRoads[i][j]);
            }
        }
        return ans;
    }
};
