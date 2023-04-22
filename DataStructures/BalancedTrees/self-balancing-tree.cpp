/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */
int hight(node *n){
    if (n!=NULL)
        return n->ht;
    else return -1;
}
void ht_update(node *n){
    n->ht=max(hight(n->left),hight(n->right))+1;
}

node * L(node * a){
    node * b= a->right;
    node * nr= b->left;
    b->left=a;
    a->right=nr;
    ht_update(a);
    ht_update(b);
    return b;
}
node * R (node * a){
    node * b= a->left;
    node * nl= b->right;
    b->right=a;
    a->left=nl;
    ht_update(a);
    ht_update(b);
    return b;
}

node * insert(node * root,int val){
    if (root==NULL){
        node * nowy= new node;
        nowy->ht=0;
        nowy->right=NULL;
        nowy->left=NULL;
        nowy->val=val;
        return nowy;
    }
    if(root->val > val)
        root->left=insert(root->left, val);
    else if(root->val < val)
        root->right=insert(root->right, val);
    
    ht_update(root);
    int  bal=0;
    if (root!=NULL)
        bal=hight(root->left)-hight(root->right);
    
    if (bal<-1){
        if (val < root -> right -> val)
            root->right = R(root->right);
        return L(root);
    }
    else if (bal>1){
        if (val > root -> left -> val)
            root->left = L(root->left);
        return R(root);
    }
    return root;
}