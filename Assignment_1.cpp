
#include"iostream"
#include<stdlib.h>
using namespace std;


class stack;
class bst_node
{
   public:
           int data;
           bst_node *left,*right;


           bst_node()
            { 
                data=0;
         
                left=NULL;
                right=NULL;
                 
            }
   
   
 }; 

class bst
{
  bst_node* bst_root;
  public:
            bst()
             {
                 bst_root=NULL;
             }
            void create();
            void create(bst_node*,int,int);
            void in_order();
            void pre_order();
            void post_order();
            void in_order(bst_node*);
            void post_order(bst_node*);
            void pre_order(bst_node*);
            void in_order_nonr();
            void insert();
            void insert(int);
            void get_min_val();
            void search_val();
            void search_val(bst_node*,int);
            void bst_mirror();
            void bst_mirror(bst_node*);
            int height();
            int height (bst_node*);
            

};
class stack
 {  
   public:
      bst_node *st[10];
      int top;
       stack()
        {
          top=-1;
        } 
    void push(bst_node*);
    bst_node* pop();
    int empty();
};

void stack::push(bst_node* v)
{
  
  if(top!=10)
   {
    st[++top]=v;
   }
   else 
     cout<<"Stack overflow\n";
}

bst_node* stack::pop()
 {
   if(top!=-1) 
    return st[top--];
  
 }

int stack::empty()
{
   if(top==-1)
       return 1; 
   else 
        return 0;
}

void bst::insert(int val)
{
   
          int flag=0;
          bst_node *cur_ptr=NULL,*temp=NULL;
                              
                                       cur_ptr=bst_root;
                                       while(cur_ptr!=NULL)
                                       {
                                         temp=cur_ptr;
                                         if(cur_ptr->data > val) {  //go to left subtree
                                             cur_ptr=cur_ptr->left;
                                             flag=1;
                                         }
                                         else if(cur_ptr->data < val) {  //go to right subtree
                                             cur_ptr=cur_ptr->right;
                                             flag=2;
                                         }
                                         else {
                                             cout<<"Data Already Present..!!";
                                             flag=0;
                                             break;
                                         }
				       } 
                                       
                                         if(flag!=0)
                                         {
                                            if(flag==1) {
                                              temp->left = new bst_node();
                                              temp->left->data =val;                                      
                                              cout<<"\nData "<<val<<" inserted as left child of : "<<temp->data<<endl;
                                            }
                                            else if(flag==2) { 
                                               temp->right = new bst_node();
                                               temp->right->data =val;           
                                               cout<<"\nData "<<val<<" inserted as right child of : "<<temp->data<<endl; 
                                            }
                                         }
}

void bst::insert()
{
     int Val;
     cout<<"\n Please Enter value you want to insert : ";
     cin>>Val;
      
     insert(Val);
     cout<<"\n inorder traversal  : ";
     in_order();
}

void bst::create()
{
          char cont1='y';
          int val;
          bst_node *cur_ptr=NULL,*temp=NULL;
          cout<<"\nTo go for creation of BST press y : ";
          cin>>cont1;
           if(cont1!='y'&&cont1!='Y')
                 return;
           else
                               do
                                 {
                                    
                                    cout<<"\nEnter value you want to add :";
                                    cin>>val; 
                                   
                                    if(bst_root==NULL)
                                    {
                                      cur_ptr= bst_root=new bst_node;
                                    
                                      cur_ptr->data=val;
                                     }
                                    else
                                     { 
                                         insert(val); 
                                     }
                                     cout<<"\nTo add more values press y:";
                                     cin>>cont1;
                                  }while(cont1=='y'||cont1=='Y');

}

void bst::pre_order()
{
   if(bst_root==NULL)
         cout<<"\nTree is Empty..!";
   else
         pre_order(bst_root);
}

void bst::in_order()
{
   if(bst_root==NULL)
         cout<<"\nTree is Empty..!";
   else  
         in_order(bst_root);
}

void bst::in_order_nonr()
{
   if(bst_root==NULL) {

         cout<<"\nTree is Empty..!";
         return;
   }
   
   stack s;
   bst_node* cur_ptr=bst_root;
     for(;;)
      {
          while(cur_ptr!=NULL)
            {
                  s.push(cur_ptr);
                  cur_ptr = cur_ptr->left;
            }
         if(!s.empty())
            {
                 cur_ptr = s.pop();
                 cout<<cur_ptr->data<<"\t";
                 cur_ptr = cur_ptr->right;
            }
         else
                  break;
    
      }

}

void bst::post_order()
{
   if(bst_root==NULL)
         cout<<"\nTree is Empty..!";
   else
          post_order(bst_root);
}


void bst::pre_order(bst_node *ptr) 
{
    
   if(ptr!=NULL)
    {
         
         cout<<ptr->data<<"\t";
         pre_order(ptr->left);
         pre_order(ptr->right);
    }
}

