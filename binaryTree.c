#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>
#include"binaryTree.h"

int main(){
	printf("\n1.  Create Tree\n2.  Insert\n3.  Is Empty\n4.  Size (No. of Nodes)\n5.  Count Leaves\n6.  Height\n7.  Level Order Traversal\n8.  Preorder Traversal\n9.  Postorder Traversal\n10. Inorder Traversal\n11. Exit");
	int i,n;
	do{
		printf("\n\nEnter the Choice:");
		scanf("%d",&c);
		switch(c){
			case 1:
				New=create();
				if(root==NULL)
					root=NULL;
				printf("Empty Tree is created.");				
				break;
			case 2:root=NULL;
			printf("Enter the no. of elements:");
			scanf("%d",&n);
			for(i=0;i<n;i++){
					New=create();
					printf("\nEnter the Element:");
					scanf("%d",&New->data);
					if(root==NULL)
						root=New;
					else
						insert(root,New);
					}
					//printf("\nDo you Want to Enter More elements?(y/n):");
				break;
			case 3:
				empty(root);
				break;
			case 4:
				printf("\nNo. of Nodes :%d",size(root));
				break;
			case 5:
				cnt=0;
				printf("\nThe leaves in Tree are:");
				cnt=countLeaf(root,cnt);
				printf("\nThe Total Number of leaf Nodes are:%d",cnt);
				break;
			case 6:
				printf("\nHeight of Tree :%d",height(root)-1);
				break;
			case 7:
				printf("\nLevel Order Traversal:\n");
				levelorder(root);
				break;
			case 8:
				printf("\nPreorder Traversal:");
				preorder(root);
				break;
			case 9:
				printf("\nPostorder Traversal:");
				postorder(root);
				break;
			case 10:
				printf("\nInorder Traversal:");
				inorder(root);
				break;
			case 11:
				exit(0);
				break;
			default :
				printf("\nEnter Choice from 1-11");
		}
	}while(c!=11);
return 0;
}
