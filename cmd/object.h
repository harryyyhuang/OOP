/*****************************************
 *  FileName    [ object.h ]
 *  PackageName [ manager ]
 *  Synopsis    [ Define the object class ]
 *  Author      [ Harry Huang ]
*****************************************/

#ifndef OBJECT_H
#define OBJECT_H


#include <string>
#include <vector>


using namespace std;


class object;
class User;

class object{
public:
    object(string objectName, string objectID) 
                    : _objectName(objectName), _objectId(objectID){}

    void borrow(User* borrower){ _borrower = borrower; }
    

private:
    string _objectName;
    string _objectId;
    User*  _borrower;
};

#endif