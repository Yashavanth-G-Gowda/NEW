int minOperations(char** logs, int logsSize) {
    int j=0;
    for(int i=0;i<logsSize;i++){
        if(strcmp(logs[i], "../")==0 ){
            if(j>0)
                j--;
        }
        else if(strcmp(logs[i], "./")!=0 )
            j++;
    }
    return j;
}
