int findTheWinner(int n, int k) {
    int i,j,p,r,a[n+1];
    for(i=0;i<n;i++)
        a[i]=i+1;
    j=n;i=0; p=1;
    while(j>1){
        while(p!=k){
            i=(i+1)%n;
            if(a[i]!=0)
                p++;
        }
        a[i]=0;
        j--;
        p=0;
    }
    for(i=0;i<n;i++){
        if(a[i]!=0)
            r=a[i];
    }
    return r;
}
