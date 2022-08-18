#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void InsertAtBeginning(char value[30]);

void InsertAtEnd(char name[30], char lastname[30], char number[30], char number2[30], struct Node *newNumber);
void RemoveAtBeginning();
void RemoveAtEnd();
void RemoveAtPosition(struct Node *newNumber);
void display();
int CheckEmpty();
int last;

struct Node{
    char fname[31];
    char lname[31];
    char telep[15];
    char cellp[15];

    struct Node *next;
}* head=NULL;
int main()
{
    int choice;
    char c,name[30], lastname[30], number[30], number2[30] , value[30];
    struct Node *newNumber;

    do{
        printf("Enter\n1-Insert\n2-Remove\n3-Display\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {

                printf("Enter Name to be Inserted\n");
                scanf("%s" , &name);
                printf("Enter last Name to be Inserted\n");
                scanf("%s ", &lastname);
                printf("Enter number to be Inserted\n");
                scanf("%s ", &number);
                printf("Enter cellnumber to be Inserted\n");
                scanf("%s ", &number2);


                InsertAtEnd(name, lastname, number, number2, newNumber);

                break;
            }

            case 2:
            {

                RemoveAtPosition(newNumber);


            }
            case 3:
            {
                display();
                break;
            }
            default:
            {
                printf("Enter Valid Choice\n");
                break;
            }
        }
        printf("Enter 'Y' to continue else any letter\n");
        fflush(stdin);
        c=getchar();
        printf("\n");
    }while(c=='Y' || c=='y');

    return(0);
}

//----------------------------------------------------------------------------------------------------------------------

void InsertAtEnd(char name[30], char lastname[30], char number[30], char number2[30],  struct Node *newNumber){

    newNumber = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNumber->fname,name);
    strcpy(newNumber->lname,lastname);
    strcpy(newNumber->telep,number);
    strcpy(newNumber->cellp,number2);

    newNumber->next=NULL;
    if(head==NULL)
    {
        head=newNumber;
    }
    else
    {
        struct Node *temp;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNumber;
    }

}
//----------------------------------------------------------------------------------------------------------------------

void RemoveAtEnd(){
    int flag=CheckEmpty();
    if(flag==1)
    {
        if(head->next==NULL)
        {
            head=NULL;
        }
        else
        {
            struct Node *temp=head,*temp1;
            while(temp->next!=NULL)
            {
                temp1=temp;
                temp=temp->next;
            }
            temp1->next=NULL;
            free(temp);
        }

    }
    else
    {
        printf("List Empty.Try again!\n");
    }
}
void clrscr()
{
    system("clear");
}

//--------------------------------------------------------------------------------------------------------------------
void RemoveAtPosition(struct Node *Node){





    char dfname_string[5],dlname_string[5];
    char *input = NULL;
    size_t len=0;
    size_t len_size=0;
    register int i,j,find=0;
    char ch;
    clrscr();
    printf("\nPhone Book12<::>Delete Contacts");
    printf("\n--------------------------------------------------------------------------------");
    printf ("\n::Enter data of the contact that you want delete it,please:");
    printf("\n\n  ::Enter first name: ");
    len_size = getline(&input,&len,stdin);
    strcpy(dfname_string,input);

    printf("\n  ::Enter last name: ");
    len_size = getline(&input,&len,stdin);
    strcpy(dlname_string,input);

    for (i = 0; i < last; i++) {
        if (strcmp (dfname_string, A[i].fname) == 0 && strcmp (dlname_string, A[i].lname) == 0 ) {

            printf("\nContact was found! Details:");
            printf("\n\nCantact %2.2d{",i+1);
            printf("\n\t   F.Name:%s\n\t   L.name:%s\n\t   Tele.P:%s\n\t   Cell.P:%s\n\t   }",A[i].fname,A[i].lname,A[i].telep,A[i].cellp);
            printf("\n\nAre you sure you want to delete this contact?(y/n)");
            ch = getc(stdin);
            getc(stdin);
            if(ch == 'y'){
                for(j = i ; j <= last ; j++)
                    A[j] = A[j+1];

                last--;
                find = 1;
                break;
            }
        }
    }
    if (find==0)
        printf("\t\t\n<<This contact does not exist in this list or program can not delete it.>>");
    else
        printf("\t\t\n<<Target contact was successfully deleted from list!>>");
    printf("\n\n\nPress a key to return main page & continue program|-->");
    getc(stdin);
//    int flag=CheckEmpty();
//    if(flag==1)
//    {
//        int count=0,flag1=0,i;
//        struct Node *temp=head;
//        if(position==1)
//        {
//            head=temp->next;
//            free(temp);
//            return;
//        }
//        for(i=0;i<position-2;i++)
//        {
//            temp=temp->next;
//        }
//        struct Node *temp1=temp->next;
//        temp->next=temp1->next;
//        free(temp1);
//
//
//    }
//    else
//    {
//        printf("List is empty\n");
//    }

}
//-------------------------------------------------------------------------------------------------------------------

void display(){
    int flag=CheckEmpty();
    if(flag==1)
    {
        struct Node *temp;
        temp=head;
        while(temp->next!=NULL)
        {

            printf("%s ",temp->fname);
            printf("%s ",temp->lname);
            printf("%s ",temp->telep);
            printf("%s ",temp->cellp);
            temp=temp->next;
        }

        printf("%s ",temp->fname);
        printf("%s ",temp->lname);
        printf("%s ",temp->telep);
        printf("%s ",temp->cellp);
        temp=temp->next;
        printf("\n");
    }
    else
    {
        printf("No List Available\n");
    }
}

int CheckEmpty()
{
    if(head==NULL)
        return 0;
    else
        return 1;
}
