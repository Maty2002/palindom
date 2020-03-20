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
    int licznik; 
    string napis; 
    string finalScore;
    string linia;
    char znak;
    string s(), slowo, polacz("");
	
	plik2<<"[";
	
    while(!plik1.eof()){ 
        getline(plik1,napis);
        
        for(int i = 0; i<napis.length(); i++){ //liczy wyst¹pienia znaku
        	if(napis[i]>64&&napis[i]<91)
            napis[i] += 32; //wg ASCII aby zmieniæ na wielk¹ literê wystarczy odj¹æ od znaku (char) 32.           
        }
        
        
        
        stringstream ss(napis);
        while(ss >> slowo) //dopóki w strumieniu wejœciowym skonstruowanym ze zdania jest jakieœ s³owo (do spacji)
                polacz += slowo; //dokleja bez spacji do wyniku
        
        int end = polacz.length()-1; 
        bool isPalindrome = true; 
        string oR;
        
        for (int i=0; i<polacz.length()/2 && isPalindrome; i++) 
            if (polacz[i] != polacz[end--]) 
                    isPalindrome = false;
        
        if(isPalindrome){
        	oR = "Tak";
		}else{
			oR = "Nie";
		}
        
        plik2<<"{\"string\":"<<"\""<<polacz<<"\""<<","<<"\"palindrom\":"<<"\""<<oR<<"\"},";
        
        polacz="";
        
    
                   
    }
    plik2<<"]";
    
    cout<<finalScore;
}


zmiana::~zmiana(){
    plik1.close();
}

int main() {
    zmiana change; 
    change.zmien(); 
    return 0;
}
