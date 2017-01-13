
library(goompter)

set.seed(42)

x <- rnorm(5)

identical(goompter(x), sin(3 * x))

