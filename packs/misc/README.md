Miscellaneous utilities.

* **defer**: Delays running specified code until the end of current scope.
  Code can be executed unconditionaly (`defer`), only when exception was thrown (`defer_fail`) or not (`defer_success`).
  You can also name a defer object using versions with -`_named` suffixes.
