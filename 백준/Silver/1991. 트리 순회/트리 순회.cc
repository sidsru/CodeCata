#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <unordered_map>
using namespace std;
unordered_map<char, pair<char, char>> m;
void preorder(const char node)
{
	if (node == '.')
	{
		return;
	}
	printf("%c", node);
	preorder(m[node].first);
	preorder(m[node].second);
}
void Inorder(const char node)
{
	if (node == '.')
	{
		return;
	}
	Inorder(m[node].first);
	printf("%c", node);
	Inorder(m[node].second);
}
void postorder(const char node)
{
	if (node == '.')
	{
		return;
	}
	postorder(m[node].first);
	postorder(m[node].second);
	printf("%c", node);
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		char node, left, right;
		scanf(" %c %c %c", &node, &left, &right);
		m[node] = make_pair(left, right);
	}
	preorder('A');
	printf("\n");
	Inorder('A');
	printf("\n");
	postorder('A');

	return 0;
}
