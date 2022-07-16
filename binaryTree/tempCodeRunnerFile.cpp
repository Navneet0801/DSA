bool pathSumFast(node* temp, int targetSum, vector<int> &ans){
    if(!temp)   return false;

    ans.push_back(temp -> data);

    pathSumFast(temp -> left, targetSum, ans);
    pathSumFast(temp -> right, targetSum, ans);

    int sum = 0;
    for(int i=0; i<ans.size(); i++){
        sum += ans[i];
        if(sum == targetSum)
            return true;
    }

    ans.pop_back();
}