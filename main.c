#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    // Test char
    ft_printf("Test char: [%c]\n", 'A');
    printf("Vérif printf: [%c]\n", 'A');

    // Test string
    ft_printf("Test string: [%s]\n", "Hello, world!");
    printf("Vérif printf: [%s]\n", "Hello, world!");

    // Test NULL string
    char *null_string = NULL;
    ft_printf("Test NULL string: [%s]\n", null_string);
    if (null_string)
        printf("Vérif printf: [%s]\n", null_string);
    else
        printf("Vérif printf: [(null)]\n");

    // Test integer
    ft_printf("Test integer: [%d]\n", 42);
    printf("Vérif printf: [%d]\n", 42);

    // Test unsigned integer
    ft_printf("Test unsigned integer: [%u]\n", 123456789);
    printf("Vérif printf: [%u]\n", 123456789);

    // Test hexadecimal (lowercase)
    ft_printf("Test hex (lowercase): [%x]\n", 255);
    printf("Vérif printf: [%x]\n", 255);

    // Test hexadecimal (uppercase)
    ft_printf("Test hex (uppercase): [%X]\n", 255);
    printf("Vérif printf: [%X]\n", 255);

    // Test pointer
    int x = 42;
    ft_printf("Test pointer: [%p]\n", &x);
    printf("Vérif printf: [%p]\n", &x);

    // Test percent
    ft_printf("Test percent: [%%]\n");
    printf("Vérif printf: [%%]\n");

    return 0;
}



