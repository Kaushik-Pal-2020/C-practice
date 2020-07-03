#include <stdio.h> 
void registerStorageClass() 
{ 
    printf("\nDemonstrating register class\n\n"); 
    register char b = 'G';  
    printf("Value of the variable 'b'"
        " declared as register: %d\n", 
        b); 

    printf("--------------------------------"); 
} 

void staticStorageClass() 
{ 
    int i = 0; 

    printf("\nDemonstrating static class\n\n"); 
    printf("Declaring 'y' as static inside the loop.\n"
        "But this declaration will occur only"
        " once as 'y' is static.\n"
        "If not, then every time the value of 'y' "
        "will be the declared value 5"
        " as in the case of variable 'p'\n"); 

    printf("\nLoop started:\n"); 

    for (i = 1; i < 5; i++) { 
        static int y = 5; 
        int p = 10; 
        y++; 
        p++; 
        printf("\nThe value of 'y', "
            "declared as static, in %d "
            "iteration is %d\n", 
            i, y); 

        printf("The value of non-static variable 'p', "
            "in %d iteration is %d\n", 
            i, p); 
    } 
    printf("\nLoop ended:\n"); 

    printf("--------------------------------"); 
} 

int main() 
{  
    registerStorageClass(); 
    staticStorageClass(); 
    return 0; 
} 