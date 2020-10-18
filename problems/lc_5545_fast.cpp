class Solution {
public:
    struct Player {
        int age, score;
    };
    
    static constexpr int MAXK = 10;
    static constexpr int MAXN = 1 << MAXK;
    
    int tree[MAXN * 2];
    
    int getMax(int l, int r) {
        l += MAXN;
        r += MAXN;
        int ans = 0;
        while (l < r) {
            if (l & 1)
                ans = max(ans, tree[l++]);
            if (r & 1)
                ans = max(ans, tree[--r]);
            l /= 2;
            r /= 2;
        }
        return ans;
    }
    
    void setMax(int i, int v) {
        i += MAXN;
        tree[i] = max(tree[i], v);
        while (i > 1) {
            i /= 2;
            tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
        }
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<Player> players;
        for (size_t i = 0; i < scores.size(); i++) {
            players.push_back({ ages[i], scores[i] });
        }
        sort(players.begin(), players.end(), [&](auto& a, auto& b) {
            if (a.score == b.score)
                return a.age < b.age;
            return a.score < b.score;
        });
        for (auto& p : players) {
            setMax(p.age, p.score + getMax(0, p.age + 1));
        }
        return getMax(0, MAXN);
    }
};
