#include <sstream>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class zmiana{
       ifstream plik1;
       ofstream plik2;

  public:
        zmiana();
        ~zmiana();
       
        void zmien();        
};

zmiana::zmiana(){ 
    plik1.open("c:\\palindromy.txt");
    plik2.open("c:\\wynikJSON.txt");
}

void zmiana::zmien(){
    string napis; 
    string s(), slowo, polacz("");
	
	plik2<<"[";
	
    while(!plik1.eof()){ 
        getline(plik1,napis);
        
        for(int i = 0; i<napis.length(); i++){
        	if(napis[i]>64&&napis[i]<91)
            napis[i] += 32;           
        }
        
        
        
        stringstream ss(napis);
        while(ss >> slowo) 
                polacz += slowo; 
        
        int end = polacz.length()-1; 
        bool isPalindrome = true; 
        string oR;
        
        for (int i=0; i<polacz.length()/2 && isPalindrome; i++) 
            if (polacz[i] != polacz[end--]) 
                    isPalindrome = false;
        
        if(isPalindrome)
            oR = "Tak";
	else
	    oR = "Nie";
	
        
        plik2<<"{\"string\":"<<"\""<<polacz<<"\""<<","<<"\"palindrom\":"<<"\""<<oR<<"\"},";
        
        polacz="";
        
    
                   
    }
    plik2<<"]";
}


zmiana::~zmiana(){
    plik1.close();
}

int main() {
    zmiana change; 
    change.zmien(); 
    return 0;
}
