#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map> 

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
        
        for (std::vector<std::string>::iterator it = inputVector.begin() ; it != inputVector.end(); ++it)
        {
            std::map<char, int> stringMap;
            std::string currentString = *it;

            int stringLength = currentString.length();

            for (int i = 0; i < stringLength; i++)
            {
     
                if (stringMap.find(currentString[i]) != stringMap.end()) {

                    stringMap.insert( 
                                        std::pair<char,int>(currentString[i],stringMap.find(currentString[i])->second++) 
                                    );

                    std::cout << "Found this character before: " << currentString[i] << "(" << stringMap.find(currentString[i])->second << ")" << std::endl;

                } else {

                    std::cout << "First time seeing: " << currentString[i] << std::endl;

                    stringMap.insert( std::pair<char,int>(currentString[i],1));
                }
            }

            
            bool has2x = false;
            bool has3x = false;
            for (std::map<char, int>::iterator it = stringMap.begin() ; it != stringMap.end(); ++it)
            {
                if (it->second == 2)
                    has2x = true;

                if (it->second == 3)
                    has3x = true;

                //if (has2x && has3x) maybe optimize
                //    break;
            }

            if (has2x) total_2x++;
            if (has3x) total_3x++;
             
        }
        
        int hash = total_2x * total_3x;

        std::cout << "Total (2x) = " << total_2x << std::endl;
        std::cout << "Total (3x) = " << total_3x << std::endl;       
        std::cout << "Hash       = " << hash << std::endl;
       
    }

    return 0;
}


/*

--- Day 2: Inventory Management System ---
You stop falling through time, catch your breath, and check the screen on the device. "Destination reached. Current Year: 1518. Current Location: North Pole Utility Closet 83N10." You made it! Now, to find those anomalies.

Outside the utility closet, you hear footsteps and a voice. "...I'm not sure either. But now that so many people have chimneys, maybe he could sneak in that way?" Another voice responds, "Actually, we've been working on a new kind of suit that would let him fit through tight spaces like that. But, I heard that a few days ago, they lost the prototype fabric, the design plans, everything! Nobody on the team can even seem to remember important details of the project!"

"Wouldn't they have had enough fabric to fill several boxes in the warehouse? They'd be stored together, so the box IDs should be similar. Too bad it would take forever to search the warehouse for two similar box IDs..." They walk too far away to hear any more.

Late at night, you sneak to the warehouse - who knows what kinds of paradoxes you could cause if you were discovered - and use your fancy wrist device to quickly scan every box and produce a list of the likely candidates (your puzzle input).

To make sure you didn't miss any, you scan the likely candidate boxes again, counting the number that have an ID containing exactly two of any letter and then separately counting those with exactly three of any letter. You can multiply those two counts together to get a rudimentary checksum and compare it to what your device predicts.

For example, if you see the following box IDs:
																    (22:333)
abcdef contains no letters that appear exactly two or three times. 	(0 : 0)
bababc contains two a and three b, so it counts for both.			(1 : 1)
abbcde contains two b, but no letter appears exactly three times.	(1 : 0)
abcccd contains three c, but no letter appears exactly two times.	(0 : 1)
aabcdd contains two a and two d, but it only counts once.			(1 : 0)
abcdee contains two e.												(1 : 0)
ababab contains three a and three b, but it only counts once.		(0 : 1)
																	T(4:3)
Of these box IDs, four of them contain a letter which appears exactly twice, and three of them contain a letter which appears exactly three times. 
Multiplying these together produces a checksum of 4 * 3 = 12.

What is the checksum for your list of box IDs?



*/






