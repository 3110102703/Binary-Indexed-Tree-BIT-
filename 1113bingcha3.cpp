#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 10001
struct stu{
	int id, idf, idm;
	vector<int> idc;
	int num, area;
};
struct out{
	int id,people;
	double numt, areat;
	int flag;
};
int fa[maxn],root[maxn];
stu st[maxn];
out rst[maxn];
int findfa(int x){
	int a=x;
	while (x != fa[x]){
		x = fa[x];
	}
	while (a != fa[a]){
		int z = fa[a];
		fa[a] = x;
		a = z;
	}
	return x;
}
void unionset(int t1, int t2){
	int f1 = findfa(t1);
	int f2 = findfa(t2);
	if (f1 < f2){
		fa[f2] = f1;
	}
	else{
		fa[f1] = f2;
	}
}
int cmp1(out t1, out t2){
	if (t1.flag ==1 && t2.flag==1){
		if (t1.areat == t2.areat){
			return t1.id<t2.id;
		}
		else{
			return t1.areat>t2.areat;
		}
	}
	else{
		return t1.flag > t2.flag;
	}
}
int main(){
	int n;
	cin >> n;
	int k, exist[maxn] = {0};
	for (int i = 0; i < maxn; i++){
		fa[i] = i;
	}
	for (int i = 0; i < n; i++){
		scanf("%d %d %d %d", &st[i].id, &st[i].idf, &st[i].idm, &k);
		exist[st[i].id] = 1;
		if (st[i].idf != -1){ 
			unionset(st[i].id, st[i].idf); exist[st[i].idf] = 1; 
		//	printf("1 %d %d %d %d\n", st[i].id, st[i].idf, fa[st[i].id], fa[st[i].idf]);
		}
		if (st[i].idm != -1){ 
			unionset(st[i].id, st[i].idm); exist[st[i].idm] = 1; 
		//	printf("2 %d %d %d %d\n", st[i].id, st[i].idm, fa[st[i].id], fa[st[i].idm]);
		}
		st[i].idc.resize(k);
		for (int j = 0; j < k; j++){
			scanf("%d", &st[i].idc[j]);
			exist[st[i].idc[j]] = 1;
			unionset(st[i].id, st[i].idc[j]);
			//printf("3 %d %d %d %d\n", st[i].id, st[i].idc[j], fa[st[i].id], fa[st[i].idc[j]]);
		}
		scanf("%d %d", &st[i].num, &st[i].area);

		

	}
	for (int i = 0; i < maxn; i++){
		rst[i].people= 0;
		rst[i].numt = 0;
		rst[i].areat = 0;
		rst[i].flag = 0;
	}
	for (int i = 0; i < n; i++){
		int idx = findfa(st[i].id);
		rst[idx].id = idx;
		rst[idx].numt += st[i].num;
		rst[idx].areat += st[i].area;
		rst[idx].flag = 1;
		//printf("rst %d %d %d %d\n", idx, rst[idx].numt, rst[idx].areat, rst[idx].flag);
	}
	int cnt = 0;
	for (int i = 0; i < maxn; i++){
		if (exist[i] == 1){
			rst[findfa(i)].people++;
		}
			if (rst[i].flag == 1){
				cnt++;
			}
		
	}
	cout << cnt << endl;
	for (int i = 0; i < maxn; i++){
		if (rst[i].flag == 1){
			rst[i].numt = (double)rst[i].numt / (double)rst[i].people;
			rst[i].areat = (double)rst[i].areat / (double)rst[i].people;
		}
	}
	sort(rst, rst + maxn, cmp1);
	for (int i = 0; i < cnt; i++){
		printf("%04d %d %.3f %.3f\n",rst[i].id,rst[i].people,rst[i].numt,rst[i].areat);
	}
	return 0;
}