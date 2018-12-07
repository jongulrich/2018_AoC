#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map> 


unsigned int difference(std::string s1,  std::string s2)
{
    int size = s1.size();
    unsigned int diff = 0;
    for (int i = 0; i < size; i++)
    {
        if (s1[i] != s2[i])
        {
            diff++;
        }
    }
  
    return diff;
}

int main()
{

    std::vector<std::string> inputVector;
    std::ifstream inputFile("2.txt");
    
    if (inputFile)
    {
        std::string line;
        while (std::getline(inputFile, line))
        {
            inputVector.push_back(line);
            std::cout << line << std::endl;
        }

        int total_2x = 0;
        int total_3x = 0;
        

        std::string saveString1 = "nope1";
        std::string saveString2 = "nope2";
        unsigned int saveDistance = 999999999;

        for (std::vector<std::string>::iterator it = inputVector.begin() ; it != inputVector.end(); ++it)
        {

            if (std::next(it) == inputVector.end())
            break;

            std::string string1;
            std::string string2;
            string1 = *it;

            for (std::vector<std::string>::iterator it2 = inputVector.begin() ; it2 != inputVector.end(); ++it2)
            {

                if (std::next(it2) == inputVector.end() || it2 == it)
                continue;

                string2 = *it2;
                
                unsigned int tmpDis = difference(string1, string2);
                if (tmpDis < saveDistance)
                {
                    saveString1 = string1;
                    saveString2 = string2;
                    saveDistance = tmpDis;
                }
            }
        }

        std::cout << "saveString1: " << saveString1 << std::endl;
        std::cout << "saveString2: " << saveString2 << std::endl;
        std::cout << "saveDistance: " << saveDistance << std::endl;

        int stringLength1 = saveString1.length();
        int stringLength2 = saveString2.length();

        std::string finalString = "";
        for (int i = 0; i < stringLength1 && i < stringLength2; i++)
        {
            
            if (saveString1[i] == saveString2[i])
            {
                finalString = finalString + saveString1[i];
            }
            else
            {
                std::cout << "removed letter[" << i << "]: " << saveString1[i] << " vs " << saveString2[i] << std::endl;
            }
            
        }

        std::cout << "finalString: " << finalString << std::endl;
       
    }

    return 0;
}







