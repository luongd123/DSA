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




//////////////////////////////////DUYỆT///////////////////////////////////////


void inorder(node *root){// Duyệt giữa
    if(root != NULL){
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}
int res = 0;
void preorder(node *root){// Duyệt trước
    if(root != NULL){
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
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
    
}






/////////////////////////////////DUYỆT////////////////////////////////////







bool search(node *root, int key){// tim kiem
    if(root == NULL){
        return false;
    }
    if(root->val == key){
        return true;
    }
    else if(key < root->val){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}

node *makeNode(int x){
    node *newNode = new node(x);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node *minNode(node *root){
    node *tmp = root;
    while(tmp != NULL && tmp->left != NULL){
        tmp = tmp->left;
    }
    return tmp;
}

node *insertBinary(node *root, int key){
    if(root == NULL){
        return makeNode(key);
    }
    if(key < root->val){
        root->left = insertBinary(root->left, key);
    }
    else if(key > root->val){
        root->right = insertBinary(root->right, key);
    }
}

node *deleteBinary(node *root, int key){
    if(root == NULL){
        return root;
    }
    if(key < root->val){
        root->left = deleteBinary(root->left, key);
    }
    else if(key > root->val){
        root->right = deleteBinary(root->right, key);
    }
    else{
        if(root->left == NULL){
            node *tmp = root->right;
            delete root;
            return tmp;
        }
        else if(root->right == NULL){
            node *tmp = root->right;
            delete root;
            return tmp;
        }
        else{
            node *tmp = minNode(root->right);
            root->val = tmp->val;
            root->right = deleteBinary(root->right, tmp->val);
        }
    }
    return root;
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
        int u; cin >> u;
        root = insertBinary(root, u);
    }

    BFS(root);
    cout << endl << search(root, 12);
    root = deleteBinary(root, 1);
    cout << endl << search(root, 1);
    



    return 0;
}