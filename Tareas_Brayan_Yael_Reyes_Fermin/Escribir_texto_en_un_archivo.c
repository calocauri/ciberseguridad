//Crear un programa de terminal
//Recibir input
//Escribir texto en un archivo
#include <stdio.h>
#include <string.h>
int main(void) {
    char buf[4096];
    FILE *f;
    printf("Escribe el texto que deseas en el archivo de texto:\n");
    if (gets(buf) == NULL) {
        printf("No se leyó entrada\n");
        return 1;
    }
    printf(buf);
    size_t len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') buf[len - 1] = '\0';
    f = fopen("C:\\Users\\byrfn\\OneDrive\\Documentos\\GitHub\\ciberseguridad\\salida.txt", "w");
    if (f == NULL) {
        fprintf(stderr, "No se pudo abrir el archivo para escribir\n");
        return 1;
    }
    if (fprintf(f, "%s\n", buf) < 0) {
        fprintf(stderr, "Error al escribir en el archivo\n");
        fclose(f);
        return 1;
    }
    fclose(f);
    printf("Texto guardado en salida.txt en el Escritorio\n");
    return 0;
}
