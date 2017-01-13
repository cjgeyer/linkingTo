
foompter <- function(x) {
    stopifnot(is.numeric(x))
    stopifnot(is.finite(x))
    .C(C_foompter, n = length(x), x = as.double(x))$x
}

