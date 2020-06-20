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



    //write the storage file
    void writeUserTxt();
    void writeObjectTxt();
    
    //add in map
    void addUser(string, User*);

    //


private:
    map<string, User*> _users;
    map<string, object*> _objects;
    User*              _currentUser;


};




#endif