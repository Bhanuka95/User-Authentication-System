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
        int encrypt(int p_letter);
        int decrypt(int p_letter);
        void saveFile(string p_line, const char* p_fileName);
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

    int eChar;

    file.open(p_fileName, ios::in);
    while(1){
        file >> eChar;
        if(eChar == 0){
            file.close();
            return line;
        }
        line += (char)decrypt(eChar);
    }
    
}
//encryption
int loginManager::encrypt(int p_letter){
    return p_letter + 3;
}
//decryption
int loginManager::decrypt(int p_letter){
    return p_letter -3;
}

void loginManager::saveFile(string p_line, const char* p_fileName){
    fstream file;
    file.open(p_fileName, ios::out);

    for(int i=0; i<p_line.length(); i++){
        file << encrypt(p_line[i]);
        file << "\n";
    }
    file << "0";
    file.close();
}

int main(){
    loginManager usr1;
    // usr1.saveFile("GrapeJuice", "pswds.dat");
    // cout << usr1.retrieveFile("pswds.dat") << endl;
    usr1.login();
    

    return 0;
}