#include <iostream>
#include <string>

using namespace std;

class Examinee
{
private:
    string Name;
    int ID;
    double Score;
public:
    void Input();
    virtual void Output();
    void PrintPreview();    
};

void Examinee::Input()
{
    cout << "Input the name: ";
    fflush(stdin);
    getline(cin, Name);

    cout << "Input the ID: ";
    cin >> ID;

    cout << "Input the score: ";
    cin >> Score;
}

void Examinee::Output()
{
    cout << "Print: " << Name << " - " << ID << " - " << "has got a score of " << Score << endl;
}

void Examinee::PrintPreview()
{
    char ch;
    cout << "Would you like to print examinee " << Name << "? (Y/N): ";
    cin >> ch;
    if (ch == 'Y' || ch == 'y')
    {
        this->Output();
    }
}

//----------------------------------------
class Examinee_2 : public Examinee
{
private:
    string Address;

public:
    void Input();
    void Output();

};

void Examinee_2::Input()
{
    Examinee::Input();
    cout << "Input the address: ";
    fflush(stdin);
    getline(cin, Address);
}

void Examinee_2::Output()
{
    Examinee::Output();
    cout << "--Address: " << Address << endl;
}

int main()
{
    Examinee_2 e[100];
    int n;

    cout << "Input the number of examinees: ";
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cout << "Examinee " << i << ":" << endl;
        e[i].Input();
    }

    for (int i = 0; i < n; ++i)
    {
        e[i].PrintPreview();
    }

    return 0;
}

