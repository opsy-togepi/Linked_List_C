#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *ptr;
};

int main()
{
    struct node *t , *t1 , *last=NULL , *start=NULL ;
    int ch , i , pos , ele , flag , count , mid_ele , n ;
    flag = 0 ;
    count = 0 ;
	do
    {
        printf("Enter your choice :- \n1. Creation \n2. Insertion \n3. Deletion \n4. Search (Linear) \n5. Print \n6. Middle elements \n7.exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("enter the number of nodes\n");
	        scanf("%d",&n);
	        for(i=0;i<n;i++)
	        {
		        t= (struct node*)malloc(sizeof(struct node));
		        printf("enter data\n");
		        scanf("%d", &( t->data ) );
		        t->ptr=NULL;
		        if(start == NULL)
		        {
			        start=last=t;
			        printf("LL created \n");
		        }
		        else{
			        last->ptr=t;
			        last=t;
			        printf("new node created \n");
		        }
	        }
            break;
        case 2:
            if( start == NULL )
            {
                printf("Linked List doesn't exist. Unable to insert. try creating a list first. \n ");
            }
            else
            {
                printf("enter the position where you were to insert the node \n");
                scanf("%d",&pos);
                t=(struct node*)calloc(1,sizeof(struct node));
                printf("Enter the data \n ");
                scanf("%d", &(t->data) );
                t -> ptr = NULL ;
                if( pos == 1 )
                {
                    t -> ptr = start;
                    start = t;
                }
                else
                {
                	printf("Node inserted \n");
                    t1=start;
                    for(i=1; i <pos-1;i++)
                    {
                        t1=t1->ptr;
                    }
                    t -> ptr = t1->ptr;
                    t1 -> ptr = t;
                       
                }
            }
            break;
        case 3:
            if( start == NULL)
            {
                printf("Linked List doesnt exist. Try creating a list first. \n ");
            }
            else
            {
                printf("Enter the position you want to delete node from \n ");
                scanf("%d",&pos);
                if( pos == 1)
                {
                    start = start -> ptr;
                }
                else
                {
                    t1 = start;
                    for ( i = 2; i < pos; i++)
                    {
                        t1 = t1 -> ptr;
                    }
                    t = t1 -> ptr ;
                    t1 -> ptr = t -> ptr ;
                    printf("node deleted \n");
                }
            }
            break;
        case 4:
            if( start == NULL )
            {
                printf ("No Linked List exists \n");
            }
            else
            {
                printf(" enter the data to be searched \n");
                scanf("%d", &ele);
                for( t = start ; t -> ptr != NULL ; t = t -> ptr)
                {
                    flag++;
                    if(ele == t -> data)
                    {
                        printf ( "element found at %d \n" , flag );
                        flag = -1;
                        break;
                    }
                }
                if(flag != (-1))
                {
                    printf("Element not found! \n");
                }
            }
            break;
            
        case 5:
            if( start == NULL )
            {
                printf ("No Linked List exists \n");
            }
            else
            {
                for( t = start ; t -> ptr != NULL ; t = t -> ptr)
                {
                        printf ( "%d \n" , t -> data );
                }
                printf( "%d \n" , t -> data);
            }
            break;
        case 6:
            if( start == NULL )
            {
                printf ("No Linked List exists \n");
            }
            else
            {
                for( t = start ; t -> ptr != NULL ; t = t -> ptr)
                {
                        count ++ ;
                }
                mid_ele = count / 2 + 1;
                t = start ; 
                for ( i = 1; i < mid_ele; i++)
                {
                    t = t -> ptr;
                }
                printf("data at mid ele is %d \n", (t -> data ));
                
            }
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Wrong Choice !! \n");
            break;
        }
    } while (ch);
    
    return 0;
}
