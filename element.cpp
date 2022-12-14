//
// Created by 房诗涵 on 2022/12/12.
//

#include "element.h"


Index::Index() {
    index[0] = '\0';//empty string
}

Index::Index(std::string id) {
    for (int i = 0; i < id.size(); ++i)
        index[i] = id[i];
    index[id.size()] = '\0';
}

bool Index::operator>(const Index &id) const {
    for (int i = 0;; ++i) {
        if (index[i] > id.index[i])return true;
        if(index[i] < id.index[i]) return false;
        if (index[i] == '\0')return false;
        if (id.index[i] == '\0')return true;

    }
}

bool Index::operator==(const Index &id) const {
    int i = 0;
    while (index[i] != '\0') {
        if (index[i] != id.index[i])return false;
        ++i;
    }
    return true;
}

bool Index::operator>=(const Index &id) const {
    if ((*this > id) || (*this == id))return true;
    else return false;
}

std::ostream &operator<<(std::ostream &os, const Index &index) {
    int i = 0;
    while (index.index[i] != '\0') {
        os << index.index[i];
    }
    return os;
}

Index &Index::operator=(const Index &id) = default;

Index::~Index() = default;

bool account::operator>(const account &id) const {
    if (index > id.index || (index == id.index && value > id.value)) return true;
    else return false;
}

Index account::GetKey() const {
    return index;
}

bool account::operator==(const account &account) const {
    if (account.index == index && account.value == value)return true;
    else return false;
}

bool account::operator>=(const account &account) const {
    if (*this > account || *this == account)return true;
    else return false;
}

int account::GetVal() const {
    return value;
}

account &account::operator=(std::pair<account, bool> account) {
    return account.first;
}


AccountManager::AccountManager() {

}

void AccountManager::AddUser(std::string &index, int value) {
    //create an account
    account userAccount;
    Index index1(index);
    userAccount.index = index1;
    userAccount.value = value;
    //insert
    accountList.Insert(index1, userAccount);
}

bool AccountManager::DeleteUser(std::string &index, int value) {
    account a;
    a.value = value;
    Index id(index);
    a.index = id;
    bool b = accountList.Erase(id, value);
    return b;
}

//more than one
std::pair<account, bool> AccountManager::FindAccount(const std::string &UserID) {
    account a;
    Index id(UserID);
    a.index = id;
    if (!more) {//haven't gotten any
        if (accountList.FindKey(id).second) {
            currentValue = accountList.FindKey(id).first.value;
            return std::make_pair(accountList.FindKey(id).first, true);
        } else return std::make_pair(a, false);
    } else {
        if (accountList.FindK(id, currentValue).second) {
            currentValue = accountList.FindK(id, currentValue).first.value;//update currentValue
            return std::make_pair(accountList.FindK(id, currentValue).first, true);
        }else return std::make_pair(a,false);
    }
}

void AccountManager::StringToChar(std::string str, char *ch) {
    int i;
    for (i = 0; i < str.size(); ++i) {
        ch[i] = str[i];
    }
    ch[i] = '\0';
}