#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
enum 
{
Bruno,
Jair,
Gael,
Brayan,
Carlos
};
srand(time(NULL));
int n = rand() % 5;
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
printf("Este es el nombre al azar: %d", n);
return 0;
}