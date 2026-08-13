class Solution {
public:
    struct Node {
        int maxLen;
        int prefixLen;
        int suffixLen;

        char leftChar;
        char rightChar;

        int len;

        Node() {
            maxLen = 0;
            prefixLen = 0;
            suffixLen = 0;
            leftChar = '#';
            rightChar = '#';
            len = 0;
        }
    };

    vector<Node> seg;

    Node mergeNode(Node left, Node right) {
        if (left.len == 0) return right;
        if (right.len == 0) return left;

        Node res;

        res.len = left.len + right.len;

        res.leftChar = left.leftChar;
        res.rightChar = right.rightChar;

        res.prefixLen = left.prefixLen;
        if (left.prefixLen == left.len &&
            left.rightChar == right.leftChar) {
            res.prefixLen = left.len + right.prefixLen;
        }

        res.suffixLen = right.suffixLen;
        if (right.suffixLen == right.len &&
            left.rightChar == right.leftChar) {
            res.suffixLen = right.len + left.suffixLen;
        }

        res.maxLen = max(left.maxLen, right.maxLen);

        if (left.rightChar == right.leftChar) {
            res.maxLen = max(
                res.maxLen,
                left.suffixLen + right.prefixLen
            );
        }

        return res;
    }

    void buildSegmentTree(int index,
                          int low,
                          int high,
                          string &s) {
        if (low == high) {
            seg[index].maxLen = 1;
            seg[index].prefixLen = 1;
            seg[index].suffixLen = 1;
            seg[index].leftChar = s[low];
            seg[index].rightChar = s[low];
            seg[index].len = 1;
            return;
        }

        int mid = (low + high) / 2;

        buildSegmentTree(2 * index + 1, low, mid, s);
        buildSegmentTree(2 * index + 2, mid + 1, high, s);

        seg[index] = mergeNode(
            seg[2 * index + 1],
            seg[2 * index + 2]
        );
    }

    void updateSegmentTree(int index,
                           int low,
                           int high,
                           int pos,
                           char val) {
        if (low == high) {
            seg[index].maxLen = 1;
            seg[index].prefixLen = 1;
            seg[index].suffixLen = 1;
            seg[index].leftChar = val;
            seg[index].rightChar = val;
            seg[index].len = 1;
            return;
        }

        int mid = (low + high) / 2;

        if (pos <= mid) {
            updateSegmentTree(
                2 * index + 1,
                low,
                mid,
                pos,
                val
            );
        } else {
            updateSegmentTree(
                2 * index + 2,
                mid + 1,
                high,
                pos,
                val
            );
        }

        seg[index] = mergeNode(
            seg[2 * index + 1],
            seg[2 * index + 2]
        );
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        int n = s.size();

        seg.resize(4 * n);

        buildSegmentTree(0, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int idx = queryIndices[i];
            char ch = queryCharacters[i];

            updateSegmentTree(0, 0, n - 1, idx, ch);

            ans.push_back(seg[0].maxLen);
        }

        return ans;
    }
};