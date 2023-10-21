#include<iostream>
//#include<vector>

void incrementArray(int *element, int sizeArray){
    for (int i = 0; i < sizeArray; i++)
    {
        *(element + i)= *(element+i)+1;
    }
    
}

int main(){
    int array[] = {0, 1,2,3,4};
    incrementArray(array, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("array %d = %d \n", i, array[i]);
    }
    

}