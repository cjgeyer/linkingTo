
// See Section 5.4 of Writing R Extensions
//
// Remove styles, which are deprecated in R-3.3.3

#include <Rdefines.h>
#include <R_ext/Rdynload.h>
#include "foompter.h"

static R_NativePrimitiveArgType foompter_types[2] = {INTSXP, REALSXP};

static R_CMethodDef cMethods[] = {
    {"foompter", (DL_FUNC) &foompter, 2, foompter_types},
    {NULL, NULL, 0, NULL}
};

static R_CallMethodDef callMethods[]  = {
    {NULL, NULL, 0}
};

void R_init_foompter(DllInfo *info)
{
    R_registerRoutines(info, cMethods, callMethods, NULL, NULL);

    R_RegisterCCallable("foompter", "foompter", (DL_FUNC) foompter);
}

