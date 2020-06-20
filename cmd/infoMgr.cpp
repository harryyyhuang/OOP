/**********************************************************
 *  FileName    [ infoMgr.cpp ]
 *  PackageName [ manager ]
 *  Synopsis    [ Define the information management class ]
 *  Author      [ Harry Huang ]
***********************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "infoMgr.h"
#include "user.h"
#include "object.h"
#include "util.h"


using namespace std;

/**********************************/
/*  Global variable and enum      */
/**********************************/
// infoMgr* infoMgr = 0;


/**********************************/
/*  class infoMgr member function */
/**********************************/
void infoMgr::readObjectTxt(){
    ifstream fin("objects.txt");
    string s;

    // make sure it's objects.txt
    getline(fin, s);
    assert(s == "Item");

    // get the number of objects
    getline(fin, s);
    int itemNumber ;
    itemNumber = getNum(s);

    // get the info 
    for(int i = 0; i < itemNumber; ++i){
        getline(fin, s);
        string objectName;
        string objectID;
        stringstream ss;
        ss << s;
        ss >> objectName;
        ss >> objectID;
        object* tmpobject = new object(objectName, objectID);
        _objects.insert(pair<string, object*>(objectName, tmpobject));
    }

    fin.close();

}

void infoMgr::readUserTxt(){
    ifstream fin("storage.txt");
    string s;
    stringstream ss;

    // make sure it's users.txt
    getline(fin, s);
    assert(s == "Users");

    // get the number of user
    getline(fin, s);
    int userNumber;
    getStringAndNum(s, userNumber);
    assert(s == "Number");
   
    // get the info 
    for(int i = 0; i < userNumber; ++i){
        string userTitle;
        string userName;
        string passWordTitle;
        string passWord;
        int borrowNum;
        User* tmpuser = new User();

        getline(fin, s);
        ss << s;
        ss >> userTitle;
        ss >> userName;
        assert(userTitle == "UserID");

        ss.str("");
        ss.clear();

        getline(fin, s);
        ss << s;
        ss >> passWordTitle;
        ss >> passWord;
        assert(passWordTitle == "Password");

        ss.str("");
        ss.clear();
        
        tmpuser->setID(userName);
        tmpuser->setPass(passWord);

        getline(fin, s);
        getStringAndNum(s, borrowNum);
        assert(s == "BorrowNumber");

        for(int i = 0; i < borrowNum; ++i){
            getline(fin, s);
            getString(s);
            map<string, object*>::iterator iter = _objects.find(s);
            object* tmpobj = iter->second;
            tmpobj->borrow(tmpuser);
            tmpuser->addBorrow(tmpobj);
        }

        _users.insert(pair<string, User*>(userName, tmpuser));

        getline(fin, s);
    }

    fin.close();


}



