#include <QCoreApplication>
#include <heder.h>


int main()
{
   int statusgame=false;
   bool result=false;
   string choice;
   do{
       statusgame=startgame();
       cout<<"Do you what to restart game ??\n";
       cout<<"Print yes or no\n";
       do
       {
           cout<<"Your choice: ";
           cin>>choice;
       }
       while(choice!="yes" && choice!="no");
       if(choice=="yes")
           result=true;
       if(choice=="no")
             result==false;
   }while(result);
cout<<"Thanks for the game :3";
return 0;
}
