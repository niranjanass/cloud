#include<stdio.h>
#include"avltry.h"
int main(){
struct node *root=NULL;
int x,n,i,ch;
int e,ele;
do
{
printf("\n1)Create \n2)Insert \n3)Print \n4)Delete \n5)Quit");
printf("\n\nEnter Your Choice:");
scanf("%d",&ch);
switch(ch) {
case 1:
printf("enter element to insert:");
scanf("%d",&e);
root=create(e);
printf("tree created successfully");
break;
case 2:
printf("enter element to insert:");
scanf("%d",&ele);
if(root==NULL){
		printf("error...create the tree to insert!!!");
	}
else{
root=insert(root,ele);
}
break;
case 3:
printf("\nPreorder sequence:\n");
preorder(root);
printf("\n\nInorder sequence:\n");
inorder(root);
printf("\n\nPostorder sequence:\n");
postorder(root);
printf("\n");
break;
case 4:
printf("\nEnter a data:");
scanf("%d",&x);
root=Delete(root,x);
break;
}
}while(ch!=5);
}



