//create struct, fill data, save to file
//structure allocated as pointer with: name/age
//user inputs for poth
//save to save.dat

#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *fp;
    
    struct Person{
        int age;
        char name[20];
    }*me;

    //address of me has enough size for a person
    me = (struct Person*)malloc(sizeof(struct Person));
    if (me==NULL){
        printf("not enough memory\n");
        return 0;
    }
    //me->name = (char *)malloc(sizeof(char)*20);
    // if (me->name==NULL){
    //     printf("not enough memory\n");
    //     return 0;
    // }
    printf("Enter name:\n ");
    scanf("%s", me->name);
    printf("Enter age:\n ");
    scanf("%d", &me->age);

    
    printf("name is %s, age is %d\n", me->name, me->age);
    fp = fopen("user.dat","w");
	if( fp==NULL )
	{
		fprintf(stderr,"Unable to create %s\n","user.dat");
		exit(1);
	}
    fwrite(me, sizeof(struct Person), 1, fp);

    fclose(fp);





    return 0;
}