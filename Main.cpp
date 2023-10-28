#include "BST.cpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void read (string& filename, BST <string, string> tree);
void read_from_file (ifstream& input, BST <string, string> tree);
void display(BST <string, string> tree);

int main()
{

BST <string, string> tree;
string filename = "New Text Document (2).txt";
read(filename, tree);
display(tree);

    



    return 0;
}
void read (string& filename, BST <string, string> tree)
{
      ifstream input;
      read_from_file(input, tree);
}
void read_from_file (ifstream& input, BST <string, string> tree)
{
    string  city, lat, longitude, country;
   while (input >> city >> lat >> longitude >> country)
   {
     tree.insert(city, lat, longitude, country);
   }
}
void display(BST <string, string> tree)
{
    tree.preorder();
}