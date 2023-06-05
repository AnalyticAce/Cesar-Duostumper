/*
** EPITECH PROJECT, 2023
** cesar
** File description:
** cesar
*/

#include "cesar.h"

void crypt_file (char **av)
{
    FILE *input_file = fopen(av[2], "r");
    if (input_file == NULL) exit (84);
    int n = atoi(av[3]); chmod("crypt", 0666);
    n = n % 26;
    FILE *outfile = fopen("crypt", "w"); int c;
    while ((c = fgetc(input_file)) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            c = c + n;
            (c < 'A') ? c = c + 26 : 0;
            (c > 'Z') ? c = c - 26 : 0;
        }
        if (c >= 'a' && c <= 'z') {
            c = c + n;
            (c < 'a') ? c = c + 26 : 0;
            (c > 'z') ? c = c - 26 : 0;
        } fputc(c, outfile);
    }
    int file = fileno(outfile); fchmod (file, 0444);
    fclose(input_file); fclose(outfile);
}

void crypt_string (char **av)
{
    char *str = strdup(av[2]); FILE *outfile;
    int n = atoi(av[3]); chmod ("crypt", 0666);
    outfile = fopen("crypt", "w"); n = n % 26;
    for (int i = 0; str[i] != '\0'; i++){
        int j = (int) str[i];
        if (j >= 'A' && j <= 'Z') {
            j = j + n;
            (j < 'A') ? j = j + 26 : 0;
            (j > 'Z') ? j = j - 26 : 0;
        }
        if (j >= 'a' && j <= 'z') {
            j = j + n;
            (j < 'a') ? j = j + 26 : 0;
            (j > 'z') ? j = j - 26 : 0;
        }
        str[i] = (char) j;
    }
    fputs(str, outfile); int file = fileno(outfile);
    fchmod (file, 0444); fclose (outfile); free(str);
}

int main (int ac, char **av)
{
    if (ac != 4){
        printf ("Usage: ./cesar -f filename key OR ./cesar -s string key\n");
        return 84;
    }
    if (av[1][0] != '-' || av[1][1] != 's' && av[1][1] != 'f'){
        return 84;
    }
    if (strcmp(av[1], "-s") == 0){
        crypt_string(av);
        return 0;
    }
    if (strcmp(av[1], "-f") == 0){
        crypt_file(av);
        return 0;
    }
    return 0;
}
