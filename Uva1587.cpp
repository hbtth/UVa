#include <cstdio>
#include <algorithm>
using namespace std;
struct Face{
	int w;
	int h;
	bool eql(Face b){
		return w == b.w && h == b.h;
	}	
}f[6];

bool cmp(Face a, Face b){
	if(a.w != b.w) return a.w < b.w;
	return a.h < b.h;
}

int main(){
	int all[12];
	while(scanf("%d%d", &f[0].w, &f[0].h) != EOF){
		all[0]=f[0].w;all[1]=f[0].h;
		for(int i=1;i<6;i++){
			scanf("%d%d", &f[i].w, &f[i].h);
			all[i*2]=f[i].w;all[i*2+1]=f[i].h;
		}
		for(int i=0;i<6;i++){
			if(f[i].w > f[i].h) swap(f[i].w, f[i].h);
		}
		sort(f, f+6, cmp);
		sort(all, all+12);
		if(f[0].eql(f[1]) && f[2].eql(f[3]) && f[4].eql(f[5])){
			bool flag=true;
			for(int i=0;i<3;i++){
				for(int j=1;j<4;j++){
					if(all[4*i] != all[4*i+j]){
						flag=false;
						break;
					}
				}
			}	
			if(flag){
				printf("POSSIBLE\n");
				continue;
			}
		}
		printf("IMPOSSIBLE\n");
	}
	return 0;	
}
