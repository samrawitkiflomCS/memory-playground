#include <stdio.h>
#include <stdlib.h>

int main(){
   int *ptr=malloc(sizeof(int));
   *ptr =57;

    printf("Heap variable befor free:%p, value: %d\n", ptr,*ptr);

    free(ptr);//free memory


     //Dangling pointer: memory has been freed
      printf("Heap variable after free(dangling): %p, value:%d\n",ptr, *ptr);

      ptr=NULL;// nullify dangling pointer

      return 0;
     }

