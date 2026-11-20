#include <bits/stdc++.h>
#define inp "test"
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define foru(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, a, b) for (int i = a; i >= ; --i)

using namespace std;

const ll oo = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
const int maxn = 1e3 + 10;

void fio(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void read(){
    if (fopen(inp".inp", "r")){
        freopen(inp".inp", "r", stdin);
        freopen(inp".out", "w", stdout);
    }
}

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int val){
    return new Node{val, nullptr, nullptr};
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node* ins(Node* root, int val){
    if (root == nullptr) return createNode(val);
    if (val < root->data) root->left = ins(root->left, val);
    else if (val > root->data) root->right = ins(root->right, val);
    return root;
}

int n;
Node* root;

void sol(){
    cin >> n;
    foru(i, 1, n){
        int x;
        cin >> x;
        root = ins(root, x);
    }
}

signed main(){
    fio();
    read();
    int test;
    cin >> test;
    foru(i, 1, test){
        root = nullptr;
        sol();
        cout << "Test #" << i << ": ";
        postorder(root);
        cout << "\n";
    }
    return 0;
}   
