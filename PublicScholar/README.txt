This solution should come ready to roll.

CHANGES TO ENVIRONMENT CONFIGURATION!!!

The environment should be configured as follows 

Navigate in Visual Studio to

Debug > PublicScholar Properties > Configuration Properties > Debugging > Command Arguments

project_0: This field should contain the value " < ../infile.bib > ../outfile.bib" (without quotes) 
project_1: This field should be blank.

This will allow the "Local Windows Debugger" to run the project.

project_0: The file we are reading in is called infile.bib (it is the file from the course website)
project_1: File reading is performed via dynamic user input. File paths are relative.

project_0: The file we are outputting is called outfile.bib.
project_1: File output is determined by dynamic user input. Once again, filepaths are relative.
		   I recommend prepending ../"filepath"."ext" as it places the file in the root folder, 
		   making it easier to find.

project_0: outfile.bib is located in the root directory of the visual studio project folder.
project_1: you will now be able to name and relocate this file.

Code should be self documenting, and where it is not clear there will be comments.
Public methods have good documentation, private methods have less.
Header files explicitly state the intended functionality of methods.
Source files are less heavily documented, as they should not be the concern of the end user.
Code uses single responsibility principle to allow "black box" interfacing.

CREDIT:

Many of the objects and classes in this project are either directly copied from,
or were heavily influenced by the lecture slides in Dr. Hougen's Data Structure Course
and/or Dr. Radhakrishnan's book on Data Structures. For this reason, much of the credit
for the underlying data structures libraries should go to them.

Non-Exhaustive list of objects and classes with some or all credit due to the above persons:
Abstract Array
Abstract Vector
Vector
Array
String

If any thing is broken in these data structures, it is likely my fault due to adapting them to
fit the specific needs of my program and should not reflect poorly on the original authors.

#### Additional Comments ####

I kept getting linker errors for Array, Vector, and String classes.
They were all previously split into .cpp and .h files.
This seems to have been the source of the error.
Now, Array and Vector have their entire class body in their respective header files. 
This seems to have fixed the problem. 

Prior to making these changes, which seem to violate best practice,
I consulted with Dr. Hougen and we weren't able to identify the problem.

It could have been a multiple inheritance issue, but I didn't have time to check, 
as I am already submitting this project 2 hours late.

Either way, it's working now.