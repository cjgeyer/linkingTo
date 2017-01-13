
goompter <- function(x) {
    stopifnot(is.numeric(x))
    stopifnot(is.finite(x))
    .C(C_goompter, n = length(x), x = as.double(x))$x
}

