#include <cstdio>
#include <cstring>

char ch[5][5];

int main()
{
    int cnt=1;
    while(gets(ch[0])){
    	if(ch[0][0] == 'Z') break;
    	for(int i=1;i<5;i++){
	    	gets(ch[i]);
	    }
        int ti=0, tj=0;
        for(int i=0;i<5;i++){
        	for(int j=0;j<5;j++){
                if(ch[i][j]<'A' || ch[i][j]>'Z'){
                    ti=i;tj=j;
                }
            }
        }
        char move;
        bool flag=true;
        while((move = getchar()) != '0'){
            if(!flag) continue;
            if(move == 'A'){
                ti--;
            }else if(move == 'R'){
                tj++;
            }else if(move == 'B'){
                ti++;
            }else if(move == 'L'){
                tj--;
            }
            //printf("ti==%d tj==%d\n", ti, tj);
            if(ti<0 || ti>=5 || tj<0 || tj>=5){
                flag=false;
                continue;
            }
            if(move == 'A'){
                ch[ti+1][tj]=ch[ti][tj];
            }else if(move == 'R'){
                ch[ti][tj-1]=ch[ti][tj];
            }else if(move == 'B'){
                ch[ti-1][tj]=ch[ti][tj];
            }else if(move == 'L'){
                ch[ti][tj+1]=ch[ti][tj];
            }
            ch[ti][tj]=' ';
        }

        if(cnt>1) printf("\n");
        printf("Puzzle #%d:\n", cnt);
        ++cnt;
        if(flag){
            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    if(j!=0) printf(" ");
                    printf("%c",ch[i][j]);
                }
                printf("\n");
            }
        }else{
            printf("This puzzle has no final configuration.\n");
        }
        getchar();
    }
    return 0;
}
