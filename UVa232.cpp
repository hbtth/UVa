#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
char ch[15][15];
int pos[15][15];
struct Tmp{
	int p;	
	string s;
};
bool cmp(Tmp t1, Tmp t2){
	return t1.p<t2.p;	
}

int main()
{
	int m,n;
	int cnt=1;
	while(scanf("%d", &m) != EOF){
		if(m==0) break;
		scanf("%d", &n);
		for(int i=0;i<m;i++){
			scanf("%s", ch[i]);
		}
		
		int tmp=1;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(ch[i][j] == '*')continue;
				if(i==0 || j==0 || ch[i-1][j] == '*' || ch[i][j-1] == '*'){
					pos[i][j]=tmp++;
				}else{
					pos[i][j]=-1;
				}
			}
		}
		if(cnt>1) printf("\n");
		printf("puzzle #%d:\n", cnt);
		++cnt;
		printf("Across\n");
		for(int i=0;i<m;i++){
			bool fg=false;
			for(int j=0;j<n;j++){
				if(ch[i][j] == '*'){
					if(fg){
						printf("\n");
						fg=false;
					}
				}else{
					if(!fg){
						printf("%3d.",pos[i][j]);
						fg=true;
					}
					printf("%c", ch[i][j]);
				}
			}
			if(fg) printf("\n");
		}
		
		
		printf("Down\n");
		vector<Tmp> vec;
		Tmp tt;
		for(int j=0;j<n;j++){
			bool fg=false;
			for(int i=0;i<m;i++){
				if(ch[i][j] == '*'){
					if(fg){
						vec.push_back(tt);
						tt.s.clear();
						fg=false;
					}
				}else{
					if(!fg){
						tt.p=pos[i][j];
						fg=true;
					}
					tt.s+=ch[i][j];
				}
			}
			if(fg){
				vec.push_back(tt);
				tt.s.clear();
			} 
		}
		sort(vec.begin(), vec.end(), cmp);
		for(int i=0;i<vec.size();i++){
			printf("%3d.%s\n", vec[i].p, vec[i].s.c_str());
		}
		
	}
	return 0;
}
