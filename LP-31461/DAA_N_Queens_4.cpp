bool isSafe(int row, int col,  vector<int>&dp, int n){
        for(int i=0 ; i<row ; i++){
            if(dp[i]==col || row-i==abs(col-dp[i]))return false;
        }
        return true;
    }
    
    bool solve(int row,vector<vector<string>>&ans, int n,   vector<int>&dp, vector<string>&curr){
       // if(ans.size()==1)return;
        if(row>=n){ans.push_back(curr);return true;}
        
        for(int col=0 ; col<n ; col++){
            if(isSafe(row,col,dp,n)){
                dp[row]=col;
                curr[row][col]='Q';
                if(solve(row+1,ans,n,dp,curr))return true;
                curr[row][col]='.';
            }
        }
        return false;
    }
    