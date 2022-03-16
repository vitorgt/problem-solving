stdin <- file("stdin")
open(stdin)

invisible(readLines(stdin, n = 1, warn = FALSE)) # Consumes line to ignore `n`
x <- as.integer(strsplit(trimws(
  readLines(stdin, n = 1, warn = FALSE), which = "both"), " ")[[1]])

close(stdin)

quartiles <- function(x) {
  y <- sort(x)
  if (length(y) %% 2 == 0) {
    return(c(
      median(y[1:(length(y) / 2)]),
      median(y),
      median(y[(length(y) / 2 + 1):length(y)])
    ))
  } else {
    return(c(
      median(y[1:(length(y) / 2)]),
      median(y),
      median(y[(length(y) / 2 + 1):length(y) + 1])
    ))
  }
}
cat(paste(quartiles(x), collapse = "\n"), "\n")
