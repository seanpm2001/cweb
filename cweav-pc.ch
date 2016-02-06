This is the change file for CWEB's CWEAVE under DOS
(Contributed by Lee Wittenberg, March 1993)

Changes necessary for compiling with Borland C/C++
Use compilation switches -mc -w-pro -Ff=5000

Note: The changes to section 4 are not necessary if using a compiler
that allows >64K arrays.

@x section 1
@d banner "This is CWEAVE (Version 3.0)\n"
@y
@d banner "This is CWEAVE (Version 3.0pc)\n"
@z

@x section 4
@d max_bytes 90000 /* the number of bytes in identifiers,
@y
@d max_bytes (unsigned)60000 /* the number of bytes in identifiers,
@z
@x
@d max_refs 20000 /* number of cross-references; must be less than 65536 */
@y
@d max_refs 10000 /* number of cross-references; must be less than 65536 */
@z
