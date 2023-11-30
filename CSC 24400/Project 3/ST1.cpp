/*
	A test case for the CandySet class

XXX XXX
	11/16/22
*/



#include <fstream>
#include <iostream>

#include "Candy.hpp"
#include "CandySet.hpp"

using namespace std;

int main (int argc, char *argv[])
{
    Candy c1("Reese's", 60);
    Candy c2("Hershey", 210);
    Candy c3("KitKat", 230);
    Candy c4("Twix", 50);
    Candy c5("Skittles",160);
    Candy c6("SourPatchKids", 140);
    Candy c7("Shoe",0);
    Candy c8("Carrot", 53);
    Candy c9("Celery", 6);
    Candy c10("BrusselSprouts", 6);
    Candy c11("Peas", 3);
    Candy c12("Mushrooms", 28);
    Candy c13("Onions", 17);
    Candy c14("Beets", 1);
    Candy c15("SomeCash",1000000);


    CandySet candyBag;

    //Checking candyBag inital size
    cout << "candyBag EXPECTED SIZE: 0       YOUR SIZE: " << candyBag.size()  << endl << endl;

    
    //Testing +=
    candyBag += c1;
    candyBag += c2;
    candyBag += c3;
    candyBag += c4;
    candyBag += c5;
    candyBag += c6;
    candyBag += c7;
    candyBag += c8;
    candyBag += c9;
    candyBag += c10;
    candyBag += c11;
    candyBag += c12;
    candyBag += c13;
    candyBag += c14;
    candyBag += c15;

            
    cout << "===== EXPECTED Things in candyBag =======" <<endl;
    cout << "Reese's(60) 0(0)" << endl

    << "Hershey(210) 0(0)" << endl
    << "KitKat(230) 0(0)" << endl
    << "Twix(50) 0(0)" << endl
    << "Skittles(160) 0(0)" << endl
    << "SourPatchKids(140) 0(0)" << endl
    << "Shoe(0) 0(0)" << endl
    << "Carrot(53) 0(0)" << endl
    << "Celery(6) 0(0)" << endl
    << "BrusselSprouts(6) 0(0)" << endl
    << "Peas(3) 0(0)" << endl
    << "Mushrooms(28) 0(0)" << endl
    << "Onions(17) 0(0)" << endl
    << "Beets(1) 0(0)" << endl
    << "SomeCash(1000000) 0(0)" <<endl;
    cout << "=========================================" <<endl << endl;

    //Yours
    cout << "===== Thing in YOUR candyBag =======" << endl << candyBag << "====================================" <<endl;

    cout << "candyBag EXPECTED SIZE: 15       YOUR SIZE: " << candyBag.size() << endl << endl;

    

    //Testing 3rd constructor
    CandySet veggieBag(candyBag);


    //Removing non-candy items
    candyBag -= c7;
    candyBag -= c8;
    candyBag -= c9;
    candyBag -= c10;
    candyBag -= c11;
    candyBag -= c12;
    candyBag -= c13;
    candyBag -= c14;
    candyBag -= c15;


    //Expected output:
    cout << "=== EXPECTED Things in veggieBag ==" << endl;
    cout << "Reese's(60) 0(0)" << endl
    << "Hershey(210) 0(0)" << endl
    << "KitKat(230) 0(0)" << endl
    << "Twix(50) 0(0)" << endl
    << "Skittles(160) 0(0)" << endl
    << "SourPatchKids(140) 0(0)" << endl
    << "Shoe(0) 0(0)" << endl
    << "Carrot(53) 0(0)" << endl
    << "Celery(6) 0(0)" << endl
    << "BrusselSprouts(6) 0(0)" << endl
    << "Peas(3) 0(0)" << endl
    << "Mushrooms(28) 0(0)" << endl
    << "Onions(17) 0(0)" << endl
    << "Beets(1) 0(0)" << endl 
    << "SomeCash(1000000) 0(0)" <<endl;
    cout << "==================================" <<endl << endl;

    //Yours:
    cout << "=== Things in YOUR veggieBag =====" << endl << veggieBag << "==================================" <<endl;
    
    //Checking veggieBag's size when using 3rd constructor
    cout << "veggieBag EXPECTED SIZE: 15       YOUR SIZE: " << veggieBag.size() << endl << endl; 

    //Removing actual candies
    veggieBag -= c1;
    veggieBag -= c2;
    veggieBag -= c3;
    veggieBag -= c4;
    veggieBag -= c5;
    veggieBag -= c6;


    //Expected output: 
    cout << "===== EXPECTED Things in veggieBag after removing all the candies =======" << endl;
    cout << "Shoe(0) 0(0)" << endl
    << "Carrot(53) 0(0)" << endl
    << "Celery(6) 0(0)" << endl
    << "BrusselSprouts(6) 0(0)" << endl
    << "Peas(3) 0(0)" << endl
    << "Mushrooms(28) 0(0)" << endl
    << "Onions(17) 0(0)" << endl
    << "Beets(1) 0(0)" << endl 
    << "SomeCash(1000000) 0(0)" <<endl;
    cout << "=========================================================================" <<endl << endl;

    //Yours:
    cout << "===== Things in YOUR veggieBag after removing all the candies =======" << endl << veggieBag;
    
    cout << "=====================================================================" <<endl;
    cout << "veggieBag EXPECTED SIZE: 9       YOUR SIZE: " << veggieBag.size() << endl << endl; 

    //Trying to find a Candy object in veggieBag
    cout << "Is there a Chair in your veggieBag?" << endl;
    cout << "EXPECTED OUTPUT: NO     YOURS: ";
    if (veggieBag.find("Chair") != NULL)
    cout << "YES" << endl << endl;
    else
    cout << "NO" << endl << endl;

    //Trying to find a Candy object in veggieBag
    cout << "Is there a Shoe in your veggieBag?" << endl;
    cout << "EXPECTED OUTPUT: YES     YOURS: ";
    if (veggieBag.find("Shoe") != NULL)
    cout << "YES" << endl << endl;
    else
    cout << "NO" << endl << endl;

    //Trying to find a Candy object in veggieBag
    cout << "Is there SomeCash in your veggieBag?" << endl;
    cout << "EXPECTED OUTPUT: YES     YOURS: ";
    if (veggieBag.find("SomeCash") != NULL)
    cout << "YES" << endl << endl;
    else
    cout << "NO" << endl << endl;

    //Testing operator-= on a Candy object
    veggieBag-=c7;
    
    //Testing operator-= on a string
    veggieBag-="SomeCash";


    // //Testing 2nd constructor
    // CandySet otherBag(2);  
    // otherBag += c7;
    // otherBag += c15;
    CandySet otherBag;
    otherBag += c7;
    otherBag += c15;

    //Testing equality
    cout << "Does candyBag==veggieBag ?" << endl;
    if (candyBag==veggieBag)
        cout << "INCORRECT: candybag and veggieBag SHOULD NOT be equal!" << endl << endl;
    else
        cout << "CORRECT: candybag and veggieBag are NOT equal!" << endl << endl;


    cout << "Does veggieBag=candyBag ?" << endl;
    if (veggieBag==candyBag)
        cout << "INCORRECT: veggieBag and candyBag SHOULD NOT be equal!" << endl << endl;
    else
        cout << "CORRECT: veggieBag and candyBag are NOT equal!" << endl << endl;

    cout << "Does veggieBag!=otherBag ?" << endl;
    if(veggieBag!=otherBag)
        cout << "CORRECT: The two bags are indeed NOT equal!" << endl << endl;
    else 
        cout << "INCORRECT: The two bags SHOULD NOT be equal!" << endl << endl;


    //Testing default constructor
    CandySet tempOtherBag;

    //Testing operator=
    tempOtherBag = otherBag;

    cout << "Does tempOtherBag==otherBag ?" << endl;
    if (tempOtherBag==otherBag)
        cout << "CORRECT: tempOtherBag and otherBag ARE equal!" << endl << endl;
    else 
        cout << "INCORRECT: tempOtherBag and otherBag SHOULD BE equal!" << endl << endl;


    //Testing clear function
    otherBag.clear();

    cout << "===== EXPECTED Things in veggieBag after invoking clear() =======";
    cout << endl;
    cout << "=================================================================" <<endl << endl;


    cout << "===== Things in YOUR veggieBag after invoking clear() =======";
    cout << otherBag << endl;
    cout << "=============================================================" <<endl;

    cout << "otherBag EXPECTED SIZE: 0       YOURS: " << otherBag.size() << endl << endl;

    //Testing operator=
    otherBag = tempOtherBag;

    cout << "otherBag should now only contain:" << endl << "Shoe" << endl << "SomeCash" << endl << endl;
    cout << "=== Things in YOUR otherBag ====" << endl;
    cout << otherBag;
    cout << "================================" <<endl << endl;

    cout << "candyBag should only contain candies (6)." << endl;
    cout << "=== Things in YOUR candyBag ===="<<endl;
    cout << candyBag;
    cout << "================================" <<endl << endl;
    
    cout << "veggieBag should only contain vegetables (7)." << endl;
    cout << "=== Things in YOUR veggieBag ==="<<endl;
    cout << veggieBag;
    cout << "================================" <<endl << endl;

    return 0;
}