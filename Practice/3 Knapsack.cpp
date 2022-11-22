#include <bits/stdc++.h>
using namespace std;
int rec(int id, int n, vector<int> &price, vector<int> &weight, int wt)
{
    if (id < 0)
        return 0;
    if (id == 0)
    {
        if (wt >= weight[0])
            return price[0];
        return 0;
    }
    int not_pick = rec(id - 1, n, price, weight, wt);
    int pick = 0;
    if (weight[id] <= wt)
        pick = rec(id - 1, n, price, weight, wt - weight[id]) + price[id];
    return max(pick, not_pick);
}
int rec_memo(int id, int n, vector<int> &price, vector<int> &weight, int wt, vector<vector<int>> &dp)
{
    if (id < 0)
        return 0;
    if (id == 0)
    {
        if (wt >= weight[0])
            return price[0];
        return 0;
    }
    if (dp[id][wt] != -1)
        return dp[id][wt];
    int not_pick = rec_memo(id - 1, n, price, weight, wt, dp);
    int pick = 0;
    if (weight[id] <= wt)
        pick = rec_memo(id - 1, n, price, weight, wt - weight[id], dp) + price[id];
    return dp[id][wt] = max(pick, not_pick);
}

int iterative_knapsack(int n, vector<int> &price, vector<int> &weight, int wt)
{
    vector<vector<int>> dp(n + 1, vector<int>(wt + 1, 0));
    // base cases
    for (int i = 1; i <= wt; i++)
    {
        if (i >= weight[0])
            dp[0][i] = price[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= wt; j++)
        {
            int not_pick = dp[i - 1][j];
            int pick = 0;
            if (weight[i] <= j)
                pick = dp[i - 1][j - weight[i]] + price[i];
            dp[i][j] = max(pick, not_pick);
        }
    }
    return dp[n - 1][wt];
}
int iterative_knapsack_op(int n, vector<int> &price, vector<int> &weight, int wt)
{
    vector<vector<int>> dp(2, vector<int>(wt + 1, 0));
    // base cases
    for (int i = 1; i <= wt; i++)
    {
        if (i >= weight[0])
            dp[0][i] = price[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= wt; j++)
        {
            int not_pick = dp[0][j];
            int pick = 0;
            if (weight[i] <= j)
                pick = dp[0][j - weight[i]] + price[i];
            dp[1][j] = max(pick, not_pick);
        }
        swap(dp[0], dp[1]);
    }
    return dp[0][wt];
}
int main()
{
    int n, wt;
    cin >> n >> wt;
    vector<int> price(n, 0);
    vector<int> weight(n, 0);
    for (int i = 0; i < n; i++)
        cin >> price[i];
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    cout << rec(n - 1, n, price, weight, wt) << endl;
    vector<vector<int>> dp(n + 1, vector<int>(wt + 1, -1));
    cout << rec_memo(n - 1, n, price, weight, wt, dp) << endl;
    cout << iterative_knapsack(n, price, weight, wt) << endl;
    cout << iterative_knapsack_op(n, price, weight, wt) << endl;
}

/*
3 50
60 100 120
10 20 30
*/