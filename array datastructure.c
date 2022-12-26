#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int menu();
struct ArrayADT
{
int lastindex;
int capacity;
int *ptr;
};
void doubl(struct ArrayADT *arr)
{
int *temp,i;
temp=(int*)malloc(sizeof(int)*arr->capacity*2);
for(i=0;i<=arr->lastindex;i++)
{
temp[i]=arr->ptr[i];
}
free(arr->ptr);
arr->ptr=temp;
arr->capacity=arr->capacity*2;
}
void half(struct ArrayADT *arr)
{
int *temp,i;
temp=(int*)malloc(sizeof(int)*arr->capacity/2);
for(i=0;i<=arr->lastindex;i++)
{
temp[i]=arr->ptr[i];
}
free(arr->ptr);
arr->ptr=temp;
arr->capacity=arr->capacity/2;
}
struct ArrayADT* createarray(int cap)
{
struct ArrayADT *arr;
arr=(struct ArrayADT*)malloc(sizeof(struct ArrayADT));
arr->lastindex=-1;
arr->capacity=cap;
arr->ptr=(int*)malloc(sizeof(int)*cap);
return arr;
}
void append(struct ArrayADT *arr,int data)
{
if(arr->lastindex==arr->capacity-1)
doubl(arr);
arr->lastindex++;
arr->ptr[arr->lastindex]=data;
}
void insert(struct ArrayADT *arr,int data,int index)
{
if(index<0||index>arr->lastindex+1)
printf("invalid index");
else if(arr->lastindex==arr->capacity-1)
doubl(arr);
else
{
arr->ptr[index]=data;
arr->lastindex++;
}
}
int count_number(struct ArrayADT *arr)
{
return arr->lastindex+1;
}
int get( struct ArrayADT *arr,int index)
{
if(index<0||index>arr->lastindex)
printf("invalid index");
else
return arr->ptr[index];
}
void delete(struct ArrayADT *arr,int index)
{
int i;
if(index<0||index>arr->lastindex)
printf("invalid index");
else
for(i=index;i<=arr->lastindex;i++)
{
arr->ptr[i]=arr->ptr[i+1];
}
arr->lastindex--;
if(arr->lastindex==arr->capacity/2)
half(arr);
}

void edit(struct ArrayADT *arr,int data,int index)
{
if(index<0||index>arr->lastindex)
printf("invalid index");
else
arr->ptr[index]=data;
}
int search(struct ArrayADT *arr,int data)
{
int i;
for(i=0;i<=arr->lastindex;i++)
{
if(arr->ptr[i]==data)
break;
}
if(i>arr->lastindex)
printf("not found");
else
return i;
}

void printlist(struct ArrayADT *arr)
{
int i;
if(arr->lastindex>=0)
{
for(i=0;i<=arr->lastindex;i++)
printf("%d",arr->ptr[i]);
}
else
printf("list is empty");
}
int menu()
{
int x;
printf("1=To create array\n");
printf("2=To append the element\n");
printf("3=To insert the element\n");
printf("4=To delete the element\n");
printf("5=To get the element at given index\n");
printf("6=To edit the element\n");
printf("7=To search an element\n");
printf("8=To count the number of element present\n");
printf("9=TO exit\n");
printf("ENTER YOUR CHOICE");
scanf("%d",&x);
return x;
}
int main()
{
int a,b;
struct ArrayADT *arr;
while(1)
{
printlist(arr);
switch(menu())
{
case 1:
      printf("enter the capacity");
      scanf("%d",&a);
      arr=createarray(a);
      break;
case 2:
      printf("enter the element");
      scanf("%d",&a);
      append(arr,a);
      break;
case 3:
       printf("enter the element");
       scanf("%d",&a);
       printf("enter the index");
       scanf("%d",&b);
       insert(arr,a,b);
       break;
case 4:
       printf("enter the index");
       scanf("%d",&b);
       delete(arr,b);
       break;
case 5:
       printf("enter the index");
       scanf("%d",&b);
       a=get(arr,b);
       printf("element is %d",a);
       break;
case 6:
       printf("enter the data");
       scanf("%d",&a);
       printf("enter the index");
       scanf("%d",&b);
       edit(arr,a,b);
       break;
case 7:
       printf("enter the data");
       scanf("%d",&a);
       b=search(arr,a);
       break;
case 8:
       a=count_number(arr);
       printf("the no of element are =%d",a);
       break;
case 9:
       exit(0);
default :
       printf("invalid choice");
}
}
}

