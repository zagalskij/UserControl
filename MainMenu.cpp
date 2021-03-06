#ifndef UNICODE
#define UNICODE
#endif

#include "stdafx.h"
#include "DLLFunctions.h"
#include "UserControl.h"

using namespace std;

//вывод всех возможных команд
void printAllCommands(void)
{
    cout << "...\n"
        "# enter command:\n"
        "# 1 - add user\n"
        "# 2 - remove user\n"
        "# 3 - add group\n"
        "# 4 - remove group\n"
        "# 5 - enumerate users\n"
        "# 6 - add privilege to user or group\n"
        "# 7 - remove user or group privilege\n"
        "# 8 - remove all user or group privileges\n"
        "# 9 - join group\n"
        "# 10 - leave group\n"
        "# 11 - print all user or group privileges\n"
        "# 12 - print all groups\n"
        "# 0 - exit\n";
    return;
}

//главное меню в цикле
int main(void)
{
    setlocale(LC_ALL, "Russian");
    Load_Dll();
    int command;
    TCHAR user_name[1024] = { 0 };
    TCHAR group_name[1024] = { 0 };
    TCHAR user_password[1024] = { 0 };
    DWORD privilege_index = 0;
    cout << "# userControl by dzagalskij" << endl;
    //главное меню
    while (1)
    {
        //распечатать все команды
        printAllCommands();
        cout << "# ";
        //ввод команды пользователя
        cin >> command;
        //распознавание команды пользователя
        //и выполнение определенной процедуры или функции
        if (command == 1)
        {
            cout << "# enter user name:\n# ";
            wcin >> user_name;
            cout << "# enter user password:\n# ";
            wcin >> user_password;
            Add_User((LPWSTR)user_name, (LPWSTR)user_password);
        }
        else if (command == 2)
        {
            wcout << "# enter user name:\n# ";
            wcin >> user_name;
            Delete_User((LPWSTR)user_name);
        }
        else if (command == 3)
        {
            wcout << "# enter group name:\n# ";
            wcin >> group_name;
            Add_Group((LPWSTR)group_name);
        }
        else if (command == 4)
        {
            wcout << "# enter group name:\n# ";
            wcin >> group_name;
            Delete_Group((LPWSTR)group_name);
        }
        else if (command == 5)
        {
            Enumerate_Users(NULL);
        }
        else if (command == 6)
        {
            wcout << "# enter user or group name:\n# ";
            wcin >> user_name;
            List_Privileges();
            wcout << "# enter privilege index\n# ";
            wcin >> privilege_index;
            Set_User_Privileges((LPWSTR)user_name, privilege_index);
        }
        else if (command == 7)
        {
            wcout << "# enter user or group name\n# ";
            wcin >> user_name;
            List_Privileges();
            wcout << "# enter privilege index\n# ";
            wcin >> privilege_index;
            Clear_User_Privileges((LPWSTR)user_name, privilege_index);
        }
        else if (command == 8)
        {
            wcout << "# enter user or group name\n# ";
            wcin >> user_name;
            Clear_All_User_Privileges((LPWSTR)user_name);
        }
        else if (command == 9)
        {
            wcout << "# enter user name\n# ";
            wcin >> user_name;
            wcout << "# enter group name\n# ";
            wcin >> group_name;
            Assign_User_To_Group((LPWSTR)user_name, (LPWSTR)group_name);
        }
        else if (command == 10)
        {
            wcout << "# enter user name\n# ";
            wcin >> user_name;
            wcout << "# enter group name\n# ";
            wcin >> group_name;
            Exclude_User_From_Group((LPWSTR)user_name, (LPWSTR)group_name);
        }
        else if (command == 11)
        {
            wcout << "# enter user or group name\n# ";
            wcin >> user_name;
            printPrivileges(user_name);
        }
        else if (command == 12)
        {
            Get_Groups_Enum();
        }
        else if (command == 0)
        {
            Unload_Dll();
            exit(0);
        }
        else
        {
            cout << "# incorrect command!\n";
        }
    }
}