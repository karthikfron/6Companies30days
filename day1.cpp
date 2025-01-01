Minimum Cost to Convert String I.
  class Solution {
public:

  void floydwarshall(vector<vector<long long>> & adjmatrix,vector<char>& original, vector<char>& changed, vector<int>& cost){
    for (int i=0;i<original.size();i++){
             int s= original[i]-'a';
             int t= changed[i]-'a';
             adjmatrix[s][t]=min(adjmatrix[s][t],(long long)cost[i]);
    }
             for(int k=0;k<26;k++){
                for (int i=0;i<26;i++){
                    for (int j=0;j<26;j++){

                    if (adjmatrix[i][k] != LONG_MAX && adjmatrix[k][j] != LONG_MAX) {
                        adjmatrix[i][j] = min(adjmatrix[i][j], adjmatrix[i][k] + adjmatrix[k][j]);
                    }
                    }

                }
             

        
    }
  }
   
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        //our final result with min cost decalred
        long  long ans=0;
        //declare a 2d vector with 26 rows and each row with 26 col with some long number 
        vector<vector< long long >> adjmatrix(26,vector< long long>(26,LONG_MAX));
        for (int i = 0; i < 26; i++) {
            adjmatrix[i][i] = 0;
        }
        //this magic function will update continously untill get shortest path matrix
        floydwarshall(adjmatrix, original, changed, cost);

        for (int i=0;i<source.size();i++){
            if(source[i]==target[i]){
                continue;
            }
            if(adjmatrix[source[i]-'a'][target[i]-'a']==LONG_MAX){
                return -1;
            }
            ans=ans+adjmatrix[source[i]-'a'][target[i]-'a'];
        }
        return ans;

        

        
    }
};
