#include <cstdio>
#include <cstring>
int rc[3010];
int mp[3010];

int main(){
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF){
		memset(rc, -1, sizeof(rc));
		memset(mp, -1, sizeof(mp));
		int ss = m/n, res=m%n, cnt=0;
		while(true){
			if(mp[res]!=-1 || res==0) break;
			mp[res]=cnt;
			rc[cnt++]=res*10/n;
			res=(res*10)%n;
		}
		printf("%d/%d = %d.", m, n, ss);
		if(res == 0){
			for(int i=0;i<cnt;i++){
				printf("%d", rc[i]);
			}
			printf("(0)\n");
			printf("   1 = number of digits in repeating cycle\n");
		}else{
			int len = cnt-mp[res];
			for(int i=0;i<mp[res];i++){
				printf("%d", rc[i]);	
			}
			printf("(");
			for(int i=mp[res];i<cnt && i<50;i++){
				printf("%d", rc[i]);
			}
			if(cnt>50) printf("...");
			printf(")\n");
			printf("   %d = number of digits in repeating cycle\n",len);
		}
		printf("\n");
	}
	return 0;
}
