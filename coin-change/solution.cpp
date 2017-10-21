// https://www.hackerrank.com/challenges/coin-change/problem

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

template<class InputIt>
long countways_impl(InputIt first, InputIt const& last, int const& goal,
        unordered_map<long, long> &store)
{
    if (goal == 0)
        return 1;

    if (goal < 0)
        return 0;

    if (first == last)
        return 0;

    long ways = 0;
    int coin = *first++;

    long key = coin | (long) goal << 32;
    if (store.find(key) != store.end())
        return store[key];

    for (int rem = goal; rem >= 0; rem -= coin)
        ways += countways_impl(first, last, rem, store);

    store[key] = ways;
    return ways;
}

template<class InputIt>
long countways(InputIt first, InputIt const& last, int const& goal)
{
    unordered_map<long, long> store;
    return countways_impl(first, last, goal, store);
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> c{};
    c.reserve(m);
    for (int i = 0; i < m; i++)
    {
        int ci; cin >> ci;
        if (ci <= n)
            c.push_back(ci);
    }

    cout << countways(c.begin(), c.end(), n) << endl;

    return 0;
}
