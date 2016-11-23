#include <cstdio>
#include <cstring>
using namespace std;
char s[100005], t[100005];

int main()
{
	while(scanf("%s %s", s, t) != EOF)
	{
		int ls = strlen(s);
		int lt = strlen(t);
		int is=0, it=0;
		for(it=0;it<lt;it++){
			if(s[is] == t[it]) is++;
		}
		if(is == ls){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}	
	return 0;	
}
