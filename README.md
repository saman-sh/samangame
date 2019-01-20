# samangame
[online brain/mind games]
In this package there is a bash script and a c++ program that I wrote to generate a list of all possible anagrams in English dictionary (in this code maximum of 9 letter words because of my CPU limitations but it can be changed in the code).
I used this word list as my dataset: An English Word List by John M. Lawler [http://www-personal.umich.edu/~jlawler/wordlist.html].

Operating system:
I used Linux/Ubuntu making this and for preparation part that includes bash scripts, a Linux based system is needed or you can use Cygwin or any other tool to do the preparation part on Windows 10.

USAGE:
First, clone or download and make a new folder and copy the files into it then give permission to bash script file so that you can run it. Then run preparation bash script (preparation.sh).
Second, compile the c++ code (Anagrams.cpp) note that c++11 should be available on your system, type this command on the terminal:
$ g++ Anagrams.cpp -std=c++11
then just run the executable (a.out). It will index the dictionary/word list (based on first two letters) to make search and comparison faster and then after a while! according to the processing capacity of your system, final results (list of anagrams with length between 3 and 9 letters in English dictionary) will be available in a text file (Anagrams.txt).

Requirements:
* Ubuntu (or any Linux distro).
* C++11
* su authority to change permission of preparation script (.sh).

Note:
Word-list/dictionary can be in any other language with some changes in bash script -number of letters in its alphabet and subsequently number of folders and files to be created - and C++ code - using Unicode for non-English dictionary.

Future work:
* Using thread library in c++11 to make program run faster.
* adding new word-lists/dictionaries to project and needed modifications in bash script and C++ code to fit them.
