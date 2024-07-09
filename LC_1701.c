double averageWaitingTime(int** c, int n, int* customersColSize) {
    int b=c[0][0];
    double sum=0;
    for(int i=0;i<n;i++){
        if(b>=c[i][0]){
            b+=c[i][1];
            sum+=b-c[i][0];
        }else{
            b=c[i][0]+c[i][1];
            sum+=c[i][1];
        }
    }
    double avg = sum/n;
    return avg;
}
