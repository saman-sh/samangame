#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>

bool Indexer()
{
    char fldr, file;
    int fldrInt = 0, fileInt = 0;
    std::string str = "";
    std::stringstream ss;
    std::ifstream finDic;
    std::ofstream foutIndx;
    finDic.open("DictionaryMain.txt");

    int t = 0;

    while (getline(finDic, str))
    {
        fldr = str[0];
        file = str[1];
        fldrInt = fldr;
        fldrInt -= 96;
        fileInt = file;
        fileInt -= 96;
        ss << "./" << fldrInt << "/" << fileInt;
        foutIndx.open(ss.str(), std::ofstream::ate | std::ofstream::app);
        ss.str(std::string());
        ss.clear();
        foutIndx << str << "\n";
        foutIndx.close();
        str = "";
    }
    finDic.close();
    foutIndx.close();
    ss.str(std::string());
    ss.clear();
    return true;
}

inline std::string PathFinder(std::string s)
{
    std::string fldr, file;
    int tmpNum = 0;
    std::stringstream ss;
    char flttr, slttr;
    flttr = s[0];
    slttr = s[1];

    ss << static_cast<int>(flttr);
    tmpNum = std::stoi(ss.str());
    ss.str(std::string());
    ss.clear();
    tmpNum -= 96;
    ss << tmpNum;
    fldr = ss.str();

    ss.str(std::string());
    ss.clear();
    ss << static_cast<int>(slttr);
    tmpNum = std::stoi(ss.str());
    ss.str(std::string());
    ss.clear();
    tmpNum -= 96;
    ss << tmpNum;
    file = ss.str();

    ss.str(std::string());
    ss.clear();

    ss << "./" << fldr << "/" << file;

    return ss.str();
}

int main()
{
    bool anagrmFound = false, anagrm0Flg = false, blkListChk = false, indxrDone = false;

    std::ifstream finPool, finPermut;

    std::stringstream anagramsTmp;

    FILE *fp;

    fp = fopen("Anagrams.txt", "w+");

    std::vector<std::string> blkList;
    blkList.clear();

    std::string src = "";
    std::string permut = "";
    std::string str = "";
    std::string path = "";

    indxrDone = Indexer();
    if (indxrDone)
    {
        std::cout<<"Indexing is now finished!\n";
        finPool.open("DictionaryMain.txt");

        while (std::getline(finPool, src))
        {

            if (src.length() > 2 && src.length() < 10)
            {

                for (unsigned int t = 0; t < blkList.size(); ++t)
                {
                    if (src == blkList.at(t))
                    {
                        blkListChk = true;
                        break;
                    }
                }

                if (!blkListChk)
                {
                    permut = src;
                    std::sort(permut.begin(), permut.end());
                    do
                    {
                        path = PathFinder(permut);
                        finPermut.open(path);
                        while (std::getline(finPermut, str))
                        {
                            if (str == permut && str != src)
                            {
                                anagrmFound = true;

                                if (!anagrm0Flg)
                                {
                                    anagrm0Flg = true;
                                    anagramsTmp << src << "/" << permut << "/";
                                    std::cout << src << "/" << permut << "/";
                                }
                                else
                                {
                                    anagramsTmp << permut << "/";
                                    std::cout << permut << "/";
                                }

                                blkList.push_back(src);
                                blkList.push_back(permut);
                            }
                        }
                        finPermut.close();
                        finPermut.clear();
                        str = "";

                    } while (std::next_permutation(permut.begin(), permut.end()));

                    if (anagrmFound)
                    {
                        anagramsTmp << "\n";
                        std::cout << "\n";
                    }
                    anagrmFound = false;
                    anagrm0Flg = false;
                    src = "";
                    permut = "";
                }

                blkListChk = false;
            }
        }

        finPool.close();

        fputs(anagramsTmp.str().c_str(), fp);

        fclose(fp);
        blkList.clear();
        std::vector<std::string>(blkList).swap(blkList);
    }
    else
        std::cout << "Error in Indexing Dictionary.";
    return 0;
}

