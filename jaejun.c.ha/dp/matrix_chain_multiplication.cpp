int mcm(int m[][2], int n){
  int dp[SIZE][SIZE] = {0};
  
  for (register int i = 1; i < n; ++i) {
    for (register int j = 1; j <= n - i; ++j){
      register int k = j + i;
            	
      dp[j][k] = MAX;
      for (register int l = j; l <= k - 1; ++l)
        if (dp[j][k] > dp[j][l] + dp[l + 1][k] + m[j - 1][0] * m[l][1] * m[k][1])
          dp[j][k] = dp[j][l] + dp[l + 1][k] + m[j - 1][0] * m[l][1] * m[k][1];
  }

  return dp[1][n];
}
