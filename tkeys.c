/**
 * @file tkeys.c
 * @author UsboKirishima (usbertibox@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-11-04
 *
 * @copyright Copyright (c) 2024 Davide Usberti
 *
 */
#include <stdio.h>
#include <core.h>

#include <option_parser.h>

char *menu_ascii = "Welcome to tkeys!\n"
                   "   1) Set encryption key\n"
                   "   2) Add password\n"
                   "   3) Edit password\n"
                   "   4) Remove from database\n";

void print_ascii()
{
    puts(menu_ascii);
}

__uint8_t main_menu()
{
    print_ascii();
}

int main(int argc, char **argv)
{
    main_menu();
    set_encryption_key("ciao");
    return 0;
}