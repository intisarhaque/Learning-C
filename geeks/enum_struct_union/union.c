/*
    User defined data type like struct but unlike struct shares same memory location



*/
// #include <stdio.h>

// union test {
// 	int x;
// 	char y;
// };

// int main()
// {
// 	union test p1;
// 	p1.x = 65;

// 	// p2 is a pointer to union p1
// 	union test* p2 = &p1;

// 	// Accessing union members using pointer
// 	printf("%d %c", p2->x, p2->y);
// 	return 0;
// }

//means every node required 16 bytes with half wasted for each type of node
struct NODE {
	struct NODE* left;
	struct NODE* right;
	double data;
};
//save space using:
struct NODE {
	bool is_leaf;
	union {
		struct
		{
			struct NODE* left;
			struct NODE* right;
		} internal;
		double data;
	} info;
};
