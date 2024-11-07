#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string imput;
    bool space = false;
    string s=" ";
    int place =0;
    vector<string> planer;
    getline(cin,imput);
    int n=0;
    while(n < imput.size()){
        if(imput[n]==s[0]){space=true; continue; place++;}
        if (space){planer.push_back(planer[imput[n]]);space=false;}
        else{
        planer[place] = planer[place] + imput[n];}
        n++;
    }

    cout << "your numbers" << imput;
    for(int z =0;z<planer.size();z++){
        cout << planer[z];
    }
    cout << "your numbers backwards";

    return 0;
}