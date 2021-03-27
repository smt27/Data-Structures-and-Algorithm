
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
//insert using recurssion
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
//insert using non-recurssion    
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
//displaying data in sorted manner(inorder)
    void inorder(node* r){
        if(r==NULL)
            return;
        inorder(r->left);
        cout<<r->data<<" ";
        inorder(r->right);
    }
//searching a particular node
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
//finding minnimum value/data in the given tree 
    int findmin(node* root){
        node* temp =root;
        if(root->left==NULL)
            return root->data;
        else
            return findmin(root->left);
    }
// finding the longest path
    int longestpathcount(node* r){
        if(r==NULL)
            return 0;
        else if(longestpathcount(r->left)>=longestpathcount(r->right))
            return (1+longestpathcount(r->left));
        return(1+ longestpathcount(r->right));
    }
//mirroring of BST
    void mirror(node *r){
        node *temp=NULL;
        if(r!=NULL){
            mirror(r->left);
            mirror(r->right);
            temp=r->left;
            r->left=r->right;
            r->right=temp;
        }
    }
//deletion of node 
    void delete_node(node *r, int key){
        node *parent=NULL;
        node *temp=root;
        //search for a given node
        while(temp!=NULL && temp->data!=key){
            parent=temp;
            if(key<temp->data)
                temp=temp->left;
            else if(key>temp->data)
                temp=temp->right;
            
        }
        //if node do not exist
        if(temp==NULL){
            cout<<"key not found\n";
            //return;
        }
        else
        {
            //case1: leaf node deletion
            if(temp->left==NULL && temp->right==NULL)
            {
                if (temp==r)
                    root=NULL;
                else if(temp==parent->left){
                    parent->left=NULL;}
                else 
                    parent->right=NULL;
                delete(temp);
            }
            //case2:node with one child
            else if(temp->left!=NULL && temp->right==NULL)
            {
                if(temp==parent->left)
                    parent->left=temp->left;
                else
                    parent->right=temp->right;
                delete(temp);
            }
            else if(temp->left ==NULL && temp->right!=NULL)
            {
                if(temp==parent->left)
                    parent->left=temp->right;
                else
                    parent->right=temp->right;
                delete(temp);
            }
            //case3:node having 2 children
            else if(temp->left!=NULL && temp->right!= NULL)
            {
                node* in_succ=temp->right;
                while(in_succ->left!=NULL)
                    in_succ=in_succ->left;
                int val= in_succ->data;
                delete_node(this->root,in_succ->data);
                temp->data=val;         //updating the value
            }
        }
        
    }
};

int main(){
    BST b;
    //recurssion insertion
    b.root=b.insertr(b.root,10);
    b.insertr(b.root,20);
    b.insertr(b.root,95);
    b.insertr(b.root,4);
    
    //non-recurssion insertion
    b.insertnr(b.root,40);
    b.insertnr(b.root,55);
    b.insertnr(b.root,68);
    
    //finding minimum value element in the tree
    cout<<"the minimum element in the tree is: "<<b.findmin(b.root);
    cout<<"\n";
    
    //searching a node using value
    node* found=b.search(b.root,600);
    if(found != NULL)
        cout<<"data found\n";
    else
        cout<<"data not found\n";
        
     b.inorder(b.root);
     cout<<"the longest path count is:";
     b.longestpathcount(b.root);
     
     //mirroring the tree
     b.mirror(b.root);
     cout<<"\nafter mirroring the tree is: ";
     b.inorder(b.root);
     b.mirror(b.root);
     
     //deletion of node
     b.delete_node(b.root,95);
     b.inorder(b.root);
     
     
    return 0;
}


