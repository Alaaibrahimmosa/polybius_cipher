#include <iostream>
using namespace std;
/*
FCI-Programming 1 -2018 - Assignment 2
Program Name : prime numbers Finder.
Last Modification Date 5/3/2018.
Author1 and ID and Group : Fares sayed hassan , 20170191 , 8.
Author2 and ID and Group : Alaa Ibrahem , 20170166 , 7.
Author3 and ID and Group : Amr Alaa , 20170187 , 7.
Author4 and ID and Group : Ali Samir , 20170172 ,7.
Teaching Assistant:
Purpose : Find and prints all prime numbers from 3 to 100.
*/



int main()
{

    bool isPrime = false ;

    for (int i=3 ; i<=100 ; i++)
    {
        for(int k = 2 ; k<10 ; k++)
        {

            if((i%k==0))
            {
                if(i==k)
                    continue ;
                else
                {
                    isPrime = false ;
                    break;
                }
            }

            else
                isPrime = true ;
        }
        if(isPrime == true )
            cout<<i<<"   ";
    }
    cout<<endl<<endl;





    return 0;
}
