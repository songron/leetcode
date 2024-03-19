#include <iostream>
#include <string>

using namespace std;

class IDCard;

class Student
{
private:

    string name;
    IDCard* card;

public:

    Student() {}

    Student(string name) : name(name), card(nullptr) {}

    void Setname(string name)
    {
        this->name = name;
    }

    void assignIDCard(IDCard* id)
    {
        card = id;
    }

    string getName() {
        return name;
    }

    IDCard* getIDCard() {
        return card;
    }
};

class IDCard
{
private:
    string cardNumber;
    Student* owner;

public:

    IDCard() {}

    IDCard(string number) : cardNumber(number), owner(nullptr) {}


    void SetID(string ID)
    {
        this->cardNumber = ID;
    }

    void assignOwner(Student* student)
    {
        owner = student;
    }

    string getCardNumber()
    {
        return cardNumber;
    }

    Student* getOwner()
    {
        return owner;
    }

};

int main()
{
    Student Students[3];
    IDCard idcards[3];
    string names[] = { "Usman","Hamza","Arslan" };
    string IDs[] = { "01-131232-047","01-131232-098","01-131232-21" };

    for (int i = 0; i < sizeof(names) / sizeof(names[0]); i++)
    {
        Students[i].Setname(names[i]);
        idcards[i].SetID(IDs[i]);
        Students[i].assignIDCard(&idcards[i]);
        idcards[i].assignOwner(&Students[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "Student: " << Students[i].getName() << endl << endl;
        cout << "ID Card Number: " << Students[i].getIDCard()->getCardNumber() << endl << endl;
    }

    cout << endl << endl;
    system("pause>0");
    return 0;
}