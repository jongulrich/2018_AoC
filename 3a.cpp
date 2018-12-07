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

/*


--- Day 3: No Matter How You Slice It ---
The Elves managed to locate the chimney-squeeze prototype fabric for Santa's suit (thanks to someone who helpfully wrote its box IDs on the wall of the warehouse in the middle of the night). Unfortunately, anomalies are still affecting them - nobody can even agree on how to cut the fabric.

The whole piece of fabric they're working on is a very large square - at least 1000 inches on each side.

Each Elf has made a claim about which area of fabric would be ideal for Santa's suit. All claims have an ID and consist of a single rectangle with edges parallel to the edges of the fabric. Each claim's rectangle is defined as follows:

The number of inches between the left edge of the fabric and the left edge of the rectangle.
The number of inches between the top edge of the fabric and the top edge of the rectangle.
The width of the rectangle in inches.
The height of the rectangle in inches.
A claim like #123 @ 3,2: 5x4 means that claim ID 123 specifies a rectangle 3 inches from the left edge, 2 inches from the top edge, 5 inches wide, and 4 inches tall. Visually, it claims the square inches of fabric represented by # (and ignores the square inches of fabric represented by .) in the diagram below:

...........
...........
...#####...
...#####...
...#####...
...#####...
...........
...........
...........
The problem is that many of the claims overlap, causing two or more claims to cover part of the same areas. For example, consider the following claims:

#1 @ 1,3: 4x4
#2 @ 3,1: 4x4
#3 @ 5,5: 2x2
Visually, these claim the following areas:

........
...2222.
...2222.
.11XX22.
.11XX22.
.111133.
.111133.
........
The four square inches marked with X are claimed by both 1 and 2. (Claim 3, while adjacent to the others, does not overlap either of them.)

If the Elves all proceed with their own plans, none of them will have enough fabric. How many square inches of fabric are within two or more claims?

*/





