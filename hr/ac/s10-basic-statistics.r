stdin <- file("stdin")
open(stdin)

readLines(stdin, n = 1, warn = FALSE) # Consumes line to ignore `n`
x <- as.integer(strsplit(trimws(
    readLines(stdin, n = 1, warn = FALSE), which = "both"), " ")[[1]])

close(stdin)

mean_ <- function(x) {
  sum(x) / length(x)
}
cat(mean_(x), "\n")

median_ <- function(x) {
  y <- sort(x)
  if (length(x) %% 2 == 0) {
    return((y[length(x) / 2] + y[(length(x) / 2) + 1]) / 2)
  } else {
    return(y[length(x) / 2])
  }
}
cat(median_(x), "\n")

mode_ <- function(x) {
  u <- sort(unique(x))
  c <- tabulate(match(x, u))
  u[c == max(c)]
}
cat(mode_(x)[1], "\n")
