typedef struct bin{
	int data;
	struct bin *left;
	struct bin *right;
}node;

node *New, *root=NULL;
int c,cnt;
char ans='n';

node *create(){
	node *temp = (node *)malloc(sizeof(node));
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void insert(node *root , node *New){
	char ch;
	printf("\nWhere to insert left/right(l/L or r/R) of %d :",root->data);
	ch=getche();
	if((ch=='r')||(ch=='R')){
		if(root->right==NULL)
			root->right=New;
		else
			insert(root->right,New);
	}
	else{
		if(root->left==NULL)
			root->left=New;
		else
			insert(root->left,New);
	}
}

void inorder(node *temp){
	if(temp!=NULL){
		inorder(temp->left);
		printf("  %d",temp->data);
		inorder(temp->right);
	}
}

void preorder(node *temp){
	if(temp!=NULL){
		printf("  %d",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}

void postorder(node *temp){
	if(temp!=NULL){
		postorder(temp->left);
		postorder(temp->right);
		printf("  %d",temp->data);
	}
}

int countLeaf(node *temp, int cnt){
	static int i=0;
	if(temp!=NULL){
		if((temp->left==NULL) &&(temp->right==NULL)){
			printf("  %d",temp->data);
			i++;
			return i;
		}
		else{
			countLeaf(temp->left,i);
			countLeaf(temp->right,i);
		}
	}
}

int height(node *temp){
	if (temp==NULL) 
		return 0; 
	else{
		int lDepth = height(temp->left); 
		int rDepth = height(temp->right); 
		
		if(lDepth > rDepth) 
			return(lDepth+1); 
		else 
			return(rDepth+1); 
	} 
}

void empty(node *temp){
	if(temp==NULL)
		printf("\nTree is Empty.");
	else
		printf("\nTree is NOT Empty.");
}

int size(node* temp){   
  if (temp==NULL)  
    return 0; 
  else     
    return(size(temp->left) + 1 + size(temp->right));   
}

void level(node* temp, int l){
    if (temp == NULL) 
        return; 
    if (l == 1) 
        printf("%d ", temp->data); 
    else if (l > 1){ 
        level(temp->left, l-1); 
        level(temp->right, l-1); 
    } 
}

void levelorder(node* temp){ 
    int h = height(temp); 
    //printf("%d",h);
    int i; 
    for (i=1; i<=h; i++){ 
        level(temp, i); 
        printf("\n"); 
    } 
}  

