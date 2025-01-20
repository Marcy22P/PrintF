/*****************************************************************************/
/*                                                                           */
/*  main_test.c - A complex testing suite for ft_printf vs. printf           */
/*                                                                           */
/*****************************************************************************/

#include <stdio.h>      // Per printf originale
#include <limits.h>     // Per INT_MIN, INT_MAX
#include <stdlib.h>     // Per exit
#include "../ft_printf.h"  // Assicurati di adattare il path al tuo ft_printf.h

/*****************************************************************************/
/* Funzione per stampare una separazione visiva tra i test                   */
/*****************************************************************************/
static void separator(const char *title)
{
    printf("\n--------------------------------------------------\n");
    printf(" TEST SU: %s\n", title);
    printf("--------------------------------------------------\n");
}

/*****************************************************************************
 *  MAIN: Eseguiamo una serie di test che coprono c, s, p, d, i, u, x, X, %   *
 *****************************************************************************/
int main(void)
{
    int   ret_std, ret_ft;
    char  *null_str = NULL;
    char   str_with_null[10] = "AB\0CD";
    void  *null_ptr = NULL;
    void  *valid_ptr = (void*)&ret_std; 

    /************** TEST %c **************/
    separator("%c");
    // Test 1) char semplice
    printf("Test 1) char semplice\n");
    ret_ft  = ft_printf(" -> ft_printf : [%c]\n", 'A');
    ret_std =    printf(" -> printf    : [%c]\n", 'A');
    printf("[Returns: ft_printf=%d, printf=%d]\n", ret_ft, ret_std);

    // Test 2) Carattere nullo
    printf("\nTest 2) char nullo\n");
    ret_ft  = ft_printf(" -> ft_printf : [%c]\n", 0);
    ret_std =    printf(" -> printf    : [%c]\n", 0);
    printf("[Returns: ft_printf=%d, printf=%d]\n", ret_ft, ret_std);

    // Test 3) Carattere '0'+256
    printf("\nTest 3) char fuori range\n");
    ret_ft  = ft_printf(" -> ft_printf : [%c]\n", '0' + 256);
    ret_std =    printf(" -> printf    : [%c]\n", '0' + 256);
    printf("[Returns: ft_printf=%d, printf=%d]\n", ret_ft, ret_std);

    // Test 4) Multipli %c con null in mezzo
    printf("\nTest 4) multipli %%c (con null in mezzo)\n");
    ret_ft  = ft_printf(" -> ft_printf : [%c %c %c]\n", 'X', 0, 'Y');
    ret_std =    printf(" -> printf    : [%c %c %c]\n", 'X', 0, 'Y');
    printf("[Returns: ft_printf=%d, printf=%d]\n", ret_ft, ret_std);

    /************** TEST %s **************/
    separator("%s");
    // Test 1) string normale
    printf("Test 1) string normale\n");
    ret_ft  = ft_printf(" -> ft_printf : [%s]\n", "Hello World");
    ret_std =    printf(" -> printf    : [%s]\n", "Hello World");
    printf("[Returns: ft_printf=%d, printf=%d]\n", ret_ft, ret_std);

    // Test 2) string NULL
    printf("\nTest 2) string NULL\n");
    ret_ft  = ft_printf(" -> ft_printf : [%s]\n", null_str);
    ret_std =    printf(" -> printf    : [%s]\n", null_str);
    printf("[Returns: ft_printf=%d, printf=%d]\n", ret_ft, ret_std);

    // Test 3) string con char nullo in mezzo
    printf("\nTest 3) string con byte nullo interno\n");
    ret_ft  = ft_printf(" -> ft_printf : [%s]\n", str_with_null);
    ret_std =    printf(" -> printf    : [%s]\n", str_with_null);
    printf("[Returns: ft_printf=%d, printf=%d]\n", ret_ft, ret_std);

    /************** TEST %p **************/
    separator("%p");
    // Test 1) puntatore NULL
    printf("Test 1) puntatore NULL\n");
    ret_ft  = ft_printf(" -> ft_printf : [%p]\n", null_ptr);
    ret_std =    printf(" -> printf    : [%p]\n", null_ptr);
    printf("[Returns: ft_printf=%d, printf=%d]\n", ret_ft, ret_std);

    // Test 2) puntatore valido
    printf("\nTest 2) puntatore valido\n");
    ret_ft  = ft_printf(" -> ft_printf : [%p]\n", valid_ptr);
    ret_std =    printf(" -> printf    : [%p]\n", valid_ptr);
    printf("[Returns: ft_printf=%d, printf=%d]\n", ret_ft, ret_std);

    /************** TEST %d e %i **************/
    separator("%d e %i");
    // Test 1) valori misti
    printf("Test 1) valori misti\n");
    ret_ft  = ft_printf(" -> ft_printf : [d=%d] [i=%i]\n", 42, 42);
    ret_std =    printf(" -> printf    : [d=%d] [i=%i]\n", 42, 42);
    printf("[Returns: ft_printf=%d, printf=%d]\n", ret_ft, ret_std);

    // Test 2) zero e valori negativi
    printf("\nTest 2) zero e valori negativi\n");
    ret_ft  = ft_printf(" -> ft_printf : [d=%d] [i=%i] [neg=%d]\n", 0, 0, -123);
    ret_std =    printf(" -> printf    : [d=%d] [i=%i] [neg=%d]\n", 0, 0, -123);
    printf("[Returns: ft_printf=%d, printf=%d]\n", ret_ft, ret_std);

    // Test 3) limiti
    printf("\nTest 3) limiti\n");
    ret_ft  = ft_printf(" -> ft_printf : [INT_MIN=%d] [INT_MAX=%i]\n", INT_MIN, INT_MAX);
    ret_std =    printf(" -> printf    : [INT_MIN=%d] [INT_MAX=%i]\n", INT_MIN, INT_MAX);
    printf("[Returns: ft_printf=%d, printf=%d]\n", ret_ft, ret_std);

    /************** TEST %u **************/
    separator("%u");
    // Test 1) zero, max unsigned
    printf("Test 1) zero, max unsigned\n");
    ret_ft  = ft_printf(" -> ft_printf : [%u] [%u]\n", 0, 4294967295u);
    ret_std =    printf(" -> printf    : [%u] [%u]\n", 0, 4294967295u);
    printf("[Returns: ft_printf=%d, printf=%d]\n", ret_ft, ret_std);

    /************** TEST %x e %X **************/
    separator("%x e %X");
    // Test 1) zero
    printf("Test 1) zero\n");
    ret_ft  = ft_printf(" -> ft_printf : [x=%x] [X=%X]\n", 0, 0);
    ret_std =    printf(" -> printf    : [x=%x] [X=%X]\n", 0, 0);
    printf("[Returns: ft_printf=%d, printf=%d]\n", ret_ft, ret_std);

    // Test 2) valori alti
    printf("\nTest 2) valori alti\n");
    ret_ft  = ft_printf(" -> ft_printf : [x=%x] [X=%X]\n", 4294967295u, 4294967295u);
    ret_std =    printf(" -> printf    : [x=%x] [X=%X]\n", 4294967295u, 4294967295u);
    printf("[Returns: ft_printf=%d, printf=%d]\n", ret_ft, ret_std);

    // Test 3) mix vari
    printf("\nTest 3) mix vari (es. 42, 255, 256, 1024)\n");
    ret_ft  = ft_printf(" -> ft_printf : [%x] [%X] [%x] [%X]\n", 42, 42, 255, 1024);
    ret_std =    printf(" -> printf    : [%x] [%X] [%x] [%X]\n", 42, 42, 255, 1024);
    printf("[Returns: ft_printf=%d, printf=%d]\n", ret_ft, ret_std);

    /************** TEST %% **************/
    separator("%%");
    // Test 1) Solo %%
    printf("Test 1) Solo %%\n");
    ret_ft  = ft_printf(" -> ft_printf : [%%]\n");
    ret_std =    printf(" -> printf    : [%%]\n");
    printf("[Returns: ft_printf=%d, printf=%d]\n", ret_ft, ret_std);

    // Test 2) Più %%
    printf("\nTest 2) Più %%\n");
    ret_ft  = ft_printf(" -> ft_printf : [%%%%] e [%%]\n");
    ret_std =    printf(" -> printf    : [%%%%] e [%%]\n");
    printf("[Returns: ft_printf=%d, printf=%d]\n", ret_ft, ret_std);

    /************** MIX DI CONVERSIONI **************/
    separator("MIX di conversioni");
    ret_ft  = ft_printf(" -> ft_printf : c=%c, s=%s, p=%p, d=%d, u=%u, x=%x, %% \n",
               'Z', "ciao", &ret_ft, -42, 999999, 0xdeadbeef);
    ret_std =    printf(" -> printf    : c=%c, s=%s, p=%p, d=%d, u=%u, x=%x, %% \n",
               'Z', "ciao", &ret_ft, -42, 999999, 0xdeadbeef);
    printf("[Returns: ft_printf=%d, printf=%d]\n", ret_ft, ret_std);

    separator("FINE TEST\n");
    return 0;
}
