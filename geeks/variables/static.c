#include <stdio.h>
int z = 20; //global
extern int w = 50; //can be used in multiple files
const a = 1; //value cant be changed. must be initiatlised during declaration
void function(){
int x = 20;//local variable (also auto?)
static int y = 30;//static variable
x = x + 10;
y = y + 10;
printf("\n%d,%d,%d",x,y,z);
}

int main() {

function();
function();
function();
return 0;
}
