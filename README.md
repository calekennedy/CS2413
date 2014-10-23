# CS 2413 - Intro to Data Structures 

VS2013 or newer is required to run this project (blame academia).

---

## Administrative Remark 

If you are a student at the University of Oklahoma (or any other university), please feel free to use the code in this repo. I do not care what you do with it. Hopefully it will help you better understand data structures and C++,
or at the very least give you a template to work against. However, if you are attending the University of Oklahoma, you must (and I cannot stress this enough) credit this source. I am not being self-interested, failure to provide credit is considered academic misconduct.

#### Academic Misconduct charges may be brought against any student who fails to properly credit their sources.
#### Many penalties are possible when a student is found guilty of an act of academic misconduct, including expulsion.
#### Please do not jeopardize your academic career.

[University of Oklahoma academic integrity information](http://integrity.ou.edu/)

As always, keep coding. :)


---

## How to run

This solution should come ready to roll.

You can run this project using the "Local Windows Debugger" in VS2013.

There is an input file located at "../infile.bib" (relative to the executable)

There is a pre-existing mergefile at "../mergefile.bib" (relative to the executable)

Everything should conform to project specifications found [here](http://www.cs.ou.edu/~hougen/classes/Fall-2014/DataStructures/materials/assignments.html).

---

## Specifics

File reading is performed via dynamic user input. File paths are relative. 
I have included an input file "infile.bib" and merge file "mergefile.bib"
They are located in the root directory (one directory up from the executable).
E.g., if you would like to use the pre-existing input file at runtime, "../infile.bib" will be the correct input.

File output is determined by dynamic user input. Once again, filepaths are relative.
I recommend using a filepath of the following form: "../filepath.ext". This places the file in the root folder, making it easier to find. However, you may name it whatever you like and locate it anywhere.

My code *should* be self documenting. Where I thought it was not clear I left comments.
Public methods have good documentation, private methods a good deal less.
Header files explicitly state the intended functionality of methods, especially those which are exposed.
Source files are less heavily documented, as they should not be the concern of the end user.
All of my code uses the [single responsibility principle](http://en.wikipedia.org/wiki/Single_responsibility_principle) to allow "black box" interfacing, reusability, and easier modifications.

---

## Credits and Thanks

Many of the objects and classes in this project are either directly copied from, or were heavily influenced by the lecture slides in Dr. Hougen's Data Structure Course and/or Dr. Radhakrishnan's book on Data Structures. For this reason, much of the credit for the underlying data structures libraries should go to them.

Non-Exhaustive list of objects and classes with some or all credit due to the above persons:
Abstract Array
Abstract Vector
Vector
Array
String
Linked List

If any thing is broken in these data structures, it is likely my fault (due to adapting them to fit the specific needs of my program) and should not reflect poorly on the original authors.

---

#### Additional Comments

I kept getting linker errors for all primitive, inherited data-structure classes.
They were all previously split into .cpp and .h files.
This seems to have been the source of the linker errors.
Now, these objects have their entire class body in their respective header files. 
This seems to have fixed the problem. 

Prior to making these changes, which seem to violate best practice,
I consulted with Dr. Hougen and we weren't able to identify the problem.
This solution appears to violate best practices, but it works.

#keepcoding
