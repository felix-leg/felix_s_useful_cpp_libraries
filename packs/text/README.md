Functions to work with strings. Divided into sub-modules, that can be included independently of each other.

Basic modules:
* **join**: Joining elements of an iterable object into one string, with a separator in-between.
* **convert**: Conversion between UTF-32 and UTF-8 strings. Also, on MS Windows, there are conversion functions from wide char to narrow and vice versa.
* **split**: A reverse operation to *join*. Splits a string on a given separator into a vector.
* **just**: String left/right/center justification.

Used internaly:
* **db**: Database of character properties. *Warning:* a big (140957 lines) file!
* **unicode**: Small file of some unicode properties.

Below modules has each versions working with ASCII, UTF-8 or UTF-32 encoded strings:
* **checks**: Tests if a character belongs to a class of characters.
* **case**: Conversion of a character/string to lower/upper/title case.
* **trim**: Removes whitespaces from left, right or both ends of a string.
