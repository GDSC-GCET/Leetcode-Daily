class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
      
      int n=matches.size();
     map<int,int> lost_map;
      vector <int> no_loss,one_loss;
      int x;
     
      for(int i=0; i<n; i++){
       lost_map[matches[i][1]]++; }
      
    for(int i=0; i<n; i++){
         if(lost_map.find(matches[i][0])==lost_map.end()){
         lost_map[matches[i][0]]=0; }
       }
  
     for( auto  i : lost_map){
      if(i.second==1){
         x=i.first;
        one_loss.push_back(x); }
      if(i.second==0){
         x=i.first;
         no_loss.push_back(x);}
    }
    
    
     return   {no_loss,one_loss};  
    }
};
