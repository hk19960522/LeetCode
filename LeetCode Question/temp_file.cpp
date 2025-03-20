class Solution {
public:
    int find(vector<int> &disjoint, int x)
    {
        return (disjoint[x] == x) ? x : disjoint[x] = find(disjoint, disjoint[x]);
    }

    void merge(vector<int> &disjoint, vector<int> &min_path, int x, int y, int length)
    {
        int fx = find(disjoint, x), fy = find(disjoint, y);
        if (fx == fy) {
            min_path[fx] &= length;
        }
        else {
            disjoint[fy] = fx;
            min_path[fx] &= (length & min_path[fy]);
        }
    }

    int find_path(vector<int> &disjoint, vector<int> &min_path, int x, int y)
    {
        int fx = find(disjoint, x), fy = find(disjoint, y);
        if (fx == fy) return min_path[fx];
        return -1;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> disjoint(n, 0), min_path(n, -1);
        vector<int> res;

        for (int i = 0; i < n; i++) {
            disjoint[i] = i;
        }

        for (int i = 0; i < edges.size(); i++) {
            int x = edges[i][0], y = edges[i][1], len = edges[i][2];
            merge(disjoint, min_path, x, y, len);
        }

        for (int i = 0; i< query.size(); i++) {
            int x = query[i][0], y = query[i][1];
            res.push_back(find_path(disjoint, min_path, x, y));
        }

        return res;
    }
};class Solution {
public:
    int find(vector<int> &disjoint, int x)
    {
        return (disjoint[x] == x) ? x : disjoint[x] = find(disjoint, disjoint[x]);
    }

    void merge(vector<int> &disjoint, vector<int> &min_path, int x, int y, int length)
    {
        int fx = find(disjoint, x), fy = find(disjoint, y);
        if (fx == fy) {
            min_path[fx] &= length;
        }
        else {
            disjoint[fy] = fx;
            min_path[fx] &= (length & min_path[fy]);
        }
    }

    int find_path(vector<int> &disjoint, vector<int> &min_path, int x, int y)
    {
        int fx = find(disjoint, x), fy = find(disjoint, y);
        if (fx == fy) return min_path[fx];
        return -1;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> disjoint(n, 0), min_path(n, -1);
        vector<int> res;

        for (int i = 0; i < n; i++) {
            disjoint[i] = i;
        }

        for (int i = 0; i < edges.size(); i++) {
            int x = edges[i][0], y = edges[i][1], len = edges[i][2];
            merge(disjoint, min_path, x, y, len);
        }

        for (int i = 0; i< query.size(); i++) {
            int x = query[i][0], y = query[i][1];
            res.push_back(find_path(disjoint, min_path, x, y));
        }

        return res;
    }
};
