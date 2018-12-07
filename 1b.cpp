#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map> 

int main()
{

    std::vector<int> inputVector;
    std::ifstream inputFile("1.txt");
    
    if (inputFile)
    {
        std::string line;
        while (std::getline(inputFile, line))
        {
            int val = std::stoi( line );
            inputVector.push_back(val);
            //std::cout << line << ":" << val << std::endl;
        }

 
        int currentFrequency = 0;
        std::map<int, bool> frequencyMap;

        for (std::vector<int>::iterator it = inputVector.begin() ; it != inputVector.end(); )
        {

            currentFrequency += *it;

            std::cout << "" << *it << std::endl;

            if (frequencyMap.find(currentFrequency) != frequencyMap.end()) {
                std::cout << "Found this frequency again: " << currentFrequency << std::endl;
                break;
            } else {
                std::cout << "First time seeing: " << currentFrequency << std::endl;

                frequencyMap.insert( std::pair<int,bool>(currentFrequency,true));
            }
            
            if (std::next(it) == inputVector.end())
            {
                it = inputVector.begin();
            }
            else
            {
                ++it;
            }

        }

        std::cout << "Current Frequency: " << currentFrequency << std::endl;
    }

    return 0;
}


/*

--- Part Two ---
You notice that the device repeats the same frequency change list over and over. To calibrate the device, you need to find the first frequency it reaches twice.

For example, using the same list of changes above, the device would loop as follows:

Current frequency  0, change of +1; resulting frequency  1.
Current frequency  1, change of -2; resulting frequency -1.
Current frequency -1, change of +3; resulting frequency  2.
Current frequency  2, change of +1; resulting frequency  3.
(At this point, the device continues from the start of the list.)
Current frequency  3, change of +1; resulting frequency  4.
Current frequency  4, change of -2; resulting frequency  2, which has already been seen.
In this example, the first frequency reached twice is 2. Note that your device might need to repeat its list of frequency changes many times before a duplicate frequency is found, and that duplicates might be found while in the middle of processing the list.

Here are other examples:

+1, -1 first reaches 0 twice.
+3, +3, +4, -2, -4 first reaches 10 twice.
-6, +3, +8, +5, -6 first reaches 5 twice.
+7, +7, -2, -7, -4 first reaches 14 twice.
What is the first frequency your device reaches twice?
*/






