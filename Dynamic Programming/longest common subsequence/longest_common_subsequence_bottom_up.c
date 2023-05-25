//by SURANJAN DAS
// Dynamic Programming C implementation of LCS problem
#include <stdio.h>
#include <string.h>

int max(int a, int b) { return (a > b) ? a : b; }

// Returns length of LCS for X[0..m-1], Y[0..n-1]
int lcs(char* X, char* Y, int m, int n)
{
	// Initializing a matrix of size (m+1)*(n+1)
	int dp[m + 1][n + 1];

	// Following steps build dp[m+1][n+1] in bottom up
	// fashion. Note that dp[i][j] contains length of LCS of
	// X[0..i-1] and Y[0..j-1]
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;

			else if (X[i - 1] == Y[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;

			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	// dp[m][n] contains length of LCS for X[0..n-1]
	// and Y[0..m-1]
	return dp[m][n];
}

// Driver code
int main()
{
	char* X = "AGGTAB";
	char* Y = "GXTXAYB";
	int m = strlen(X);
	int n = strlen(Y);

	int length = lcs(X, Y, m, n);
	printf("Length of LCS: %d\n", length);

	return 0;
}

