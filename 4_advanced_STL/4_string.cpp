// somte string features
#include <iostream>
using namespace std;
#include <algorithm>

int main()
{
    string s1 = "hello";
    string s2 = "world";
    string s3(10,'a');
    string s4 = s1+" "+s2;
    string s5 = s1.append(" "+s2);          
    string s6 = s1.insert(0, " "+s2); 
    string s7 = s1.replace(0, 1, "H");   // replace the first 1 chars with "H"
    string s8 = s1.erase(0, 1);         // erase the first 1 chars
    string s9 = s1.substr(0, 1);        // s1.substr(start, length)
    int pos1 = s1.find("o");           // find the first o in s1, return the index of o
    int pos2 = s1.rfind("o");         // find the last o in s1, return the index of o

    // one practical useful command
    string s11 = "lishoushou2019@gmail.com";
    string s12 = "chenrourou2020@gmail.com";
    string s13 = s11.substr(0, s11.find("@")); // get the username from s11
    string s14 = s12.substr(s12.find("@")+1); // get the domain from s11
}