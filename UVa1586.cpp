#include <cstdio>
#include <cstring>
#include <cctype>

 double getMole(char c){
     if(c=='C') return 12.01;
     else if(c=='H') return 1.008;
     else if(c=='O') return 16.00;
     else if(c=='N') return 14.01;
     else return 0;
 }

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        char ch[85];
        scanf("%s", ch);
        int len = strlen(ch);
        double total = 0;
        for(int i=0;i<len;){
            int j=i++;
            while(!isalpha(ch[i]) && i<len) i++;
            if(i-j == 1) total+=getMole(ch[j]);
            else if(i-j==2) total+=getMole(ch[j])*(ch[j+1]-'0');
            else if(i-j==3) total+=getMole(ch[j])*((ch[j+1]-'0')*10+ch[j+2]-'0');
        }
        printf("%.3lf\n", total);
    }
}
