#include<iostream>
#include<vector>
using namespace std;
struct node{
	int val;
	node* left;
	node* right;
};
node* build(node* root,int t){
	if (root == NULL){
		root = new node();
		root->val = t;
		root->left = NULL;
		root->right = NULL;
	}
	else{
		if (t <= root->val){
			root->left=build(root->left, t);
		}
		else{
			root->right=build(root->right, t);
		}
	}
	return root;
}
int depth[1001] = { 0 }, maxdepth = -1;
void dfs(node* root, int tdepth){
	if (root == NULL){ 
		if (tdepth > maxdepth){
			maxdepth = tdepth;
		}
		return; 
	}
	depth[tdepth]++;
	dfs(root->left, tdepth + 1);
	dfs(root->right, tdepth + 1);
}
int main(){
	int n; cin >> n;
	node * root = NULL;
	int t;
	for (int i = 0; i < n; i++){
		scanf("%d", &t);
		root=build(root,t);
	}
	dfs(root, 0);
	
	printf("%d + %d = %d", depth[maxdepth - 1], depth[maxdepth-2], depth[maxdepth - 1] + depth[maxdepth-2]);
	return 0;
}