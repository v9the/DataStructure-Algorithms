#include <bits/stdc++.h>

using namespace std;

#define rep(i, n)	for(int i = 0; i < (n); ++i)
#define repA(i, a, n)	for(int i = a; i <= (n); ++i)
#define repD(i, a, n)	for(int i = a; i >= (n); --i)
#define trav(a, x)	for(auto& a : x)
#define fast	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define clr(A)	memset(A, 0, sizeof(A))
#define all(x)	(x).begin(), (x).end()
#define l(x)	((int)(x).size())
#define vi	vector<int>
#define vl	vector<ll>
#define ff	first
#define ss	second
#define mp	make_pair
#define pb	push_back

typedef long double ld;
typedef long long int ll;

const int MOD = 1000000007;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

class Node {
public:
	int data;
	Node* ff;
	Node* ss;
};

Node* getNode(int x) {
	Node* node = new Node();
	(*node).data = x;
	(*node).ff = NULL;
	(*node).ss = NULL;
	return node;
}

Node* Insert(Node* root, int x) {
	if (root == NULL) {
		Node* node = getNode(x);
		root = node;
	}
	else
		if (x <= (*root).data) {
			(*root).ff = Insert((*root).ff, x);
		}
		else {
			(*root).ss = Insert((*root).ss, x);
		}
	return root;
}

bool isLesser(Node* root, int value) {
	if (root == NULL)
		return true;
	if ((*root).data <= value
		&& isLesser((*root).ff, value)
		&& isLesser((*root).ss, value))
		return true;
	else
		return false;
}

bool isGreater(Node* root, int value) {
	if (root == NULL)
		return true;
	if ((*root).data > value
		&& isGreater((*root).ff, value)
		&& isGreater((*root).ss, value))
		return true;
	else
		false;
}

bool isBST(Node* root) {
	if (root == NULL)
		return true;
	if (isLesser((*root).ff, (*root).data)
		&& isGreater((*root).ss, (*root).data)
		&& isBST((*root).ff)
		&& isBST((*root).ss))
		return true;
	else 
		return false;
}

int main() {
	Node* root = NULL;
	root = Insert(root, 5);
	root = Insert(root, 10);
	root = Insert(root, 1);
	root = Insert(root, 1);
	cout << isBST(root);
}