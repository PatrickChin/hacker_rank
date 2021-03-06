// https://www.hackerrank.com/challenges/the-grid-search

#include <iostream>
#include <vector>

using namespace std;

bool found(const vector<string> &G, const vector<string> &g,
        const size_t &h, const size_t &w, const size_t &ii, const size_t &jj)
{
    for (size_t i = 1; i < h; ++i)
        for (size_t j = 0; j < w; ++j)
            if (G[ii+i][jj+j] != g[i][j])
                return false;
    return true;
}

bool solve(const vector<string> &G, const size_t &H, const size_t &W,
           const vector<string> &g, const size_t &h, const size_t &w)
{
    for (size_t i = 0; i <= H-h; ++i)
    {
        size_t pos = G[i].find(g[0]);
        while (pos != string::npos)
        {
            if (found(G, g, h, w, i, pos))
                return true;
            pos = G[i].find(g[0], pos+1);
        }
    }
    return false;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int W, H;
        cin >> H >> W;
        vector<string> G(H);
        for (int i = 0; i < H; ++i)
            cin >> G[i];

        int w, h;
        cin >> h >> w;
        vector<string> g(h);
        for (int i = 0; i < h; ++i)
            cin >> g[i];

        cout << (solve(G, H, W, g, h, w) ? "YES" : "NO") << endl;
    }
}
