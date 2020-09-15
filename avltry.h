#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
    int height;
};
struct node *create(int);
struct node *insert(struct node *,int);
struct node *Delete(struct node *,int);
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);
int height(struct node *);
struct node *rightrotate(struct node *);
struct node *leftrotate(struct node *);
struct node *RR(struct node *);
struct node *LL(struct node *);
struct node *LR(struct node *);
struct node *RL(struct node *);
int BF(struct node *);
struct node *create(int data){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return(newnode);		
}
struct node *insert(struct node*root,int data){	
	if(root==NULL){
		root=(struct node*)malloc(sizeof(struct node));
		root->data=data;
	root->left=NULL;
	root->right=NULL;
	}
	else{
		if(data>root->data){
		root->right=insert(root->right,data);
			if(bf(root)==-2){
				if(data>root->right->data)
				root=LL(root);
				else
				root=RL(root);
			}
		}
		else{
			if(data<root->data){
				root->left=insert(root->left,data);
				if(bf(root)==2){
					if(data <root->left->data)
					root=RR(root);
					else
					root=LR(root);
				}}	
		}
	}
	root->height = ht(root);
return(root);
}
int bf(struct node *root){
	int lh,rh;
	if(root==NULL)
	return 0;
	if(root->left==NULL)
	lh=0;
	else{
		lh=1+root->left->height;
	}
	if(root->right==NULL)
	rh=0;
	else{
		rh=1+root->right->height;
	}
	return(lh-rh);
}
struct node *LL(struct node *root){
	root =leftrotate(root);
	return(root);
}
struct node *leftrotate(struct node *x){
	struct node *y;
	y=x->right;
x->right=y->left;
	y->left=x;
	x->height=ht(x);
    y->height=ht(y);  
    return(y);	
}
struct node *RR(struct node *root){
	root=rightrotate(root);
	return(root);
}
struct node *rightrotate(struct node *x){
	struct node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->height=ht(x);
    y->height=ht(y);  
    return(y);	
}
struct node *RL(struct node *root){
	root->right=rightrotate(root->right);
	root=leftrotate(root);
	return(root);
}
struct node *LR(struct node *root){
	

root->left=leftrotate(root->left);
	root=rightrotate(root);
	return(root);
}
int ht(struct node *root){
    int lh,rh;
    if(root==NULL)
        return(0);  
    if(root->left==NULL)
        lh=0;
    else
        lh=1+root->left->height;       
    if(root->right==NULL)
        rh=0;
    else
        rh=1+root->right->height;  
    if(lh>rh)
        return(lh);
    else
    return(rh);
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
      

  printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node *root){
    if(root!=NULL)    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
void postorder(struct node *root){
	if(root!=NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}
struct node * Delete(struct node *root,int x){
    struct node *p;  
    if(root==NULL)
    {
        return NULL;
    }
else
        if(x > root->data) {
            root->right=Delete(root->right,x);
            if(bf(root)==2)
                if(bf(root->left)>=0)
                    root=LL(root);
                else
                    root=LR(root);
        }
        else
            if(x<root->data){            
                root->left=Delete(root->left,x);
                if(bf(root)==-2)    
                    if(bf(root->right)<=0)
                        root=RR(root);
                    else
                        root=RL(root);
            }
            else{
                if(root->right!=NULL) {    
                    p=root->right;                  
                    while(p->left!= NULL)
                        p=p->left;
                     root->data=p->data;
                    root->right=Delete(root->right,p->data);                   
                   

 if(bf(root)==2)
                        if(bf(root->left)>=0)
                            root=LL(root);
                        else
                            root=LR(root);
                }
                else
                    return(root->left);
            }
    root->height=ht(root);
    return(root);
}
