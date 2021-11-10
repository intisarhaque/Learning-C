#include <stdlib.h>

// int a = 10;
// char b = 'x';

// void *p = &a; // void pointer holds address of int 'a'
// p = &b; // void pointer holds address of char 'b'

// #include<stdio.h>
// int main()
// {
// 	int a = 10;
// 	void *ptr = &a;
// 	printf("%d", *ptr);
// 	return 0;
// }
// //above cannot be dereferenced


// #include<stdio.h>
// int main()
// {
// 	int a = 10;
// 	void *ptr = &a;
// 	printf("%d", *(int *)ptr); //type-casted (int *) then dereferenced
// 	return 0;
// }
// //this is fine

//cannot do pointer arithmetic with void pointers

//null pointer
//int * pInt = NULL;
int main(){
	int *ptr;
	ptr = (int*)malloc(2*sizeof(int));
	if(ptr==NULL){
		printf("memory not allocated");
	}
	else{
		printf("memory allocated");
	}
}

