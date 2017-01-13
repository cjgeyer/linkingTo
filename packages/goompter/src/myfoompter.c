#include <stddef.h>
#include <R_ext/Rdynload.h>
#include "myfoompter.h"
#include "foompter.h"

void myfoompter(int *n, double *x)
{
    static foompter_funptr fun = NULL;
    if (fun == NULL)
        fun = (foompter_funptr) R_GetCCallable("foompter", "foompter");
    fun(n, x);
}
