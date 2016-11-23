#include <cstdio>
#include <cstring>
#include <cmath>

long long E[15][35];
double M[15][35];

int main()
{
	double m;
	long long e;
	for(int i=0;i<=9;i++){
		for(int j=1;j<=30;j++){
			e = (1 << j)-1;
			m = 1-1.0/(1 << (i+1));
			double t = log10(m) + e*log10(2);
			E[i][j] = t/1;
			M[i][j] = pow(10, t-E[i][j]);
		}
	}
	char ch[20];
	while(scanf("%s", ch), strcmp(ch, "0e0")!=0){
		*(strchr(ch, 'e'))=' ';
		sscanf(ch, "%lf %lld", &m, &e);
		//printf("%lf %lld\n", m, e);
		bool flag=true;
		for(int i=0;i<=9 && flag;i++){
			for(int j=1;j<=30;j++){
			//	printf("%d-%d %lld %lf\n",i,j, E[i][j], M[i][j]);
				if(e == E[i][j] && fabs(m-M[i][j]) < 1e-4){
					printf("%d %d\n", i, j);
					flag=false;
					break;
				}
			}
		}
	}
	return 0;
}
