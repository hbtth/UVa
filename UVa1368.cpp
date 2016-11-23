#include <cstdio>
#include <cstring>
char ch[1010];
int cnt[1010][4];

int _t(char c){
	switch(c){
		case 'A':return 0;			
		case 'C':return 1;
		case 'G':return 2;
		case 'T':return 3;
	}
	return -1; 
}

char _rt(int i){
	switch(i){
		case 0:return 'A';			
		case 1:return 'C';
		case 2:return 'G';
		case 3:return 'T';
	}
	return -1; 
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int m, n;
		scanf("%d%d", &m, &n);
		for(int i=0;i<n;i++){
			cnt[i][0]=cnt[i][1]=cnt[i][2]=cnt[i][3]=0;
		}
		for(int i=0;i<m;i++){
			scanf("%s", ch);
			for(int j=0;j<n;j++){
				++cnt[j][_t(ch[j])];
			}
		}
		int ans=0;
		for(int i=0;i<n;i++){
			int k=0;
			for(int j=1;j<4;j++){
				if(cnt[i][j]>cnt[i][k]) k=j;
			}
			ans+=m-cnt[i][k];
			printf("%c", _rt(k));
		}
		printf("\n%d\n", ans);
	}		
	return 0;
}
