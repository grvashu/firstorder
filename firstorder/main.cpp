//
//  main.cpp
//  firstorder
//
//  Created by Gaurav Singh on 31/01/19.
//  Copyright © 2019 Mathscapes Research. All rights reserved.
//

#include <iostream>
using namespace std;

class Variable{
    bool state;
    string name;
public:
    Variable(){
        name = "";
        state = false;
    }
    Variable(string name, bool state){
        this->name = name;
        this->state = state;
    }
    void setName(string name){
        this->name = name;
    }
    string getName(){
        return name;
    }
    void setState(bool state){
        this->state = state;
    }
    bool getState(){
        return state;
    }
    void toggle(){
        state = !state;
    }
    friend std::ostream& operator<<(std::ostream& os, const Variable& var){
        os<<var.name<<':'<<var.state;
        return os;
    }
};

class Constant:public Variable{
public:
    Constant() : Variable(){
        // do nothing
    }
    Constant(string name, bool state) : Variable(name,state){
        // do nothing
    }
    void toggle(){
        // do nothing
    }
};

int main(int argc, const char * argv[]) {
    Variable v = Variable("A",true);
    Constant c = Constant("C",true);
    v.toggle();
    c.toggle();
    std::cout << v << endl;
    std::cout << c << endl;
    return 0;
}
