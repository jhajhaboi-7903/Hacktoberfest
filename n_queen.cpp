[22:36, 06/10/2021] Anurag: #include<iostream>
#include<vector>
using namespace std;

int cnt = 0;

void PrintingChessBoard(vector<vector<int>> &ChessBoard) {
	for (int i = 0 ; i < ChessBoard.size() ; i++) {
		for (int j = 0 ; j < ChessBoard.size() ; j++) {
			cout << ChessBoard[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

bool IsQueenSafe(vector<vector<int>> &ChessBoard , int i , int j) {
	for (int ro = 0 ; ro < i ; ro++) {
		for (int col = 0 ; col < ChessBoard.size() ; col++) {
			if (ChessBoard[ro][col] != 0) {
				if (j == col || abs(i - ro) == abs(j - col))
					return false;
			}
		}
	}
	return true;




	// for (int ro = i - 1 , col = j ; ro >= 0 ; ro--) {
	// 	if (ChessBoard[ro][col] != 0)
	// 		return false;
	// }
	// for (int ro = i - 1 , col = j - 1 ; i >= …
[22:53, 06/10/2021] Anurag: #include<iostream>
#include<cstring>
using namespace std;

// int dp[1000][10000];
// int knapsack(int wt[] , int val[] , int n , int W) {
// 	if (n == 0 || W == 0)
// 		return 0;

// 	if (dp[n][W] != -1)
// 		return dp[n][W];

// 	if (wt[n - 1] <= W)
// 		return dp[n][W] = max(val[n - 1] + knapsack(wt , val , n - 1 , W - wt[n - 1]) ,
// 		                      knapsack(wt , val , n - 1 , W));
// 	else
// 		return dp[n][W] = knapsack(wt , val , n - 1 , W);
// }

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	// memset(dp , -1 , sizeof(dp));
	int n , W;
	cin >> n >> W;

	int wt[n] , val[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> wt[i] ;
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> val[i] ;
	}

	// cout << "Max profit -> " << knapsack(wt , val , n , W) << endl;

	int dp[n + 1][W + 1];

	for (int i = 0 ; i <= n ; i++) {
		for (int j = 0 ; j <= W ; j++) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;
		}
	}

	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= W ; j++) {
			if (wt[i - 1] <= j) {
				dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]] , dp[i - 1][j]);
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	for (int i = 0 ; i <= n ; i++) {
		for (int j = 0 ; j <= W ; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Max profit -> " << dp[n][W];

	return 0;
}
