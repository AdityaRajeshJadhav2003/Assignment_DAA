#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    struct node* left;
    struct node* right;
};

struct node* newnode(int data){
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->val = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void bfs_trees(struct node* root){
    queue<struct node*> q;
    q.push(root);
    while(!q.empty()){
        struct node* front = q.front();
        cout<< front->val <<" ";
        q.pop();

        if(front->left){
            q.push(front->left);
        }
        if(front->right){
            q.push(front->right);
        }
    }
    
    return;
}
void dfs_inorder(struct node* root){
    //time complexity = O(n)
    //base case 
    if(root == NULL) return;
    
    //recursive way
    dfs_inorder(root->left);
    cout<<root->val<<" ";
    dfs_inorder(root -> right);
}
void dfs_preorder(struct node* root){
    //time complexity = O(n)
    //base case 
    if(root == NULL) return;
    
    //recursive way
    
    cout<<root->val<<" ";
    dfs_preorder(root->left);
    dfs_preorder(root -> right);
}
void dfs_postorder(struct node* root){
    //time complexity = O(n)
    //base case 
    if(root == NULL) return;
    
    //recursive way
    dfs_postorder(root->left);
    dfs_postorder(root -> right);
    cout<<root->val<<" ";
}
int main(){
    struct node* root = newnode(2);
    root->left = newnode(3);
    root->right = newnode(4);
    root->left->left = newnode(5);
    root->left->right = newnode(6);
    root->right->left = newnode(7);
    root->right->right = newnode(8);
    cout<<"The breadth first search approach is : ";
    bfs_trees(root);
    cout<<endl;
    cout<<"Preorder Traversal is : ";
    dfs_preorder(root);
    cout<<endl;
    cout<<"Inorder Traversal is : ";
    dfs_inorder(root);
    cout<<endl;
    cout<<"Postorder Traversal is : ";  
    dfs_postorder(root);
    cout<<endl;
    return 0;
}