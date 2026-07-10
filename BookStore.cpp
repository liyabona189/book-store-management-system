#include <iostream>
#include <string>
using namespace std;

// created class called BookType
class BookType {
private:                 // access specifier

// attributes 

string title;
string authors[4];         
string publisher;
string isbn;
double price;
int numCopies;
int numAuthors;

// declared a default constructor 

public:

BookType(){
    title = "";
    
    for (int i = 0; i < 4; ++i) {
            authors[i] = ""; 
        }

    publisher = "";
    isbn = "";
    price = 0.0;
    numCopies = 0;
    numAuthors = 0;

}

// Parameterized constructor

BookType(string t, string a[4], string p, string i, double pr, int nC, int nA) {
        
        title = t;
        for(int i = 0; i < 4; ++i){
            authors[i] = a[i];
        }
        publisher = p;
        isbn = i;
        price = pr;
        numCopies = nC;
        numAuthors = nA;

}

// SETTERS 

void setTitle(string t){
    title = t;
}

void setAuthors(string a[], int count) {
    if (count <= 4) {
        for (int i = 0; i < count; i++) {
            authors[i] = a[i];
        }
        numAuthors = count;
    } 
    else {
        cout << "Cannot have more than 4 authors." << endl;
    }
}

void setPublisher(string p){
    publisher = p;
}


void setIsbn( string i){
    isbn = i;
}

void setPrice(double pr){
    price = pr;

}
    
void setNumCopies(int nC){
    numCopies = nC;
}

void setNumAuthors(int nA){
    numAuthors = nA;
}

//GETTERS

string getTitle(){
    return title;
}

string getAuthor(int i) { // Return a specific author by i
        if (i < numAuthors) {
            return authors[i];
        }
        return "";
    }


string getPublisher(){
    return publisher;
}

string getIsbn(){
    return isbn;
}

double getPrice(){
    return price;
}

int getNumCopies(){
    return numCopies;
}

int getNumAuthors(){
    return numAuthors;
}

// method to update number of copies

void updateCopies(int newNumCopies){
    
    numCopies += newNumCopies;
}

// method to compare book titles or ISBN with input

bool bookTitles(string input){
    
    return (title == input || isbn == input);
        
    }

    // Display Function

    void displayBook(){

        cout << "The title of the book: " << title << endl;

         cout << "Authors: ";
        for (int i = 0; i < numAuthors; i++) {
            cout << authors[i];
            if (i < numAuthors - 1) cout << ", ";
        }
        cout << endl;
        cout << "The publisher of the book: " << publisher << endl;
        cout << "The ISBN of the book: " << isbn << endl;
        cout << "The price of the book: R" << price << endl;
        cout << "The number of copies in stock: " << numCopies << endl;
        cout << "The number of authors in the book: " << numAuthors << endl;
    }

};

class MemberType {
    public:

string name;
string memberId;
int booksBought;
double amountSpent;

public:                 //access specifier

// default costructor

    MemberType(){
        name = "";
        memberId = "";
        booksBought = 0;
        amountSpent = 0.0;
    }

// declared a parameterised constructor

MemberType(string n, string mI, int bB, double aS) {

    name = n;
    memberId = mI;
    booksBought = bB;
    amountSpent = aS;

}

//SETTERS

void setName(string n){
    name = n;
}

void setMemberId(string mI){
    memberId = mI;
}

void setBooksBought(int bB){
    booksBought = bB;
}

void setAmountSpent(double aS){
    amountSpent = aS;
}

//GETTERS

string getName(){
    return name;
}

string getMemberId(){
    return memberId;
}

int getBooksBought(){
    return booksBought;
}

double getAmountSpent(){
    return amountSpent;
}

// method to update number of books

void updateBooksBought(int newBooksBought){
    booksBought += newBooksBought;
}

// method to update amount spent

void updateAmountSpent(double newAmountSpent){
     amountSpent += newAmountSpent;
}

// Display function 

void displayMemberInfo(){
    
    cout << "Name of member: " << name << endl;
    cout << "Member ID: " << memberId << endl;
    cout << "Number of books bought: " << booksBought << endl;
    cout << "Amount Spent: R" << amountSpent << endl;
    
}

};

// derived class SpecialMemberType

class SpecialMemberType:public MemberType{
    public:                                             // access specifier

    string membershipLevel;

// default constructor 

    SpecialMemberType(){
        membershipLevel = "";
    }

// paramterized constructor

    SpecialMemberType(string n, string mI, int bB, double aS, string mL) 
        : MemberType(n, mI, bB, aS), membershipLevel(mL) {}

//SETTERS

    void setMembershiplevel(string mL){
        membershipLevel = mL;
    }

//GETTERS 

    string getMembershipLevel(){
        return membershipLevel;
    }

// Display Function

    void displayMembershipDetails(){
         cout << "Name of member: " << name << endl;
         cout << "Member ID: " << memberId << endl;
         cout << "Number of books bought: " << booksBought << endl;
         cout << "Amount Spent: R" << amountSpent << endl;
         cout << "Membership Level: " << membershipLevel << endl;
    
        }
};

int main(){
    
    BookType books[100];
    MemberType members[50];
    SpecialMemberType specialMembers[50];

    int bookCount = 0;
    int memberCount = 0;
    int specialMemberCount = 0;

    while (true) {
        cout << "1. Add Book\n2. Add Member\n3. Add Special Member\n4. View Books\n5. View Members\n6. Exit\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string title, publisher, isbn;
            double price;
            int numCopies, numAuthors;
            string authors[4];

            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter publisher: ";
            getline(cin, publisher);
            cout << "Enter ISBN: ";
            getline(cin, isbn);
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter number of copies: ";
            cin >> numCopies;
            cout << "Enter number of authors (max 4): ";
            cin >> numAuthors;

            for (int i = 0; i < numAuthors; i++) {
                cout << "Enter author " << (i + 1) << ": ";
                cin.ignore();
                getline(cin, authors[i]);
            }

            books[bookCount++] = BookType(title, authors, publisher, isbn, price, numCopies, numAuthors);
            cout << "Book added successfully!\n";
        } 
        else if (choice == 2) {
            string name, memberId;
            int booksBought;
            double amountSpent;

            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter member ID: ";
            getline(cin, memberId);
            cout << "Enter number of books bought: ";
            cin >> booksBought;
            cout << "Enter amount spent: ";
            cin >> amountSpent;

            members[memberCount++] = MemberType(name, memberId, booksBought, amountSpent);
            cout << "Member added successfully!\n";
        } 
        else if (choice == 3) {
            string name, memberId, membershipLevel;
            int booksBought;
            double amountSpent;

            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter member ID: ";
            getline(cin, memberId);
            cout << "Enter number of books bought: ";
            cin >> booksBought;
            cout << "Enter amount spent: ";
            cin >> amountSpent;
            cout << "Enter membership level: ";
            cin.ignore();
            getline(cin, membershipLevel);

            specialMembers[specialMemberCount++] = SpecialMemberType(name, memberId, booksBought, amountSpent, membershipLevel);
            cout << "Special member added successfully!\n";
        } 
        else if (choice == 4) {
            for (int i = 0; i < bookCount; i++) {
                books[i].displayBook();
                cout << endl;
            }
        } 
        else if (choice == 5) {
            for (int i = 0; i < memberCount; i++) {
                members[i].displayMemberInfo();
                cout << endl;
            }
            for (int i = 0; i < specialMemberCount; i++) {
                specialMembers[i].displayMembershipDetails();
                cout << endl;
            }
        } 
        else if (choice == 6) {
            break;
        } else {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}




