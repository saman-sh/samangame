# samangame
[online brain/mind games]
In this package there is a bash sript and a c++ program that I wrote to generate a list of all possible anagrams (in this code maximum of 8 letter words because of my CPU limitaions but it can be changed in code) in English dictionary (or any other language if dictionary provided).
I used this word list as my dataset: An English Word List by John M. Lawler [http://www-personal.umich.edu/~jlawler/wordlist.html].

Operating system:
I used linux/Ubuntu making this and for preparation part that includes bash scripts, a linux based system is needed or you can use Cygwin or any other tool to do the preparation part on Windows 10.

USAGE:
First, make a new folder and copy the files into it and give permission to them so that you can compile and run them. Then run preparation bash script (preparation.sh).
This might take few minutes depending on speed of your system.
Second, compile the c++ code (Anagrams.cpp) note that c++11 should be available on your system, type this command on the terminal:
$ g++ Anagrams.cpp -std=c++11
then just run the executable (a.out).

Requirements:
* Ubuntu (or any Linux distro).
* C++11
* su authority to change permission of preparation script (.sh).

Note:
Preparion script actually is for indexing the dictionary (based on first two letters) to make search and comparison faster.

Future work:
Using Pthread library in c++ code to make it run faster.
