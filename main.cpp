#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class loginManager{
    private:
    string userName, password;
    bool accessGranted;

    public:
        string usernameAttempt;
        string pwdAttempt;
        loginManager();
        void login();
        string retrieveFile(const char* p_fileName);
};

loginManager::loginManager(){
    accessGranted = false;
}
void loginManager::login(){
    printf("\nEnter your username: \n");
    cin >> usernameAttempt;
    userName = retrieveFile("users.dat");
    if(usernameAttempt == userName){
        printf("\nEnter the password: \n");
        cin >>pwdAttempt;
        password = retrieveFile("pswds.dat");
        if(pwdAttempt == password){
            printf("You are authenticated as: %s", userName.c_str());
        }
        else{
            printf("Sorry!!! You are not authenticated!");
            login();
        }
    }
    else{
        printf("Sorry!!! User: %s Doesn't exist!", usernameAttempt.c_str());
        login();
    }
        
}
//retrieve passwords and usernames from text file
string loginManager::retrieveFile(const char* p_fileName){
    string line;
    fstream file;

    file.open(p_fileName, ios::in);
    if(file.is_open()){
        getline(file, line);
    }
    file.close();
    return line;
}

int main(){
    loginManager usr1;
    usr1.login();

    return 0;
}