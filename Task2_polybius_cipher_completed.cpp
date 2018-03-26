#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*
FCI-Programming 1 -2018 - Assignment 2
Program Name : Polybius square cipher.
Last Modification Date 5/3/2018.
Author1 and ID and Group : Fares sayed hassan , 20170191 , 8.
Author2 and ID and Group : Alaa Ibrahem , 20170166 , 7.
Author3 and ID and Group : Amr Alaa , 20170187 , 7.
Author4 and ID and Group : Ali Samir , 20170172 ,7.
Teaching Assistant:
Purpose : ciphering and deciphering using Polybius square cipher.
*/

string cipher(string message,string key);
string decipher(string message,string key);
int findInKey(string key,char target);

char table[5][5];
int main()
{
cout << "ahlan ya user ya habibi." << endl;
cout << "what do you want to do?" << endl;
while(true){
    char ToPlace='a';
    string message;
    int choice;
    string key;
    //Filling the Board with letters.omitting the letter z
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            table[i][j]=ToPlace;
            ++ToPlace;
        }
    }//end of Filling .


    cout << "\npres 1 for ciphering.\npress 2 for deciphering\nPress any other number for existing .";
    cin >> choice;
    cin.ignore();


    if(choice == 1){
        cout << "Enter the key, between 0 to 4 ,DO NOT PUT SPACES!!: " << endl;
        cin >> key;
        cin.ignore();
        cout << "Enter the message :" << endl;
        getline(cin,message);
        cout << "cipher: " << cipher(message,key) << endl;

    }else if(choice == 2){
        cout << "Enter the key, between 0 to 4 ,DO NOT PUT SPACES!!: " << endl;
        cin >> key;
        cin.ignore();
        cout << "Enter the message :" << endl;
        getline(cin,message);
        cout << "decipher: " << decipher(message,key) << endl;
    }else{
        break;
    }

}
    return 0;
}//end of main.

string cipher(string message,string key){
    string toReturn;
    for(int i=0;i<message.length();i++){
        if(message[i] == 'z'){
            toReturn += '&';
        }

        else if(message[i]==' '){
            toReturn+=" ";
        }
        // find the row and column in table.
        else{
              for(int j=0;j<5;j++){
                for(int k =0; k<5;k++){
                    if(tolower(table[j][k]) == message[i]){
                        toReturn+=key[j];
                        toReturn+=key[k];

                    }
                }
              }// end of finding.
        }//end of else.
    }//end of looping on the message.

    return toReturn;
}
string decipher(string message,string key){
    string toReturn;
    for (int i=0;i<message.length();i++){
        if(message[i] == ' '){
            toReturn += " ";
        }else if(message[i] == '&'){
            toReturn+= "z";
        }
        else{
            toReturn += table[findInKey(key,message[i])][findInKey(key,message[i+1])];
            ++i;
        }
    }// end of loop on the message.
    return toReturn;
}

int findInKey(string key,char target){
    for(int i=0; i<key.length();i++){
        if(key[i] == target){
            cout << "key[i] " <<key[i] << "i:" << i << endl;
            return i;
        }
    }


}




