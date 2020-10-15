/* reference: 
https://huiyu.tistory.com/entry/DP-연쇄행렬-최소곱셈-알고리즘 
https://source-sc.tistory.com/24

dp[SIZE][SIZE] = {0};

dp[i][j] = min(dp[i][k] + dp[k+1][j] + matrix[i][0] * matrix[k][1] * matrix[j][1]) (i <= k < j)

*/



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
