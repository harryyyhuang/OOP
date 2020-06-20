/**********************************************************
 *  FileName    [ infoMgr.h ]
 *  PackageName [ manager ]
 *  Synopsis    [ Define the information management class ]
 *  Author      [ Harry Huang ]
***********************************************************/

#ifndef INFO_MGR_H
#define INFO_MGR_H


#include "user.h"
#include "object.h"
#include <map>
#include <vector>

using namespace std;

class infoMgr ;

class infoMgr{
public:

    infoMgr(){}

    //read the storage file
    void readUserTxt();
    void readObjectTxt();



    // write the storage file
    void writeUserTxt();
    void writeObjectTxt();

//--------------------------------------------------------------------------------------------------------
//  functions for system to call //

    // register functions
    bool setID(string UserID) // return false if same id exist
    void setPassWord(string Password) 

    // borrow functions
    bool borrowByID(string id); // return false if object has been borrowed or not exist
    bool borrowByName(string objName);// return false if there's no available object or not exist
    
    //return functions
    bool returnByID(string id); // return false if id not exist or haven't borrowed
    bool returnByName(string objName); // return false if haven't borrowed
//---------------------------------------------------------------------------------------------------------
    
    
    //add in map
    void addUser(string, User*);

    //
    int(id) search(string object);
    // use id to borrow
    void borrow(id);

    // use id to return 
    void returnobj(id);

    //resgister 
    bool setID(string s); // make sure no same ID
    void setPassWord(string s);

    //login
    bool logID(string ID, string Password);

private:
    map<string, User*> _users;
    map<string, vector<object*>> _objects;
    User*              _currentUser;


};




#endif