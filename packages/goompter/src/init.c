
// See Section 5.4 of Writing R Extensions
//
// Remove styles, which are deprecated in R-3.3.3

#include <Rdefines.h>
#include <R_ext/Rdynload.h>
#include "goompter.h"

static R_NativePrimitiveArgType goompter_types[2] = {INTSXP, REALSXP};

static R_CMethodDef cMethods[] = {
    {"goompter", (DL_FUNC) &goompter, 2, goompter_types},
    {NULL, NULL, 0, NULL}
};

static R_CallMethodDef callMethods[]  = {
    {NULL, NULL, 0}
};

void R_init_goompter(DllInfo *info)
{
    R_registerRoutines(info, cMethods, callMethods, NULL, NULL);
}

