#include <QCoreApplication>
#include <game.h>


int main()
{
   int statusgame=false;
   statusgame=startgame();
   char choice;
   do
   {
       cout<<"Do you what to restart game ??\n";
       cout<<"Print yes or no\n";

       do
       {
           cout<<"Your choice: ";
           cin>>choice;
       }
       while(choice!='yes' || choice!='no');
   }
   while(statusgame);

}
