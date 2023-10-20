#include<stdio.h>

void towerOfHanoi(int n, char start, char auxilary, char destination){
    if(n == 0)
    {
        return;
    }
    towerOfHanoi(n-1, start, destination, auxilary);
    printf("Disk no %d moved from %c to %c rod\n", n, start, destination);
    towerOfHanoi(n-1, auxilary, start, destination);
}

int main(){
    int n;
    printf("Enter Number of disks\n");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}