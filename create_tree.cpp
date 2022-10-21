#include<iostream>
using namespace std;
int* preorder, * inorder;
int ans = 0;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode():val(0),left(nullptr),right(nullptr){}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
TreeNode* mybuildtree(int pre_left, int pre_right, int in_left, int in_right) {
	if (pre_left > pre_right) {
		return nullptr;
	}
	int root =preorder[pre_left];
	int root_index = in_left;
	for (; inorder[root_index] != root; root_index++);
	TreeNode* root_node = new TreeNode(inorder[root_index]);
	int left_len = root_index - in_left;
	//left subtree
	root_node->left = mybuildtree(pre_left + 1, pre_left + left_len, in_left, root_index - 1);
	//right subtree
	root_node->right = mybuildtree(pre_left + 1 + left_len, pre_right, root_index + 1, in_right);
	return root_node;
}
int get_distance(TreeNode* root) {
	if (!root)
		return 0;
	int lefth = get_distance(root->left);
	int righth = get_distance(root->right);
	ans=max(ans,max(lefth,righth));
	return max(lefth,righth) + 1;
}
int main() {
	int n = 0;
	cin >> n;
	preorder = new int[n];
	inorder = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> preorder[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
	}
	TreeNode* tree = mybuildtree(0, n - 1, 0, n - 1);
	cout<<get_distance(tree);
	cout << ans;
	return 0;
}