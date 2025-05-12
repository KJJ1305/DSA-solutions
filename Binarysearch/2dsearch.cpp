class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M=matrix.size();
        int N=matrix[0].size();
        int st=0;
        int p,q;
        int end=M*N-1;
        while(st<=end){
            int mid=(st+end)/2;
            p=mid/N;
            q=mid%N;
            if(matrix[p][q]==target)
                return true;
            if(matrix[p][q]<target)
                st=mid+1;
            else
                end=mid-1;
        }
        return false;
    }
};