#include<iostream>
#include<string>
using namespace std;

class loginManager{
    private:
    string userName="Bhanuka", password="1995";
    bool accessGranted;

    public:
        string usernameAttempt;
        string pwdAttempt;
        loginManager();
        void login();
};

loginManager::loginManager(){
    accessGranted = false;
}
void loginManager::login(){
    printf("Enter your username: \n");
    cin >> usernameAttempt;
    if(usernameAttempt == userName){
        printf("Enter the password: \n");
        cin >>pwdAttempt;
        if(pwdAttempt == password){
            printf("You are authenticated as: %s", userName.c_str());
        }
    }
}

int main(){
    loginManager usr1;
    usr1.login();

    return 0;
}