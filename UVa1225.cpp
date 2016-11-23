#include <cstdio>
#include <cstring>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int mp[10];
        memset(mp, 0, sizeof(mp));
        for(int i=1;i<=n;i++){
            int k=i;
            do{
                mp[k%10]++;
                k/=10;
            }while(k!=0);
        }
        for(int i=0;i<10;i++){
            if(i!=0) printf(" ");
            printf("%d", mp[i]);
        }
        printf("\n");
    }
    return 0;
}

