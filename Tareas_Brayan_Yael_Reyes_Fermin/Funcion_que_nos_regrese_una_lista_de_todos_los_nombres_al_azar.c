#include <stdio.h>
#include <stdlib.h>
#include <time.h>
enum 
{
Bruno,
Jair,
Gael,
Brayan,
Carlos
};
int main()
{
srand(time(NULL));
int n = rand() % 5;
srand(time(NULL));
int n = rand() % 4;
srand(time(NULL));
int n = rand() % 3;
srand(time(NULL));
int n = rand() % 2;
srand(time(NULL));
int n = rand() % 1;
switch (n)
{
case Bruno:
    printf ("Soy Bruno");
    break;
case Gael:
    printf ("Soy Gael");
    break;
case Jair:
    printf ("Soy Jair");
    break;
case Brayan:
    printf ("Soy Brayan");
    break;
case Carlos:
    printf ("Soy Carlos");
    break;
default:
    printf ("No se encontro el alumno");
    break;
}
return 0;
}