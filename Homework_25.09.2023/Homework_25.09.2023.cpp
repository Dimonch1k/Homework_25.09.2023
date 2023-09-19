#include <iostream>
#include <vector>
using namespace std;




class AuthenticationException : public exception
{
public:
    AuthenticationException(string message) : exception(message.c_str()){}
};




class User {
private:
    string name;
    int password;

public:
    User(string name, int password)
    {
        this->name = name;
        this->password = password;
    }

    string getName()
    {
        return name;
    }

    int getPassword()
    {
        return password;
    }
};


class Register {
private:
    vector<User*> users;

public:

    void addUser(User* user)
    {
        users.push_back(user);
    }
    
    int signIn()
    {
        string userName;
        int userPassword;

        cout << "Login in your account: \n";
        cout << "\tName: "; cin >> userName;
        cout << "\tPassword: "; cin >> userPassword;

        for (int i = 0; i < users.size(); i++)
        {
            if (userName == users[i]->getName())
            {
                if (userPassword == users[i]->getPassword())
                {
                    cout << "You successfully login to your account!\n\n\n";
                    return 0;
                }
            }
        }
        throw AuthenticationException("Incorrectly entered name or password!\n\n\n");
        signIn();
    }
};





int main()
{   
    vector<User*> users;
    Register* regist = new Register();
    try {
        
        
        User* user1 = new User("Jura", 12345);
        User* user2 = new User("Andriy", 54321);
        User* user3 = new User("Maks", 67890);
        User* user4 = new User("Fandy", 98765);
        User* user5 = new User("Larry", 34567);

        regist->addUser(user1);
        regist->addUser(user2);
        regist->addUser(user3);
        regist->addUser(user4);
        regist->addUser(user5);



        regist->signIn();
    }

    catch (const AuthenticationException& ex)
    {
        cout << ex.what() << "\n\n";
        regist->signIn();
    }
}