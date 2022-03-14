stdin <- file("stdin")
open(stdin)

readLines(stdin, n = 1, warn = FALSE) # Consumes line to ignore `n`
x <- as.integer(strsplit(trimws(
  readLines(stdin, n = 1, warn = FALSE), which = "both"), " ")[[1]])
w <- as.integer(strsplit(trimws(
  readLines(stdin, n = 1, warn = FALSE), which = "both"), " ")[[1]])

close(stdin)

weighted_mean <- function(x, w) {
  sum(x * w) / sum(w)
}
cat(sprintf("%.1f", weighted_mean(x, w)), "\n")
