---
title: ft_printf
---

# Introduction / Introduzione

A project from 42 Roma Luiss that implements a custom version of the
standard `printf` function.\
Un progetto della 42 Roma Luiss che implementa una versione custom della
funzione standard `printf`.\
**Note / Nota Bene:** This project is implemented **without bonus**.\
Il progetto è realizzato **senza bonus**.

# What Does `ft_printf` Do? / Cosa fa `ft_printf`?

The `ft_printf` function mimics the behavior of the original `printf`.
It supports the following conversion specifiers:\
La funzione `ft_printf` riproduce il comportamento della `printf`
originale e supporta i seguenti specificatori di conversione:

-   **`%c`**: Print a character / Stampa un carattere.

-   **`%s`**: Print a string / Stampa una stringa.

-   **`%p`**: Print a pointer address / Stampa un indirizzo puntatore.

-   **`%d` and `%i`**: Print a signed integer / Stampa un intero con
    segno.

-   **`%u`**: Print an unsigned integer / Stampa un intero senza segno.

-   **`%x` and `%X`**: Print an unsigned integer in hexadecimal
    (lowercase or uppercase) / Stampa un intero senza segno in
    esadecimale (minuscolo o maiuscolo).

-   **`%%`**: Print a literal `%` character / Stampa il carattere `%`.

# Repository Structure / Struttura della Repository

The repository is organized as follows:\
La repository è organizzata nel seguente modo:

    ft_printf/                 # Main ft_printf project directory
    ├── ft_print_char.c
    ├── ft_print_hex.c
    ├── ft_print_numbers.c      # Contains print_decimal and print_unsigned
    ├── ft_print_percent.c
    ├── ft_print_ptr.c
    ├── ft_print_string.c
    ├── ft_printf.c
    ├── ft_sort_printf.c
    ├── ft_printf.h
    └── Makefile

    tester/                   # Tester directory
    ├── main_test.c
    └── Makefile

# Norminette

To check the coding style, please use
[Norminette](https://github.com/42School/norminette).\
Per controllare lo stile del codice, utilizza
[Norminette](https://github.com/42School/norminette).

# Included Tester / Tester Incluso

This repository includes a comprehensive tester to compare the output
and return values of `ft_printf` against the original `printf`.\
La repository include un tester completo che confronta l'output e il
valore di ritorno di `ft_printf` con quelli della `printf` originale.

## What Does the Tester Check? / Cosa Testa il Tester?

-   **`%c`**:

    -   Regular characters / Caratteri semplici.

    -   Null characters / Caratteri nulli.

    -   Out-of-range values / Valori fuori range.

-   **`%s`**:

    -   Normal strings / Stringhe normali.

    -   `NULL` strings / Stringhe NULL.

    -   Strings with embedded null bytes / Stringhe con byte nullo
        interno.

-   **`%p`**:

    -   `NULL` pointers / Puntatori NULL.

    -   Valid pointers / Puntatori validi.

-   **`%d` and `%i`**:

    -   Mixed values / Valori misti.

    -   Zero and negative numbers / Zero e numeri negativi.

    -   Edge cases (e.g., `INT_MIN` and `INT_MAX`) / Casi limite (es.
        `INT_MIN` e `INT_MAX`).

-   **`%u`**:

    -   Unsigned numbers, including zero and maximum unsigned values /
        Numeri senza segno, inclusi zero e il massimo valore unsigned.

-   **`%x` and `%X`**:

    -   Hexadecimal conversion in both lowercase and uppercase /
        Conversione esadecimale in minuscolo e maiuscolo.

-   **`%%`**:

    -   Printing the `%` character / Stampa del carattere `%`.

-   **Mixed conversions**:

    -   A combination of multiple specifiers in a single output /
        Combinazione di vari formati in un'unica stringa.

## How to Use the Tester / Come Utilizzare il Tester

1.  **Compilation**\
    In the tester directory, run:\
    Nella cartella del tester, esegui:

        make

    This command will compile the tester and automatically compile your
    `ft_printf` project by invoking its Makefile.\
    Questo comando compilerà il tester e compilerà automaticamente il
    progetto `ft_printf` richiamando il relativo Makefile.

2.  **Running the Tests**\
    After compilation, run:\
    Dopo la compilazione, esegui:

        ./test_printf

    This will execute a series of tests, printing the results for each
    conversion specifier.\
    Verrà eseguita una serie di test, mostrando a video i risultati per
    ciascun specificatore di conversione.

# External Tester

An external tester is available which you can use to further validate
your implementation.\
È disponibile anche un tester esterno per validare ulteriormente la tua
implementazione:\
[printfTester](https://github.com/Tripouille/printfTester.git)

# Moulinette Grade / Valutazione Moulinette

Here is my grade from the moulinette for `ft_printf`:\
\_Esito dalla moulinette:\_

    Hi,
    You have been graded 100 on ft_printf:
    test_spdxiucpercent: 8/8 correct functions | bonus_one: KO (Does not compile) | bonus_two: KO (Does not compile)
