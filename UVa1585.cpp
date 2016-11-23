#include <cstdio>
#include <cstring>
int main() {
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char ch[85];
        int score=0;
        scanf("%s", ch);
        int len = strlen(ch);
        int tmp=0;
        for(int i=0;i<len;i++)
        {
            if(ch[i] == 'O'){
                tmp++;
            }else if(ch[i] == 'X'){
                tmp=0;
            }
            score+=tmp;
        }
        printf("%d\n", score);
    }
    return 0;
}