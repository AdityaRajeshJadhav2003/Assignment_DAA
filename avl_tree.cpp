#include<bits/stdc++.h>
using namespace std;

struct node{
        int data;
        struct node* right;
        struct node* left;
};

struct node* newnode(int val){
    struct node* root = new node();
    root -> data = val;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void preorder(struct node* root){
    if(!root) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int height(struct node* root){
    if(!root) return 0;
    int lr = height(root->left);
    int rr = height(root->right);

    return max(lr,rr) + 1;
}

bool isAVL(struct node* root){
    if(!root) return true;

    if(isAVL(root->left) == false){
        return false;
    }

    if(isAVL(root->right) == false){
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);

    return (abs(lh - rh) <= 1);
}
int main(){
    struct node* root = newnode(1);
    root -> left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    root->right->right->left = newnode(8);
   // root->right->right>left->left = NULL;
    root->right->right->left->right = newnode(9);
    cout<<endl;

    //          1
    //       /     \
    //      2        3
    //    /   \    /   \
    //   4     5   6    7
    //                 /
    //                8
    //                  \
    //                    9
    preorder(root);
    cout<<endl<<endl;

    int hite = height(root);
    cout<<hite<<endl;

    if(isAVL(root)) cout<<"Tree is AVL."<<endl;
    else cout<<"Tree is not AVL."<<endl;

}