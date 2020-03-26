#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
#include <bitset>
#include <set>
#include <map>
using namespace std;
#define inf 2000000000
#define mod 1000000007
// 루드트리
class List{
public:
	List* parent;			// 부도노드
	List* left;				// 왼쪽 자식노드
	List* right;			// 오른쪽 자식노드
	int key;				// 키값
	bool L;					// 나는 왼쪽자식노드이다.
	bool R;					// 나는 오른쪽자식노드이다.

	List();
};

List* head = NULL, *root = NULL;
int cnt = 0;
List::List()
	:parent(NULL), left(NULL), right(NULL), L(false), R(false){

}

void Binary_Insert_node(int n)
{
	List* L = new List;
	L->key = n;

	if (root == NULL){
		root = L;
		head = L;
		cnt = 0;
		return;
	}
	head = root;
	while (head != NULL){
		if (head->key > L->key){
			L->parent = head;
			head = head->left;
			L->L = true;
			L->R = false;
			cnt++;
		}
		else{
			L->parent = head;
			head = head->right;
			L->L = false;
			L->R = true;
			cnt++;
		}
	}
	head = L;
	if (L->L) L->parent->left = L;
	else if (L->R) L->parent->right = L;
}

void preorder(List* temp){
	if(temp == NULL) return;
	preorder(temp->left);
	preorder(temp->right);
	cout << temp->key << '\n';
}

int main()
{
	int n;
	while(cin >> n){ Binary_Insert_node(n);}
	preorder(root);
}
