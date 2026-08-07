class Solution {
public:
    struct State {
        int a, b, c, d;

        bool operator==(const State& o) const {
            return a == o.a && b == o.b && c == o.c && d == o.d;
        }
    };

    struct Hash {
        size_t operator()(const State& s) const {
            return (((s.a * 31 + s.b) * 31 + s.c) * 31 + s.d);
        }
    };

    vector<array<int,4>> contrib = {
        {0,0,0,0}, // 0
        {0,0,0,0}, // 1
        {1,0,0,0}, // 2
        {0,1,0,0}, // 3
        {2,0,0,0}, // 4
        {0,0,1,0}, // 5
        {1,1,0,0}, // 6
        {0,0,0,1}, // 7
        {3,0,0,0}, // 8
        {0,2,0,0}  // 9
    };

    unordered_map<State, int, Hash> memo;

    int need(int a, int b, int c, int d) {
    if (a == 0 && b == 0 && c == 0 && d == 0)
        return 0;

    State st{a, b, c, d};

    auto it = memo.find(st);
    if (it != memo.end())
        return it->second;

    int ans = 1e9;

    for (int dig = 2; dig <= 9; dig++) {

        int na = max(0, a - contrib[dig][0]);
        int nb = max(0, b - contrib[dig][1]);
        int nc = max(0, c - contrib[dig][2]);
        int nd = max(0, d - contrib[dig][3]);

        // Skip digits that do not reduce the current state
        if (na == a && nb == b && nc == c && nd == d)
            continue;

        ans = min(ans, 1 + need(na, nb, nc, nd));
    }

    return memo[st] = ans;
}
    string buildSuffix(int len, int a, int b, int c, int d) {
        string res;

        for (int pos = 0; pos < len; pos++) {
            int remPos = len - pos - 1;

            for (int dig = 1; dig <= 9; dig++) {
                int na = max(0, a - contrib[dig][0]);
                int nb = max(0, b - contrib[dig][1]);
                int nc = max(0, c - contrib[dig][2]);
                int nd = max(0, d - contrib[dig][3]);

                if (need(na, nb, nc, nd) <= remPos) {
                    res.push_back(char('0' + dig));
                    a = na;
                    b = nb;
                    c = nc;
                    d = nd;
                    break;
                }
            }
        }

        return res;
    }

    string smallestNumber(string num, long long t) {
        int req2 = 0, req3 = 0, req5 = 0, req7 = 0;

        while (t % 2 == 0) {
            req2++;
            t /= 2;
        }

        while (t % 3 == 0) {
            req3++;
            t /= 3;
        }

        while (t % 5 == 0) {
            req5++;
            t /= 5;
        }

        while (t % 7 == 0) {
            req7++;
            t /= 7;
        }

        if (t > 1)
            return "-1";

        int n = (int)num.size();

        vector<array<int,4>> pref(n + 1, {0,0,0,0});
        vector<bool> noZero(n + 1, true);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i];

            int d = num[i] - '0';

            noZero[i + 1] = noZero[i] && (d != 0);

            if (d != 0) {
                for (int k = 0; k < 4; k++) {
                    pref[i + 1][k] += contrib[d][k];
                }
            }
        }

        // num itself
        if (noZero[n] &&
            pref[n][0] >= req2 &&
            pref[n][1] >= req3 &&
            pref[n][2] >= req5 &&
            pref[n][3] >= req7) {
            return num;
        }

        // same length answer
        for (int i = n - 1; i >= 0; i--) {
            if (!noZero[i])
                continue;

            int rem2 = max(0, req2 - pref[i][0]);
            int rem3 = max(0, req3 - pref[i][1]);
            int rem5 = max(0, req5 - pref[i][2]);
            int rem7 = max(0, req7 - pref[i][3]);

            int cur = num[i] - '0';

            for (int dig = max(1, cur + 1); dig <= 9; dig++) {
                int a = max(0, rem2 - contrib[dig][0]);
                int b = max(0, rem3 - contrib[dig][1]);
                int c = max(0, rem5 - contrib[dig][2]);
                int d = max(0, rem7 - contrib[dig][3]);

                int suffixLen = n - i - 1;

                if (need(a, b, c, d) <= suffixLen) {
                    string ans = num.substr(0, i);
                    ans.push_back(char('0' + dig));
                    ans += buildSuffix(suffixLen, a, b, c, d);
                    return ans;
                }
            }
        }

        // longer length answer
        int L = max(n + 1, need(req2, req3, req5, req7));

        return buildSuffix(L, req2, req3, req5, req7);
    }
};