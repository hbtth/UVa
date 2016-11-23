#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[105], t[105];

int _t(char c){
	return c-'0';
}

int main()
{
	while(scanf("%s%s", s, t) != EOF){
		int ls = strlen(s);
		int lt = strlen(t);
		
		int minLen = ls+lt;
		for(int i=0;i<ls;i++){
			bool flag = true;
			for(int j=0;j<lt && i+j<ls;j++){
				if(_t(s[i+j]) + _t(t[j]) > 3){
					flag= false;
					break;
				}
			}
			if(flag){
				minLen = min(minLen, i+max(lt, ls-i));
			}
		}
		for(int j=0;j<lt;j++){
			bool flag = true;
			for(int i=0;i<ls && i+j<lt;i++){
				if(_t(s[i]) + _t(t[i+j]) > 3){
					flag= false;
					break;
				}
			}
			if(flag){
				minLen = min(minLen, j+max(ls, lt-j));
			}
		}
		printf("%d\n", minLen);
	}	
	return 0;
}
