/*
-in c99 can declare array inside struct without dimension whose size is flexible
-this array should be last member of structure
-structure should contain at least 1 more member


struct student
{
    int stud_id;
    int name_len;
    int struct_size;
    char stud_name[];
};
size of this will be 4+4+4+0=12
studname is not fixed and is a "Flexible Array Member (FAM)"
memory allocation can be done using malloc:  struct student *s = malloc( sizeof(*s) + sizeof(char [strlen(stud_name)])  );

*/






// C program for variable length members in structures in GCC
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

// A structure of type student
struct student
{
	int stud_id;
	int name_len;

	// This is used to store size of flexible character array stud_name[]
	int struct_size;

	// Flexible Array Member(FAM) variable length array must be last member of structure
	char stud_name[];
};

// Memory allocation and initialisation of structure
struct student *createStudent(struct student *s, int id, char a[])
{
	//currently pointer to struct that doesnt exist yet. no memory
	// Allocating memory according to user provide array of characters
	s = malloc( sizeof(*s) + sizeof(char) * strlen(a)); //at this point assign chunk of memory

	s->stud_id = id;
	s->name_len = strlen(a);
	strcpy(s->stud_name, a);

	// Assigning size according to size of stud_name which is a copy of user provided array a[].
	s->struct_size = (sizeof(*s) + sizeof(char) * strlen(s->stud_name));

	return s;
}

// Print student details
void printStudent(struct student *s)
{
	printf("Student_id : %d\n"
		"Stud_Name : %s\n"
		"Name_Length: %d\n"
		"Allocated_Struct_size: %d\n\n",
		s->stud_id, s->stud_name, s->name_len,
		s->struct_size);

	// Value of Allocated_Struct_size is in bytes here
}

// Driver Code
int main()
{
	struct student *s1 = createStudent(s1, 523, "Cherry");//datatype is pointer to student struct
	struct student *s2 = createStudent(s2, 535, "Sanjayulsha");

	printStudent(s1);
	printStudent(s2);

	// Size in struct student
	printf("Size of Struct student: %lu\n", sizeof(struct student));

	// Size in struct pointer
	printf("Size of Struct pointer: %lu", sizeof(s1));

	return 0;
}

/*
Student_id : 523
Stud_Name : SanjayKanna
Name_Length: 11
Allocated_Struct_size: 23

Student_id : 535
Stud_Name : Cherry
Name_Length: 6
Allocated_Struct_size: 18

Size of Struct student: 12
Size of Struct pointer: 8
*/