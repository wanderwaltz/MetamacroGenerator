MetamacroGenerator
==================

A command-line tool which allows generating metamacros.h similar to the one included in [extobjc](https://github.com/jspahrsummers/libextobjc) library with variable limit on arguments count.

Usage:

    ./MetamacroGenerator -limit 25 > output.h

Prints the generated metamacros.h with arguments limit 25 into a file named `output.h`. Default limit value is 20 as per original metamacros.h from [extobjc](https://github.com/jspahrsummers/libextobjc). Limit cannot be set to less than 20.
