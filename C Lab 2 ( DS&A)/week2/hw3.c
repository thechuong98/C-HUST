/*Replace a substring by a substring*/
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{  
  if(argc == 4){
    char buffer[1024] = { 0 };
    char *insert_point = &buffer[0];
    char *tmp = argv[1];
    size_t needle_len = strlen(argv[2]);
    size_t repl_len = strlen(argv[3]);

    while (1) {
        char *p = strstr(tmp, argv[2]);

        // walked past last occurrence of needle; copy remaining part
        if (p == NULL) {
            strcpy(insert_point, tmp);
            break;
        }

        // copy part before needle
        memcpy(insert_point, tmp, p - tmp);
        insert_point += p - tmp;

        // copy replacement string
        memcpy(insert_point, argv[3], repl_len);
        insert_point += repl_len;

        // adjust pointers, move on
        tmp = p + needle_len;
    }

    // write altered string back to target
    strcpy(tmp, buffer);
    printf("%s\n", tmp);
    }
  else printf("Not in form. The form should be 'program text str1 str2\n");
}

