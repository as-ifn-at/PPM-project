#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {

    ifstream image;
    ofstream newimage;
    image.open("land.ppm");
    newimage.open("newimage.ppm");
    string type="", width="",height="",RGB="";
    image>>type;
    image>>width;
    image>>height;
    image>>RGB;

    newimage<<type<<endl;
    newimage<<width<<" "<<height<<endl;
    newimage<<RGB<<endl;
    string red="",green="",blue="";
    int r=0, g=0, b=0;
    while(!image.eof()) {
        image>>red;
        image>>green;
        image>>blue;
        r=stoi(red);
        g=stoi(green);
        b=stoi(blue);
        int avg=(r+g+b)/3;
        r=g=avg;
        
        newimage<<r<<" "<<g<<" "<<b<<endl;
    }
    image.close();
    newimage.close();
    return 0;
}