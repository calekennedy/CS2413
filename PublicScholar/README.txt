#### Administrative Remark ####
If you are a student at the University of Oklahoma (or any other university),
please feel free to use the code in this repo.
I do not care what you do with it.
Hopefully it will help you better understand the subject matter in the course,
or at the very least give you a template to work against.
However, you must (and I cannot stress this enough) credit this source.
I am not being self-interested when I say this.
Failure to credit me for any of the code you use is considered academic misconduct,
and may carry a penalty of expulsion. 
[OU academic misconduct information](http://integrity.ou.edu/)

As always, keep coding. :)


---


This solution should come ready to roll.

You can run this project using the "Local Windows Debugger"

There is an input file located at "../infile.bib" from the executable

There is a pre-existing mergefile at "../mergefile.bib" from the executable

Everything should conform to project specifications

---

CHANGES TO ENVIRONMENT CONFIGURATION!!!

The environment should be configured as follows 

Navigate in Visual Studio to

Debug > PublicScholar Properties > Configuration Properties > Debugging > Command Arguments

project_2: This field should be blank.

This will allow the "Local Windows Debugger" to run the project.

project_2: File reading is performed via dynamic user input. File paths are relative.
			I have included an input file "infile.bib" and merge file "mergefile.bib"
			Their filepaths are one directory up from the executable,
			e.g., "../infile.bib" will be the correct input to load the pre-existing
			input file at runtime

project_2: File output is determined by dynamic user input. Once again, filepaths are relative.
		   I recommend prepending ../"filepath"."ext" as it places the file in the root folder, 
		   making it easier to find.
		   However, you may name it whatever you like and locate it anywhere.

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
Linked List

If any thing is broken in these data structures, it is likely my fault 
(due to adapting them to fit the specific needs of my program) 
and should not reflect poorly on the original authors.

#### Additional Comments ####

I kept getting linker errors for all primitive, inherited data-structure classes.
They were all previously split into .cpp and .h files.
This seems to have been the source of the linker errors.
Now, these objects have their entire class body in their respective header files. 
This seems to have fixed the problem. 

Prior to making these changes, which seem to violate best practice,
I consulted with Dr. Hougen and we weren't able to identify the problem.
This solution appears to violate best practices, but it works.

#keepcoding