# C Note

This is a mock-banking program utilizing a bootstrapped linked list composed of struct records.
The data held in the record can be viewed in the record.h file.  I learned a great deal about working
with memory management between the stack and heap.  During the process I gained a true appreciation for the function-debugging
methodology of memory tracing during the creation of this project. 

## Testing summary

The test plan consisted of a series of 34 tests.  This document contains the
outcomes of each group of tests, i.e., function tests, start up tests, etc...

Each possible start up to the program was tested to ensure correct functionality.
This included running the program with too many arguments, incorrect arguments, as well
as the correct usages.  All of these tests were considered successful.  When the
user attempted any command line arguments other than the ./<program name> or
./<program name> debug, the correct error messages were displayed.  When the user
ran the program without the debug argument, no debug data was displayed.  On the other
hand when the debug command was included, debug data was neatly displayed to the user.

The add record function was tested exhaustively.  This was in conjunctions with the
print all records function, to ensure that correct functionality was resulting from
adding records.  The add record function was tested with no account number, and the
correct error message was displayed.  Adding a record was attempted with the correct
format for an account, but with either no name or no address.  This same test was
also performed against a name and/or address exceeding the char[] length of the
particular data value.  Both instances were a success, the attempt to add the record
was rejected and the appropriate error message was clearly printed to the user.
When records were added, repeating accounts were accepted.  Adding records into the
list resulted in a sorted list based on the account number as the sorting criteria.
Tests were done to ensure proper ordering of the list, with records added to the
beginning, middle and end resulting in the desired outcome.

In regards to the print all records, testing was done when no records existed in
the system, when a single record existed, and also when multiple records existed.
In all instances the desired output was seen.  A message was displayed to the user
when the linked list was empty, and the records where printed in order by account
number when there was more than one account.

Printing a single record was tested under four scenarios: There existed no records
in the system, there existed records in the system with no matching account number,
out of all records there existed a single record with a matching account number,
there existed multiple records with matching account numbers.  Under all scenarios
the print record function operated to standard and no abnormalities were observed.

Finally, the delete record was tested very similarly to that of the print record
function.  In every instance the delete record did its job very well.  If multiple
records with identical account numbers existed, all were removed.  If no records
existed, an error was displayed to the user. A single match resulted in a single
record deletion.  If no match occurred, this result was displayed to the user.

Testing was carried out for the read and writefile functions.  The program runs as
normal if no records text file exists.  If the file does exist, records are added
to the linked list by means of the add record function.  Upon exiting the program,
the records text file is written over with the current linked list data, replacing
all previous data.  Both functions were tested with no records, one record, as well
as multiple records.  In all instances, the results were satisfying.There is also
a print menu options option, but that did not require much testing.

Throughout running all of these tests, the debug was utilized.  Working efficiently
and showing meta data for every function existing within the program.  Whenever a
function is called the debug information is shown in a comment like block that is
easily distinguishable from the actual program text being output to the screen.
Multiple series pertaining to each set of tests were performed, and the program is
determined to be stable. 
