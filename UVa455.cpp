#include <cstdio>
#include <cstring>
int main()
{
    int N;
    scanf("%d", &N);
    while(N--){
        char ch[85];
        scanf("%s", ch);
        int len = strlen(ch);
        int ans=len;
        for(int i=1;i<=len;i++){
            if(len%i==0){
                bool flag=true;
                for(int j=0;j<len-i;j++)
                {
                    if(ch[j] != ch[j+i])
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag)
                {
                    ans=i;
                    break;
                }
            }
        }
        printf("%d\n",ans);
        if(N>0) printf("\n");
    }
    return 0;
}