# MiniShell

| Functions | Lib | Prototype (linux) | Description |
| --- | --- | --- | --- |
| `Malloc` | <stdlib.h> | void *malloc(size_t size); | Permet d'allouer dynamiquement de la mémoire de **size** octet et renvoie un pointeur sur la mémoire allouée (heap) |
| `Free` | <stdlib.h> | void free(void *ptr);      | Permet de liberer l'espace mémoire pointé par ptr, qui a été obtenu lors d'un appel antérieur à malloc() |
| `Write` | <unistd.h> |  ssize_t write(int fd, const void *buf, size_t count); | Permet d'écrire  **count** octet dans le fichier associé au descripteur [fd](https://en.wikipedia.org/wiki/File_descriptor) |
| `Open` |  

sources:

Signal :

- https://www.tutorialspoint.com/c_standard_library/c_function_signal.htm
