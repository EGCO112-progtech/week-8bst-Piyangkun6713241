// An integer binary search tree

struct TreeNode {                                           
    struct TreeNode *leftPtr; // pointer to left subtree
   int data; // node value                               
    struct TreeNode *rightPtr; // pointer to right subtree
}; // end structure treeNode 
        
typedef struct TreeNode * TreeNodePtr; // synonym for TreeNode*
                    
typedef struct {
	int size;
	TreeNodePtr root;
}BST;

// prototypes

void insertNode( BST *, int );

/*void insertNode_R(TreeNodePtr * t,int value){
  if(t==NULL){
   t= new TreeNodePtr;
	 if(t){
		t -> leftPtr=NULL;
		t -> rightPtr=NULL;
		t -> data=value;
   }
  }
  else{
     if(t->data>=value) //left
      t = t -> leftPtr;
     else //right
      t = t -> rightPtr;
   }
}*/

void insertNode( BST *b, int value ){
	 TreeNodePtr t =b->root,new_node;
	 int inserted=0;
	new_node =(TreeNodePtr) malloc(sizeof(struct TreeNode));
	if(new_node){
		new_node->leftPtr=NULL;
		new_node->rightPtr=NULL;
		new_node->data=value;
		/*First Node*/
		if(!b->root)	b->root=new_node;
		else {
         while(!inserted){
            if(t->data >=value){
               /* move/insert to the left*/
               if(t->leftPtr){ 
                  t=t->leftPtr;
                  continue;
               }
               t -> leftPtr=new_node;
               inserted=1;
            }
  	 
  
            else{
	            /* move/ insert to the right*/
               if(t->rightPtr){
                  t = t->rightPtr;
                  continue;
               }
               t -> rightPtr=new_node;
               inserted=1;
            }
         }//end while		
        
         b->size++;
      }//end else;
  }
  
}//end function

void preOrder(TreeNodePtr treePtr){
   if(treePtr != NULL){
      printf("%3d", treePtr->data);
      
      preOrder( treePtr->leftPtr);

      preOrder( treePtr->rightPtr);
   }
}

void inOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        
        
      inOrder( treePtr->leftPtr ); //Recursion to the left
 
      printf("%3d",treePtr->data) ;  //print the value 
   
      inOrder( treePtr->rightPtr ); //Recursion to the right
   } // end if                          
} // end 

void postOrder(TreeNodePtr treePtr){
   if ( treePtr != NULL ){
      
   postOrder( treePtr->leftPtr);

   postOrder( treePtr->rightPtr);

   printf("%3d", treePtr->data);
   }
}

int n = 0;

void printTree(TreeNodePtr treePtr){
   if ( treePtr != NULL ){

   n++;

   printTree( treePtr->rightPtr);

   for(int i = 0; i<n-1; i++) printf("    ");

   printf("%3d\n", treePtr->data);

   printTree( treePtr->leftPtr);

   n--;
   }
}