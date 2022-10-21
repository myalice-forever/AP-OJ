#include<iostream>
using namespace std;
int* preorder, * inorder;
int n;
int* left_visited;
int* right_visited;
int root_index = 0;
int max_len = 0;
//返回树的高度
//root_index为根节点，tree_index为上一个根节点，根据direction分别向左向右寻找子树的根节点
int height_cal(int tree_index, const char direction) {
	if (tree_index<0 || tree_index>n)//越界
		return 0;
	int i = tree_index;
	if (direction == 'L') {
		if (left_visited[tree_index])
			return 0;
		left_visited[tree_index] = 1;
		for (; i >= 0 && inorder[i] != preorder[root_index]; i--);
	}
	else if (direction == 'R') {
		if (right_visited[tree_index])
			return 0;
		right_visited[tree_index] = 1;
		for (; i < n && inorder[i] != preorder[root_index]; i++);
	}
	if ((i >= 1 && right_visited[i - 1] == 1 || i == 0) && (i < n - 1 && left_visited[i + 1] == 1 || i == n - 1)) {//左右都访问过
		left_visited[i] = 1;
		right_visited[i] = 1;
		return 0;
	}
	else if (i >= 1 && right_visited[i - 1] == 1 || i == 0) {//只有左边访问过
		left_visited[i] = 1;
		root_index++;
		int right_height = height_cal(i, 'R');
		//max_len = max(max_len, 1+right_height);
		return 1 + right_height;
	}
	else if (i < n - 1 && left_visited[i + 1] == 1|| i==n-1) {//只有右边访问过
		right_visited[i] = 1;
		root_index++;
		int left_height = height_cal(i, 'L');
		//max_len = max(max_len, 1+left_height);
		return 1 + left_height;
	}
	else {//左右两边都没访问过
		root_index++;
		int left_height = height_cal(i, 'L');
		root_index++;
		int right_height = height_cal(i, 'R');
		max_len = max(max_len, 2 + left_height + right_height);
		return 1 + max(left_height, right_height);
	}
}
int main() {
	cin >> n;
	preorder = new int[n];
	inorder = new int[n];
	left_visited = new int[n];
	right_visited = new int[n];
	for (int i = 0; i < n; i++)
		left_visited[i] = 0, right_visited[i] = 0;
	for (int i = 0; i < n; i++)
		cin >> preorder[i];
	for (int i = 0; i < n; i++)
		cin >> inorder[i];
	if (n == 1) {
		cout << 0;
		return 0;
	}
	int tree_index = 0;
	for (; inorder[tree_index] != preorder[root_index]; tree_index++);
	if (tree_index == n - 1) {
		root_index++;
		int left_height = height_cal(tree_index, 'L');
		cout << max(1 + left_height, max_len);
	}
	else if (tree_index == 0) {
		root_index++;
		int right_height = height_cal(tree_index, 'R');
		cout << max(1 + right_height, max_len);
	}
	else {
		root_index++;
		int left_height = height_cal(tree_index, 'L');
		root_index++;
		int right_height = height_cal(tree_index, 'R');
		max_len = max(max_len, 2 + left_height + right_height);
		cout << max_len;
	}
	return 0;
}