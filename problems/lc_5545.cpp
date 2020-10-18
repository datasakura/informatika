class Solution {
public:
    struct Player {
        int age, score, teamScore;
    };

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
        for (size_t i = 0; i < players.size(); i++) {
            auto& pi = players[i];
            for (size_t j = 0; j < i; j++) {
                auto& pj = players[j];
                if (pi.age >= pj.age && pi.teamScore < pj.teamScore) {
                    pi.teamScore = pj.teamScore;
                }
            }
            pi.teamScore += pi.score;
        }
        int ans = 0;
        for (auto& p : players) {
            ans = max(ans, p.teamScore);
        }
        return ans;
    }
};
