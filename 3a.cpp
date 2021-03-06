#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map> 
#include <algorithm>
#include <cstring>

typedef struct Pair
{
    int x;
    int y;

} Pair;

class Fabric
{

public:
        Fabric() {
            id = 0;   
            origin.x = 0;        
            origin.y = 0;        
            width = 0;   
            height = 0;   
            destination.x = 0;
            destination.y = 0;
        };

        Fabric(std::string str) { 
          populateObject(str);
        };
    
//lazy
        int id;
        Pair origin;
        int width;
        int height;
        Pair destination;
private:

        void populateObject(std::string str)
        {
           //e.g. #22 @ 466,752: 28x14 
           sscanf ((char*)str.c_str(), "#%d @ %d,%d: %dx%d ", &id, &origin.x, &origin.y, &width, &height);
           destination.x = origin.x + width - 1;
           destination.y = origin.y + height - 1;
        }
             
        
};

std::ostream &operator<<(std::ostream &os, Fabric const &f) { 
    os <<"#(ID) = " << f.id << ", origin(" << f.origin.x << "," << f.origin.y << "), width=" << f.width << ", length=" << f.height << ", destination("<<f.destination.x << ","<< f.destination.y <<")";
}

int getOverlapAmount(Fabric f1, Fabric f2)
{
    int squareInchesOfOverlap = 0;

    int x_overlap = std::max(0, std::min(f1.destination.x, f2.destination.x) - std::max(f1.origin.x, f2.origin.x));
    int y_overlap = std::max(0, std::min(f1.destination.y, f2.destination.y) - std::max(f1.origin.y, f2.origin.y));
    squareInchesOfOverlap = x_overlap * y_overlap;

    return squareInchesOfOverlap;
}

int main()
{

    std::vector<Fabric*> inputVector;
    std::ifstream inputFile("3.txt");
    
    if (inputFile)
    {
        std::string line;

        int maxWidth = 0;
        int maxHeight = 0;
        int overlapCount = 0;


        while (std::getline(inputFile, line))
        {
            Fabric *ent = new Fabric(line);
            std::cout << line << std::endl;

            inputVector.push_back(ent);
            std::cout << *ent << std::endl;
            if (maxWidth < (ent->origin.x + ent->width))
                maxWidth = 1+ ent->origin.x + ent->width;

            if (maxHeight < (ent->origin.y + ent->height))
                maxHeight = 1 + ent->origin.y + ent->height;
        }



        unsigned int fabricMap[maxWidth][maxHeight];
        std::memset(fabricMap, 0, sizeof (fabricMap[0][0]) * maxWidth * maxHeight);
        
        for (auto& it : inputVector) {
            std::cout << *it << std::endl;

            for (int i = it->origin.x; i <= it->destination.x; i++)
            {
                for (int j = it->origin.y; j <= it->destination.y;j++)
                {
                   fabricMap[i][j]++;
                   std::cout << "added ("<<i<< "," <<j<<")" << std::endl;
                }
            }
        }

        
        for(int i = 0; i < maxWidth;i++)
        {
            for(int j = 0; j < maxHeight;j++)
            {
                if (fabricMap[i][j] > 1)
                {
                    std::cout << "Overlap ("<<i<< "," <<j<<")" << std::endl;
                    overlapCount++;
                }
            }
        }

        std::cout << "Number of Square Inches Overlapping: " << overlapCount << std::endl;
    }

    return 0;
}

/*


--- Day 3: No Matter How You Slice It ---
The Elves managed to locate the chimney-squeeze prototype fabric for Santa's suit 
(thanks to someone who helpfully wrote its box IDs on the wall of the warehouse in the middle of the night). 
Unfortunately, anomalies are still affecting them - nobody can even agree on how to cut the fabric.

The whole piece of fabric they're working on is a very large square - at least 1000 inches on each side.

Each Elf has made a claim about which area of fabric would be ideal for Santa's suit. All claims have an ID 
and consist of a single rectangle with edges parallel to the edges of the fabric. Each claim's rectangle is defined as follows:

The number of inches between the left edge of the fabric and the left edge of the rectangle.
The number of inches between the top edge of the fabric and the top edge of the rectangle.
The width of the rectangle in inches.
The height of the rectangle in inches.
A claim like #123 @ 3,2: 5x4 means that claim ID 123 specifies a rectangle 3 inches from the left edge, 
2 inches from the top edge, 5 inches wide, and 4 inches tall. Visually, it claims the square inches of 
fabric represented by # (and ignores the square inches of fabric represented by .) in the diagram below:

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





