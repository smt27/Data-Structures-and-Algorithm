
/*operations on threaded bst*/

#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    int lth, rth;
   
};
class BST{
    public:
        node* root=NULL;

//insert using non-recurssion    
    node* insert(node *root , int key){
        node* nn=new node();
        nn->data=key;
        //nn->left=nn->right=NULL;
        nn->lth=1;
        nn->rth=1;
        
        node* temp=root;
        node* parent=NULL;
        while (temp!=NULL)
        {
            if(key==temp->data)
            {
                cout<<"duplicate key!! ";
                return root;
                
            }
            parent=temp;
            if(key<temp->data)
            {
                if(temp->lth==0)
                    temp=temp->left;
                else
                    break;
            }
            else if(key>temp->data)
            {
                if(temp->rth==0)
                    temp=temp->right;
                else 
                    break;
            }
        }
        if(parent==NULL)   //tree is NULL or empty
        {
            //data is a root node, 
            //so its inorder predecessor and successor is itself
            root=nn;
            nn->left=NULL;
            nn->right=NULL;
        
        }
        else if(key<parent->data)       //puts data as a left child
        {
            nn->left= parent->left;     //predecessor
            nn->right=parent;       //successor
            parent->lth=0;
            parent->left=nn;
        }
        else if(key>parent->data)       //puts data as a right child
        {
            nn->left=parent;        //predecessor
            nn->right=parent->right;        //successor
            parent->rth=0;
            parent->right=nn;
        }
        return root;
    }
    
//displaying data in sorted manner(inorder)
   void inorder(node* root){
        cout<<"inorder display: ";
        if(root ==NULL)
            cout<<"the tree is empty\n";
        node *temp=root;
        while(temp->lth ==0)
            temp=temp->left;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=inordersuccessor(temp);
        }
        
    
    }
//finding the inorder successor
    node* inordersuccessor(node *temp)
    {
        if(temp->rth==1)
            return temp->right;
        else
        {
            temp=temp->right;
            while(temp->lth==0){
                temp=temp->left;
            }
            return temp;
        }
    }
    
//finding the inorder predecessor
    node* inorderpredecessor(node* temp)
    {
        if(temp->lth==1)        //its a leaf node
            return temp->left;
        else
        {
            temp=temp->left;
            while(temp->rth==0)
                temp=temp->right;
            return temp;
        }
    }
    
// Here 'par' is pointer to parent Node and 'ptr' is  pointer to current Node.
    struct node* caseA(struct node* root, struct node* par,
                       struct node* ptr)
    {
        // If Node to be deleted is root
        if (par == NULL)
            root = NULL;
     
        // If Node to be deleted is left of its parent
        else if (ptr == par->left) {
            par->lth= 1;
            par->left = ptr->left;
        }
        else {
            par->rth = 1;
            par->right = ptr->right;
        }
     
        // Free memory and return new root
        free(ptr);
        return root;
    }
 
// Here 'par' is pointer to parent Node and 'ptr' is pointer to current Node.
    struct node* caseB(struct node* root, struct node* par,
                       struct node* ptr)
    {
        struct node* child;
     
        // Initialize child Node to be deleted has
        // left child.
        if (ptr->lth == 0)
            child = ptr->left;
     
        // Node to be deleted has right child.
        else
            child = ptr->right;
     
        // Node to be deleted is root Node.
        if (par == NULL)
            root = child;
     
        // Node is left child of its parent.
        else if (ptr == par->left)
            par->left = child;
        else
            par->right = child;
     
        // Find successor and predecessor
        node* s = inordersuccessor(ptr);
        node* p = inorderpredecessor(ptr);
     
        // If ptr has left subtree.
        if (ptr->lth == 0)
            p->right = s;
     
        // If ptr has right subtree.
        else {
            if (ptr->rth== 0)
                s->left = p;
        }
     
        free(ptr);
        return root;
    }
 
// Here 'par' is pointer to parent Node and 'ptr' is
// pointer to current Node.
    struct node* caseC(struct node* root, struct node* par,
                       struct node* ptr)
    {
        // Find inorder successor and its parent.
        struct node* parsucc = ptr;
        struct node* succ = ptr->right;
     
        // Find leftmost child of successor
        while (succ->lth==0) {
            parsucc = succ;
            succ = succ->left;
        }
     
        ptr->data = succ->data;
     
        if (succ->lth == 1 && succ->rth == 1)
            root = caseA(root, parsucc, succ);
        else
            root = caseB(root, parsucc, succ);
     
        return root;
    }
 
// Deletes a key from threaded BST with given root and
// returns new root of BST.
    struct node* delThreadedBST(struct node* root, int dkey)
    {
        // Initialize parent as NULL and ptrent
        // Node as root.
        struct node *par = NULL, *ptr = root;
     
        // Set true if key is found
        int found = 0;
     
        // Search key in BST : find Node and its
        // parent.
        while (ptr != NULL) {
            if (dkey == ptr->data) {
                found = 1;
                break;
            }
            par = ptr;
            if (dkey < ptr->data) {
                if (ptr->lth == 0)
                    ptr = ptr->left;
                else
                    break;
            }
            else {
                if (ptr->rth == 0)
                    ptr = ptr->right;
                else
                    break;
            }
        }
     
        if (found == 0)
            printf("dkey not present in tree\n");
     
        // Two Children
        else if (ptr->lth == 0 && ptr->rth== 0)
            root = caseC(root, par, ptr);
     
        // Only Left Child
        else if (ptr->lth == 0)
            root = caseB(root, par, ptr);
     
        // Only Right Child
        else if (ptr->rth == 0)
            root = caseB(root, par, ptr);
     
        // No child
        else
            root = caseA(root, par, ptr);
     
        return root;
    }
    
    
    


};

int main(){
    BST b;
    b.root=b.insert(b.root,6);
    b.insert(b.root,3);
    b.insert(b.root,5);
    b.insert(b.root,10);
    b.insert(b.root,9);
    b.insert(b.root,13);
    b.insert(b.root,4);
    b.inorder(b.root);
    b.delThreadedBST(b.root,5);  // deletion of node having 1 child
    b.delThreadedBST(b.root,10);  //node with 2 Children
    b.delThreadedBST(b.root, 13); // leaf node deletion
    cout<<"\nafter deleting a node\n";
    b.inorder(b.root);
    return 0;
}



