#include<iostream>


int increment(int number){
    return (number +1);
}
void incrementReference(int &number){
    number = number + 1;
    printf("&numberRef = %d \n", number);
}

void incrementPointer(int *number){
    *number = *number + 1;
    printf("pointNumber = %d \n", number);
}

int main(){
    int a = 0;
    int b = 0;
    int c = 0;
    int *pointer = &c;

    a = increment(a);
    printf("a = %d \n", a); 

    incrementReference(b);
    printf("b = %d \n", b);

    incrementPointer(pointer);
    printf("&c = %d \n", &c);
    printf("c = %d \n", c);
    return 0;
}