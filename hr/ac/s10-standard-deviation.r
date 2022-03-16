stdin <- file("stdin")
open(stdin)

invisible(readLines(stdin, n = 1, warn = FALSE)) # Consumes line to ignore `n`
x <- as.integer(strsplit(trimws(
  readLines(stdin, n = 1, warn = FALSE), which = "both"), " ")[[1]])

close(stdin)

stddev <- function(x) {
  (sum((x - mean(x)) ** 2) / length(x)) ** 0.5
}
cat(sprintf("%.1f", stddev(x)), "\n")