/*
int main(void)
{
    // Test pour %c (caractère unique)
    ft_printf("Test %%c : [%c]\n", 'A');
    printf("Vérif printf : [%c]\n", 'A');

    // Test pour %s (chaîne de caractères)
    ft_printf("Test %%s : [%s]\n", "Hello, world!");
    printf("Vérif printf : [%s]\n", "Hello, world!");
    ft_printf("Test %%s avec NULL : [%s]\n", NULL);
    printf("Vérif printf avec NULL : [%s]\n", NULL);

    // Test pour %p (pointeur)
    int x = 42;
    ft_printf("Test %%p : [%p]\n", &x);
    printf("Vérif printf : [%p]\n", &x);

    // Test pour %d et %i (entiers signés)
    ft_printf("Test %%d : [%d]\n", 1234);
    printf("Vérif printf : [%d]\n", 1234);
    ft_printf("Test %%i : [%i]\n", -5678);
    printf("Vérif printf : [%i]\n", -5678);

    // Test pour %u (entiers non signés)
    ft_printf("Test %%u : [%u]\n", 123456789);
    printf("Vérif printf : [%u]\n", 123456789);
    ft_printf("Test %%u avec zéro : [%u]\n", 0);
    printf("Vérif printf avec zéro : [%u]\n", 0);

    // Test pour %x et %X (hexadécimal)
    ft_printf("Test %%x : [%x]\n", 255);
    printf("Vérif printf : [%x]\n", 255);
    ft_printf("Test %%X : [%X]\n", 255);
    printf("Vérif printf : [%X]\n", 255);
    ft_printf("Test %%x avec zéro : [%x]\n", 0);
    printf("Vérif printf avec zéro : [%x]\n", 0);

    // Test pour %%
    ft_printf("Test %%%% : [%%]\n");
    printf("Vérif printf : [%%]\n");

    // Test avec plusieurs spécificateurs
    ft_printf("Test combiné : [Char: %c, String: %s, Pointer: %p, Dec: %d, Unsigned: %u, Hex: %x, Percent: %%]\n", 
              'B', "Test", &x, -42, 123456, 0xabcdef);
    printf("Vérif printf : [Char: %c, String: %s, Pointer: %p, Dec: %d, Unsigned: %u, Hex: %x, Percent: %%]\n", 
           'B', "Test", &x, -42, 123456, 0xabcdef);

    return 0;
}

int main(void)
{
    int len1, len2;

    printf("### Tests de conversion hexadécimale en minuscule (%%x) ###\n");

    len1 = ft_printf("Mon ft_printf : %x\n", 0);
    len2 = printf("printf attendu : %x\n", 0);
    printf("Résultats longueur : ft_printf = %d, printf = %d\n\n", len1, len2);

    len1 = ft_printf("Mon ft_printf : %x\n", 42);
    len2 = printf("printf attendu : %x\n", 42);
    printf("Résultats longueur : ft_printf = %d, printf = %d\n\n", len1, len2);

    len1 = ft_printf("Mon ft_printf : %x\n", 255);
    len2 = printf("printf attendu : %x\n", 255);
    printf("Résultats longueur : ft_printf = %d, printf = %d\n\n", len1, len2);

    len1 = ft_printf("Mon ft_printf : %x\n", 123456789);
    len2 = printf("printf attendu : %x\n", 123456789);
    printf("Résultats longueur : ft_printf = %d, printf = %d\n\n", len1, len2);

    printf("### Tests de conversion hexadécimale en majuscule (%%X) ###\n");

    len1 = ft_printf("Mon ft_printf : %X\n", 0);
    len2 = printf("printf attendu : %X\n", 0);
    printf("Résultats longueur : ft_printf = %d, printf = %d\n\n", len1, len2);

    len1 = ft_printf("Mon ft_printf : %X\n", 42);
    len2 = printf("printf attendu : %X\n", 42);
    printf("Résultats longueur : ft_printf = %d, printf = %d\n\n", len1, len2);

    len1 = ft_printf("Mon ft_printf : %X\n", 255);
    len2 = printf("printf attendu : %X\n", 255);
    printf("Résultats longueur : ft_printf = %d, printf = %d\n\n", len1, len2);

    len1 = ft_printf("Mon ft_printf : %X\n", 123456789);
    len2 = printf("printf attendu : %X\n", 123456789);
    printf("Résultats longueur : ft_printf = %d, printf = %d\n\n", len1, len2);

    return 0;
}


int main()
{
    int count;

    // Test des caractères
    // count = printf("Caractere : %c\n", 'A');
    // printf("ft_printf a affiché %d caractères.\n\n", count);

    // Test des chaînes de caractères
    // count = ft_printf("Chaine : %s\n", "Hello, World!");
    // printf("ft_printf a affiché %d caractères.\n\n", count);
    // count = ft_printf("Chaine NULL %s\n", NULL);
    // printf("ft_printf a affiché %d caractères.\n\n", count);

    // // Test des entiers signés et non signés
    // count = ft_printf("Entier signé : %d\n", -12345);
    // printf("ft_printf a affiché %d caractères.\n\n", count);
    // count = ft_printf("Entier non signé : %u\n", 12345);
    // printf("ft_printf a affiché %d caractères.\n\n", count);

    // // Test des hexadécimaux
    // count = ft_printf("Hexadécimal minuscule : %x\n", 255);
    // printf("ft_printf a affiché %d caractères.\n\n", count);
    // count = ft_printf("Hexadécimal majuscule : %X\n", 255);
    // printf("ft_printf a affiché %d caractères.\n\n", count);

    // // Test des pointeurs
    // count = ft_printf("Pointeur NULL : %p\n", NULL);
    // printf("ft_printf a affiché %d caractères.\n\n", count);
    // count = ft_printf("Pointeur valide : %p\n", (void*)0x12345678);
    // printf("ft_printf a affiché %d caractères.\n\n", count);

    // // Test du pourcentage
    count = ft_printf("%%");
    printf("ft_printf a affiché %d caractères.\n\n", count);
    int real_count = ft_printf("%%");
    printf("ft_printf a affiché %d caractères.\n\n", real_count);

    return 0;
}

int main()
{
    int count;

    // Test pour %c (caractère)
    count = ft_printf("Caractère: %c\n", 'A');
    printf("ft_printf a affiché %d caractères.\n\n", count);

    // Test pour %s (chaîne de caractères)
    count = ft_printf("Chaîne: %s\n", "Hello, World!");
    printf("ft_printf a affiché %d caractères.\n\n", count);

    // Test pour %d (entier signé)
    count = ft_printf("Entier signé: %d\n", -12345);
    printf("ft_printf a affiché %d caractères.\n\n", count);

    // Test pour %i (entier signé, identique à %d)
    count = ft_printf("Entier signé (i): %i\n", -6789);
    printf("ft_printf a affiché %d caractères.\n\n", count);

    // Test pour %u (entier non signé)
    count = ft_printf("Entier non signé: %u\n", 12345);
    printf("ft_printf a affiché %d caractères.\n\n", count);

    // Test pour %x (hexadécimal minuscule)
    count = ft_printf("Hexadécimal minuscule: %x\n", 255);
    printf("ft_printf a affiché %d caractères.\n\n", count);

    // Test pour %X (hexadécimal majuscule)
    count = ft_printf("Hexadécimal majuscule: %X\n", 255);
    printf("ft_printf a affiché %d caractères.\n\n", count);

    // Test pour %% (signe de pourcentage)
    count = ft_printf("Signe de pourcentage: %%\n");
    printf("ft_printf a affiché %d caractères.\n\n", count);

    // Comparaison avec le printf standard
    printf("Comparaison avec le printf standard :\n");
    printf("Caractère: %c\n", 'A');
    printf("Chaîne: %s\n", "Hello, World!");
    printf("Entier signé: %d\n", -12345);
    printf("Entier signé (i): %i\n", -6789);
    printf("Entier non signé: %u\n", 12345);
    printf("Hexadécimal minuscule: %x\n", 255);
    printf("Hexadécimal majuscule: %X\n", 255);
    printf("Signe de pourcentage: %%\n");

    return 0;
}
*/
