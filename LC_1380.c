/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* luckyNumbers (int** a, int m, int* n, int* r) {
    int *res=(int *)malloc(sizeof(int)*m);
    int i,j,k,x,min,max;
    *r=0;
    for(i=0;i<m;i++){
        min=a[i][0];
        x=0;
        for(j=1;j<n[i];j++){
            if(min>a[i][j]){
                min=a[i][j];
                x=j;
            }
        }
        max=min;
        for(k=0;k<m;k++){
            if(a[k][x]>max){
                max=a[k][x];
                break;
            }
        }
        if(max==min){
            res[*r]=min;
            (*r)++;
        }
    }
    return res;
} 
