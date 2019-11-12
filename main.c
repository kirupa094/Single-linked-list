#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
struct node*link;
};
struct node*root='NULL';
int len;
int main()
{
    int ch;
    while(1)
    {
        printf("single list operations\n");
        printf("1.append\n");
        printf("2.length\n");
        printf("3.addatfirst\n");
        printf("4.addatafter\n");
        printf("5.display\n");
        printf("6.delete\n");
        printf("7.exit\n");
        printf("enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
          case 1:append();
                  break;
          case 2:len=length();
                 printf("length=%d\n",len);
                  break;
          case 3:addatfirst();
                  break;
          case 4:addatafter();
                  break;
          case 5:display();
                 break;
          case 6:delete();
                  break;
          case 7:exit(1);
                  break;
          default:printf("invalid enter option");

        }
    }
    return 0;
}
void append()
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&temp->data);
    temp->link='NULL';
    if(root=='NULL')
    {
        root=temp;
    }
    else
    {
        struct node*p;
        p=root;
        while(p->link!='NULL')
        {
            p=p->link;
        }
        p->link=temp;
    }
}
int length()
{
    int count=0;
    struct node*temp;
    temp=root;
    while(temp!='NULL')
    {
        count++;
        temp=temp->link;
    }
    return count;
}
void display()
{
    struct node*temp;
    temp=root;
    if(temp=='NULL')
    {
        printf("No elements in list\n");
    }
    else
    {
        while(temp!='NULL')
        {
            printf("%d-->",temp->data);
            temp=temp->link;
        }
        printf("\n\n");
    }
}
void addatfirst()
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&temp->data);
    temp->link='NULL';
    if(root=='NULL')
        root=temp;
    else
    {
        temp->link=root;
        root=temp;
    }
}
void addatafter()
{
    struct node*temp,*p;
    int loc,i=1;
    printf("Enter which location you insert:");
    scanf("%d",&loc);
    if(loc>length())
    {
        printf("Invalid location occur\n");
    }
    else
    {
       p=root;
       while(i<loc)
       {
           p=p->link;
           i++;
       }
       temp=(struct node*)malloc(sizeof(struct node));
       printf("Enter data:");
       scanf("%d",&temp->data);
       temp->link=p->link;
       p->link=temp;
    }
}
void delete()
{
    struct node*temp;
    int loc;
    printf("Enter which location you delete:");
    scanf("%d",&loc);
    if(loc>length())
    {
        printf("Invalid location\n");
    }
    else
        if(loc==1)
    {
        temp=root;
        root=temp->link;
        temp->link='NULL';
        free(temp);
    }
    else
    {
        struct node*p=root,*q;
        int i=1;
        while(i<loc-1)
        {
            p=p->link;
            i++;
        }
        q=p->link;
        p->link=q->link;
        q->link='NULL';
        free(q);
    }
}
