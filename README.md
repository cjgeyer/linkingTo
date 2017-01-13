
# Introduction

This repo has two R packages, one of which calls a native routine in the
other (C called from R in one package (`goompter`) calls directly (without
going back to R) C in another package (`foompter`)).  These are just toy
packages that don't do anything interesting.  There is no interest is in
what they do, only in how they do it.

# The Package Called

In order for R package `foompter` to have a function (also named `foompter`)
callable from another package, it has to do a bunch of things.

1. It has to register its C functions called from R via
    the `R_registerRoutines` mechanism
    ([Section 5.4 of *Writing R Extensions*](https://cran.r-project.org/doc/manuals/r-release/R-exts.html#Registering-native-routines).
    Actually, on second thought I don't know that this is necessary
    for the rest of this to work.  But it is a good idea anyway.
    This item only benefits this package `foompter`.  It is the next
    item that benefits the other package `goompter`.
1. It has to register its C functions called from C in other packages via
    the `R_RegisterCCallable` mechanism ([Section 5.4.2 of *Writing R Extensions*](https://cran.r-project.org/doc/manuals/r-release/R-exts.html#Linking-to-native-routines-in-other-packages).
    In our package `foompter` this is done in [`init.c`](packages/foompter/src/init.c).  This file also does item 1 above.
1. It should provide an include file that says how to call the exported
    function.  This include file is exported by putting it in the `include`
    directory of the installed package, which means it is in
    the `inst/include` directory of the source package.  In this include
    file [`foompter.h`](packages/foompter/src/foompter.h) there
    is a typedef
    for a function pointer which can be a pointer to the function we
    want to export.  Just to make sure this is declared correctly,
    we make such a function pointer which we don't actually use in
    this package (in [`foompter.c`](packages/foompter/src/foompter.c))
    just do the compiler will check that the typedef is correct.
1. Since we need the header file in two places we make
    `packages/foompter/inst/include/foompter.h` a symbolic link to
    `packages/foompter/src/foompter.h`.

# The Package Calling

In order for R package `goompter` to be able to call a function
(named `foompter`) from another package, it has to do a bunch of things.

1. It has to make sure that package is loaded before it is by doing two
    things.
    a. It has to put the name of that package in the Imports field of its
    [`DESCRIPTION` file](packages/goompter/DESCRIPTION).
    b. It has to import that package with an `import(foompter)` directive
    in its
    [`NAMESPACE` file](packages/goompter/NAMESPACE).

