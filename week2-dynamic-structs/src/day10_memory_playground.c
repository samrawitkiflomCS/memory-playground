#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char* name;
    int value;
} person;
person* create_person(char* alice, int num)
{
    person* p= malloc(sizeof(person));
    if (!p)return 0;
    p->name=malloc(strlen(alice)+1);//we access  name using->, then we store value in name. but name expects an address value because it is a pointer itself. when we allocate memory, we're storing address in it as it is meant to be.
    if(!p->name)
    {
        free(p);
        return 0;
    }
    strcpy(p->name,alice);
    p->value=num;
   
    return p;
}
void show_value(person*p){
if (!p)return;
printf("value=%d name=%s\n", p->value, p->name);
}
void destroy_func(person*p){
    if(!p)return;// to avoid dereferencing null pointer
free(p->name);
free(p);
}
int main()
{
int n=3;
person** point= malloc(n*sizeof(*point));
if (!point)return 1;
point[0]=create_person("alpha",45);
point[1]=create_person("beta",46);
point[2]=create_person("gamma",47);
for(int i=0; i<n;i++)
{
show_value(point[i]);
}
n=5;
person** temp=realloc(point, n*sizeof(*temp));
if (!temp)
{
for(int i=0; i<3; i++) 
{
    destroy_func(point[i]);
     point[i]=NULL;
}
free (point);
point=NULL;
return 1;
}
point=temp;
point[3]=create_person("theta",56);
point[4]=create_person("omega",42);
printf("\nafter resizing\n");
for(int i=0; i<n; i++)
{
    show_value(point[i]);
}
for(int i=0; i<n; i++) 
{
    destroy_func(point[i]);
     point[i]=NULL;
}
free (point);
point=NULL;
return 42;
}
