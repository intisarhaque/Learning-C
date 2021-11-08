// C program to demonstrate
// example of time() function.
//time_t time( time_t *second )

#include <stdio.h>
#include <time.h>

int main ()
{
	time_t seconds;
	
	seconds = time(NULL);
    // or can do time(&seconds);
	printf("Seconds since January 1, 1970 = %ld\n", seconds);
	
	return(0);
}
