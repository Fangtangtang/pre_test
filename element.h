//
// Created by 房诗涵 on 2022/12/12.
//

#ifndef QIANZHI_ELEMENT_H
#define QIANZHI_ELEMENT_H

#include "linkList.h"
#include <string>
#include <iostream>
//key:ID
struct Index {
    char index[65];

    Index();

    Index(std::string id);

    ~Index();

    bool operator>(const Index &index1) const;

    bool operator==(const Index &index1) const;

    bool operator>=(const Index&index1) const;

    Index &operator=(const Index &index1);

    friend std::ostream &operator<<(std::ostream &os,const Index &index);

};

struct account {
    int value;
    Index index;

    bool operator>(const account &account) const;

    bool operator==(const account &account) const;

    bool operator>=(const account&account) const;

    account &operator=(std::pair<account, bool> account);
    //获取key
    Index GetKey() const;
    int GetVal() const;

    //修改密码
//    void ChangePassword(std::string &CurrentPassword,std::string &NewPassword);

};

class AccountManager{
public:
    int currentValue=0;

    bool more=false;

    AccountManager();

    ~AccountManager()=default;

    //insert
    void AddUser(std::string &index, int value);

    //delete
    bool DeleteUser(std::string &index,int value);

    //find
    std::pair<account,bool> FindAccount(const std::string &UserID);

private:

    LinkList<Index,account> accountList{"information"};

    std::fstream io_account_information;

    //转格式
    void StringToChar(std::string str,char* ch);
};




#endif //QIANZHI_ELEMENT_H