void bst::in_order(bst_node *ptr) 
{
    
   if(ptr!=NULL)
    {
         in_order( ptr->left);
         cout<<ptr->data<<"\t";
         in_order(ptr->right);
    }
}

void bst::post_order(bst_node *ptr) 
{
    
   if(ptr!=NULL)
    {
         post_order(ptr->left);
         post_order(ptr->right);
         cout<<ptr->data<<"\t";
    }
}

void bst::get_min_val()
{
       bst_node *ptr=bst_root;
       if(ptr==NULL)
   
             cout<<"\nTree is empty..!";
       else
       {
    		while(ptr->left!=NULL)
        	     ptr=ptr->left;
       		cout<<"\nMinimum Value :"<<ptr->data;
       }
}

void bst::search_val()
{
       int val;
       cout<<"\n Enter value to be searched :";
       cin>>val;
       search_val(bst_root,val);
}

void bst::search_val(bst_node *ptr,int val)
{
        if(ptr!=NULL)
           {
                 if(ptr->data >val)
                    search_val(ptr->left,val);
                 else if(ptr->data<val)
                    search_val(ptr->right,val);
                 else
                    cout<<"\nData "<< val <<" Found ";
           }
        else
                  cout<<"Data "<< val<<" not Found";
}


void bst::bst_mirror()
{
  bst_mirror(bst_root);   
}

void bst::bst_mirror(bst_node *ptr)
{
     bst_node *temp=NULL;
   if(ptr!=NULL) {
     if(ptr!=NULL&&(ptr->left!=NULL||ptr->right!=NULL))
        {
                temp=ptr->right;
                ptr->right=ptr->left;
                ptr->left=temp;
         }
      if(ptr->left!=NULL)
              bst_mirror(ptr->left);
      if(ptr->right!=NULL)
              bst_mirror(ptr->right);
   }
  else
     cout<<"Tree is empty..";
}

int bst::height()
{
  return height(bst_root);
}


int bst:: height (bst_node* ptr)
{
       int hl=0,hr=0;
      if(ptr==NULL)
          return 0;
      if(ptr->left==NULL && ptr->right==NULL)
          return 1;
       else
         {
                   hl=height(ptr->left);
                   hr=height(ptr->right);
         }
        if(hl>hr)
             return hl+1;
        else
              return hr+1;
}


 
         
int main()
 {
                               
       int ch,val,ch2,flag=0,ht;
       char cont='y',cont2='y',cont1='y';

       do  
        {
            cout<<"____________________BST OPERATIONS_____________________\n\n";
            bst b; 
            b.create();   
           do
           {
             system("clear");
                
             cout<<"\nYou have following choices :\n1.Insertion of a value Binary Search Tree\n2.Traversal\n3.Finding minimum value in a BST\n4.Searching a particular value in a BST\n5.Interchanging left and right pointers at each node\n6.Finding no. of nodes in a longest path\nEnter Your Choice:";
                   
                cin>>ch;
             if(flag==1)
              {
                 b.bst_mirror();
                 flag=0;
              }   
                 switch(ch)
                   {
                         case 1:
                                 b.insert();
                                 break;
                         case 2:
                                      //tree traversal
           				 do
          				  {
             					cout<<"\nYou have following choices for traversals:\n1.Pre-Order\n2.In-Order\n3.Post-Order\n4.In-Order(Non-Recursive)\nEnter Your Choice:\n";
             					cin>>ch2;
             					switch(ch2)
              					{
             					      case 1 :  cout<<"\nPre-Order Traversal : \n";  
                             					b.pre_order();
                             					break;
                   				      case 2 :  cout<<"\nIn-Order Traversal : \n";  
                             					b.in_order();
                             					break;
                 				      case 3 :  cout<<"\nPost-Order Traversal : \n";  
                             					b.post_order();
                             					break;
                                                      case 4:   cout<<"\nIn-Order Traversal(Non-Recursive) :\n";
								b.in_order_nonr();
                                                                break;
                				      default: cout<<"\nInvalid Choice....!";
            					}
             					cout<<"\nFor trying another traversal methods press(y/n) :";
            					cin>>cont2;
            				   }while(cont2=='y'||cont2=='Y');
                                   
                                           break;
	
			 case 3:
                                b.get_min_val();
                                break;
                         
                         case 4:
                                b.search_val();
                                break;
                         
                         case 5:
                                                            
                                   b.bst_mirror();
                                    
                                   cout<<"\nTree mirrored successfully\nInorder traversal on mirrored tree:\n";
                                   b.in_order();
                                   flag=1;
                               
                               break;
                         
                         case 6:
                                ht=b.height();
                                cout<<"\nNo. of nodes in longest path : "<<ht;
                                break;
                        
                         default: cout<<"\nInvalid choice...!!";
                   } 
                 cout<<"\nTo continue with same BST press y :\n";
                 cin>>cont;
            }while(cont=='y'||cont=='Y');
        cout<<"\nFor creation of another BST press y/Y : ";
        cin>>cont1;
      }while(cont1=='y'||cont1=='Y');
   
       return 0;
 }
                         
