#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>


inline std::string pathFinder(std::string s)
{
std::string fldr,file;
int tmpNum=0;
std::stringstream ss;
char flttr,slttr;
flttr=s[0];
slttr=s[1];

ss << static_cast<int>(flttr);
tmpNum=std::stoi(ss.str());
ss.str(std::string());
ss.clear();
tmpNum-= 96;
ss<<tmpNum;
fldr=ss.str();

ss.str(std::string());
ss.clear();
ss << static_cast<int>(slttr);
tmpNum=std::stoi(ss.str());
ss.str(std::string());
ss.clear();
tmpNum-= 96;
ss<<tmpNum;
file=ss.str();

ss.str(std::string());
ss.clear();

ss << "./" <<fldr<<"/"<<file;


return ss.str();

}


int main()
{
bool anagrmFound=false,anagrm0Flg=false,blkListChk=false;
//bool anagrm0Flg=false;
//bool blkListChk=false;
std::ifstream finPool,finPermut;

std::stringstream anagramsTmp;

FILE *fp;

fp = fopen("Anagrams.txt", "w+");


 std::vector<std::string> blkList;
 blkList.clear();


std::string src="";
std::string permut="";
std::string str="";
std::string path="";

finPool.open("DictionaryMain.txt");

while(std::getline(finPool,src))
{
if(src.length()>2 && src.length()<10)
{

 for(int t=0;t<blkList.size();++t)
	{
           if(src==blkList.at(t))
	   {
		blkListChk=true;
		break;
	   }

        }

if(!blkListChk)
{
permut=src;

std::cout<<src<<"\n";
std::sort(permut.begin(), permut.end());
 do
 {
	path=pathFinder(permut);
	finPermut.open(path);
	while(std::getline(finPermut,str))
	{
	if(str==permut && str!=src)
	{
	anagrmFound=true;

	if(!anagrm0Flg)
	{
	anagrm0Flg=true;
	anagramsTmp << src << "/" << permut << "/";
	std::cout<< src << "/" << permut << "/";
	}
	else
	{
	anagramsTmp <<permut << "/";
	std::cout<<permut << "/";
	}

	blkList.push_back(src);
	blkList.push_back(permut);

	}
	}
 	finPermut.close();
 	finPermut.clear();
 	str="";
 	
 }
 while(std::next_permutation(permut.begin(), permut.end()));

if(anagrmFound)
{
anagramsTmp <<"\n";
std::cout<<"\n";
}
anagrmFound=false;
anagrm0Flg=false;
src="";
permut="";

}

blkListChk=false;
}
}

finPool.close();

fputs(anagramsTmp.str().c_str(), fp);

fclose(fp);
blkList.clear();
std::vector<std::string>(blkList).swap(blkList);
return 0;

}
