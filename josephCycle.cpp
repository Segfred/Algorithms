//dp[i]=(dp[i-1]+k)%i,dp[i]表示i个人的时候最后剩下人的序号，或者说i个人做约瑟夫环游戏最后的人剩下的下标
//http://qiemengdao.iteye.com/blog/1264485 f1 = 0，只有一个人的时候剩的编号为0
int getLast(int n, int k){
if(n<1||k<1) return 0;
int res=0;//int res=1是错的，考虑n=2,k=1，最后2%2会变成0，因此加1必须放在最后
for(int i=2;i<=n;++i) res=(res+k)%i;//剩最后一个生会变成0, so the index must begin from 0
return res+1;//return res(之前res=1错)
}

/*wrong solution
int getLast(int n, int k){
if(n<1||k<1) return 0;
int res=1;//int res=1是错的，考虑n=2,k=1，最后2%2会变成0，因此加1必须放在最后
for(int i=2;i<=n;++i) res=(res+k)%i;//剩最后一个生会变成0, so the index must begin from 0
return res;//return res(之前res=1错)
}
