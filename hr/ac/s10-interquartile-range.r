stdin <- file("stdin")
open(stdin)

invisible(readLines(stdin, n = 1, warn = FALSE)) # Consumes line to ignore `n`
v <- as.integer(strsplit(trimws(
  readLines(stdin, n = 1, warn = FALSE), which = "both"), " ")[[1]])
f <- as.integer(strsplit(trimws(
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
inter_quartile <- function(v, f) {
  s <- c()
  for (i in seq_len(length(v))) {
    s <- c(s, rep(v[i], f[i]))
  }
  q <- quartiles(s)
  return(q[3] - q[1])
}
cat(sprintf("%.1f", inter_quartile(v, f)), "\n")
