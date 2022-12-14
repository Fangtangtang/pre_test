#include <iostream>
#include "linklist.h"
#include "element.h"
#include <string>

using namespace std;

int main() {
    freopen("my.out", "w", stdout);
    string cmd, index;
    AccountManager *accountManager = new AccountManager;
    int value;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> cmd;
        if (cmd == "insert") {
            cin >> index >> value;
            accountManager->AddUser(index, value);
        }
        if (cmd == "delete") {
            cin >> index >> value;
            if (!accountManager->DeleteUser(index, value))
                cout << "doesn't exist" << "\n";
        }
        if (cmd == "find") {
            cin >> index;
            account tmp;
            accountManager->more = false;
            accountManager->currentValue = 0;
            while (true) {
                pair<account,bool> pair=accountManager->FindAccount(index);
                if (pair.second) {
                    tmp = pair.first;
                    accountManager->more= true;
                    cout << tmp.value << ' ';
                } else {
                  if(!accountManager->more) cout << "null" ;
                    break;
                }
            }
            std::cout<<"\n";
        }
    }
    delete accountManager;
    return 0;
}
