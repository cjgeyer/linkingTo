
library(foompter)

set.seed(42)

x <- rnorm(5)

identical(foompter(x), sin(3 * x))

