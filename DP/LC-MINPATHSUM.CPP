class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid[0].size();
        int n=grid.size();
       // cout<<m<<" "<<n<<endl;
        long long int k[n+1][m+1];

        memset(k,-1,sizeof(k));

        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    k[i][j]=0;
                }
                
              
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<grid[i-1][j-1]<<" ";
                if(j==1){
                    k[i][j]=(grid[i-1][j-1]+k[i-1][j]);
                }
                else if(i==1){
                     k[i][j]=(grid[i-1][j-1]+k[i][j-1]);
                }
                else{
                    
                    k[i][j]= min((int)grid[i-1][j-1]+k[i-1][j],(int)grid[i-1][j-1]+k[i][j-1]);
                  }
                  cout<<k[i][j]<<endl;
              
            }
        }
       return k[n][m];


    }
};