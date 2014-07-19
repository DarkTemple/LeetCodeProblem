class Solution {
public:
    void comb(vector<int> candidates, int index, int sum, int target, vector<vector<int>> &res, vector<int> &path) {
    	if(sum>target)return;
		if(sum==target){res.push_back(path);return;}
		for(int i= index; i<candidates.size();i++) {
			path.push_back(candidates[i]);
			comb(candidates,i,sum+candidates[i],target,res,path);
			path.pop_back();
		}
	}
    
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Note: The Solution object is instantiated only once.
        sort(candidates.begin(),candidates.end());
		vector<vector<int>> res;
		vector<int> path;
		comb(candidates,0,0,target,res,path);
		return res;
    }
};