#include <bits/stdc++.h>
//halo
using namespace std;
using ll = long long ;

struct node{
    int val;
    node *left;
    node *right;
    node(int x){
        val = x;
        left = right = NULL;
    }
};

void makeRoot(node *root, int u, int v, char c){
    if(c == 'L'){
        root->left = new node(v);
    }
    else{
        root->right = new node(v);
    }
}

void insertNode(node *root, int u, int v, char c){ // tao ra mot canh
    if(root == NULL){
        return;
    }
    if(root->val == u){
        makeRoot(root, u, v, c);
    }
    else{
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}

void inorder(node *root){// Duyệt giữa
    if(root != NULL){
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}
int res = 0;
void preorder(node *root, int cnt){// Duyệt trước
    if(root != NULL){
        cout << root->val << " ";
        preorder(root->left, cnt + 1);
        preorder(root->right, cnt + 1);
        res = max(res, cnt);
    }
    
}

void posorder(node *root){
    if(root != NULL){
        posorder(root->left);
        posorder(root->right);
        cout << root->val << " ";
    }

}

void BFS(node *root){ // Duyệt theo cấp
    queue<node *> Q;
    Q.push(root);
    while(!Q.empty()){
        node *x = Q.front(); Q.pop();
        cout << x->val <<" ";
        if(x->left != NULL){
            Q.push(x->left);
        }
        if(x->right != NULL){
            Q.push(x->right);
        }
    }
}

void spiralOrdeer(node *root){
    stack<node*> s1, s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            node *x = s1.top(); s1.pop();
            cout << x->val <<" ";
            if(x->right != NULL){
                s2.push(x->right);
            }
            if(x->left != NULL){
                s2.push(x->left);
            }
        }
        while(!s2.empty()){
            node *x = s2.top(); s2.pop();
            cout << x->val <<" ";
            if(x->left != NULL){
                s1.push(x->left);
            }
            if(x->right != NULL){
                s1.push(x->right);
            }
            
        }
    }
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);  
    node *root = NULL;
    int n; cin >> n;
    for(int i = 1; i <= n; i ++){
        int u, v; char c; cin >> u >> v >> c;
        if(root == NULL){
            root = new node(u);
            makeRoot(root, u, v, c);
        }
        else{
            insertNode(root, u, v, c);
        }
    }
    preorder(root, 0);
    cout << res;



    return 0;
}
