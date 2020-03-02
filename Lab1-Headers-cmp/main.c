#include <stdio.h>
#include <string.h>
#include "general_fun.h"
#include "interface_vectorD.h"
#include "interface_vectorC.h"

const size_t MAXN = (1U << 31) - 1;

int main() {
    size_t n = 0;
    printf("Write down size of an array : ");
    char sn[100] = "";
    scanf("%s", sn);

    while (sn[0] == '-' || is_greater_than_max(sn, MAXN) || !is_num(sn)){
        if (sn[0] == '-') printf("\nERROR : Negative size. TRY AGAIN!\n\n");
        else if (!is_num(sn)) printf("\nERROR : It's not a number. TRY AGAIN\n\n");
        else printf("\nERROR : Too big size, choose less number <= %zu. TRY AGAIN\n\n", MAXN);
        printf("Write down size of an array : ");
        scanf("%s", sn);
    }

    n = convert_str_to_int(sn);

    char s[100] = "";

    printf("Do you want array of real or complex numbers?\nType \"Real\" or \"Complex\" : ");
    while (scanf("%s", s)) {
        if (!strcmp(s, "Real")) { interface_vectorD(n); break; }
        else if (!strcmp(s, "Complex")) { interface_vectorC(n); break; }
        else printf("\nERROR : Invalid keyword. TRY AGAIN.\n\n");
        printf("Do you want array of real or complex numbers?\nType \"Real\" or \"Complex\" : ");
    }

    return 0;
}
