
/* operations on binary search tree*/
#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
};
class BST{
    public:
        node* root=NULL;
        
        node* insertr(node* root , int key){
        node* nn=new node();
            nn->data=key;
            nn->left=NULL;
            nn->right=NULL;
        if(root==NULL){
            root=nn;
            return nn;
        }
        else if(key<root->data){
            root->left=insertr(root->left,key);
        }
        else if(key>root->data){
            root->right=insertr(root->right,key);
        }
        
    }
    
    node* insertnr(node* root, int key){
        node* nn=new node();
        nn->data=key;
        nn->left=nn->right=NULL;
        
        node* temp=root;
        node* parent=NULL;
        while (temp!=NULL){
            parent=temp;
            if(key<temp->data)
                temp=temp->left;
            if(key>temp->data)
                temp=temp->right;
        }
        if(parent==NULL){
            parent=nn;
        }
        if(key<parent->data){
            parent->left=nn;
        }
        if(key>parent->data){
            parent->right=nn;
        }
        return parent;
    }
    void inorder(node* r){
        if(r==NULL)
            return;
        inorder(r->left);
        cout<<r->data<<" ";
        inorder(r->right);
    }
    node* search(node* root, int key){
        node* temp =root;
        while(temp!=NULL){
            if(key== temp->data)
                return temp;
            else if(key<temp->data)
                temp=temp->left;
            else if(key>temp->data)
                temp= temp->right;
        }
        return NULL;
    }
    int findmin(node* root){
        node* temp =root;
        if(root->left==NULL)
            return root->data;
        else
            return findmin(root->left);
    }
};

int main(){
    BST b;
    b.root=b.insertr(b.root,10);
    b.insertr(b.root,20);
    b.insertnr(b.root,95);
    b.insertr(b.root,4);
    cout<<"the minimum element in the tree is: "<<b.findmin(b.root);
    cout<<"\n";
    node* found;
    b.search(b.root,600);
    if(found != NULL)
        cout<<"data found\n";
    else
        cout<<"data not found\n";
     b.inorder(b.root);
    return 0;
}


