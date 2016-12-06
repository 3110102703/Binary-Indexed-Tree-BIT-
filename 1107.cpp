#include<iostream>
#include<algorithm>
#include<vector>
#define maxn 10010
using namespace std;
int father[maxn], course[maxn],root[maxn];
int findfather(int x){
	int a = x;
	while (father[x] != x){
		x = father[x];
	}
	while (a != father[a]){
		int z = a;
		a=father[a];
		father[z] = x;
	}
	return x;
}
void unionf(int a,int b){
	int fa = findfather(a);
	int fb = findfather(b);
	if (fa != fb){
		father[fa] = fb;
	}
}
int main(){ 
	int n,k,t; cin >> n;
	for (int i = 1; i <= n; i++){
		father[i] = i;
	}
	for (int i = 1; i <= n; i++){
		scanf("%d:", &k);
		for (int j = 0; j < k; j++){
			scanf(" %d", &t);
			if (course[t] == 0){
				course[t] = i;
			}
			unionf(i, findfather(course[t]));
		}
	}
	for (int i = 1; i <= n; i++){
		root[findfather(i)]++;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		if (root[i] != 0){
			cnt++;
		}
	}
	printf("%d\n", cnt);
	sort(root + 1, root + n + 1); reverse(root + 1, root + n + 1);
	for (int i = 1; i <= cnt; i++){
		printf("%d", root[i]);
		if (i != cnt){ printf(" "); }
	}
	return 0; 
}