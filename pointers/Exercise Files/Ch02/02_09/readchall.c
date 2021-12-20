//read file, builds struct, outputs data read
//read data from first program
//use same structure definition
//read from saved.dat
//output structures data

#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *fp;
    
    struct Person{
        int age;
        char name[20];
    }*me;

    fp = fopen("user.dat","r");
    if( fp==NULL )
	{
		fprintf(stderr,"Unable to read file\n");
		exit(1);
	}

    me = (struct Person *)malloc(sizeof(struct Person));
    if (me==NULL){
        printf("not enough memory\n");
        return 0;
    }
    // //me->name = (char *)malloc(sizeof(char)*20);
    // if (me->name==NULL){
    //     printf("not enough memory\n");
    //     return 0;
    // }

    fread(me, sizeof(struct Person), 1, fp);
    printf("name is %s, age is %d\n", me->name, me->age);
    
}
