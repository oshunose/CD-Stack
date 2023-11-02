#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>

using namespace std;

template <typename T>
class LinkedStack;

template <typename T>
class LinkedList;

template <typename T>
class Node;

class Entertainment;

class CD;

class DVD;

class Entertainment{
    protected:
        string artist; 
        string length;
        string genre;
    
    public:
        Entertainment(){};                                      // constructor
        Entertainment(string a, string b, string c){         
            artist = a;
            length = b; 
            genre = c;
        }         

        virtual void print(){                                   // print function template
            cout << "Artist: " << artist << endl;
            cout << "Length: " << length << endl;
            cout << "Genre: " << genre << endl;
        };                                   
};

class CD: public Entertainment{
    private:
        string album;
        string numsongs;

    public:
        CD(){};                     //constructor
        CD(string a, string b, string c, string d, string e): Entertainment(a,b,c){
            album = d;
            numsongs = e;
        }

        void print(){                                   // print function template
            cout << "Artist: " << artist << endl;
            cout << "Length: " << length << endl;
            cout << "Genre: " << genre << endl;
            cout << "Album: " << album << endl;
            cout << "Number of Songs: " << numsongs << endl;
        }

};

class DVD: public Entertainment{
    private:
        string movie;
        string cast;


    public:
        DVD(){};                                // constructor
        DVD(string a, string b, string c, string f, string g): Entertainment(a,b,c){
        movie = f; 
        cast = g;
        }

    void print(){                                   // print function
            cout << "Artist: " << artist << endl;
            cout << "Length: " << length << endl;
            cout << "Genre: " << genre << endl;
            cout << "Movie: " << movie << endl;
            cout << "Cast: " << cast << endl;
        }

};


template <typename T>
class Node{
    private:
        T elem;                                                     // Linked list element
        Node<T>* next;                                              // next item on linked list

    public:
        Node(){};                                                   // constructor
        Node(T e, T n){
            elem = e;
            next = n;
        }
    
    friend class LinkedList<T>;
};

template <typename T>
class LinkedList{
    private:
        Node<T> *head;
    public:
        LinkedList(){                           // constructor
            head = new Node<T>;
            head = NULL;
        }

        void front() const{                     // print front CD/DVD
            (head->elem)->print();
        }

        void addNode(T elem){                   // function to add a new CD/DVD to front of list
            Node<T> *newNode = new Node<T>;
            newNode -> elem = elem;
            newNode -> next = head;
            head = newNode;
        }
        
        bool empty() const {                       // check if stack is empty
        return head == NULL;
        }
        
        ~LinkedList() {                             // destructor
        while (!empty()){
            removeFront();
        };
        }

       
        void removeFront(){                      // remove front CD/DVD and make prev CD/DVD new front
            Node<T>* old = head;                  
            head = old->next;                    
            delete old;                         
        }

        void print(){                                   // print function to print all elements of stack
            if (head == NULL){                          // Checks if list is empty
                cout<< "The CD/DVD stack is empty" <<endl;
                return;
            }
            cout << "-----------------------------------------------" << endl;  
            Node<T> *loopNode = head;                               // loop through stack and print each CD/DVD
            while (loopNode != NULL){ 
                (loopNode->elem)->print();
                loopNode = loopNode -> next;
                cout << "-----------------------------------------------" << endl;
            }
        }

        friend class LinkedStack<T>;
        friend class CD;
        friend class DVD;
        friend class Entertainment;
};

template <typename T>
class LinkedStack{
    private:
        LinkedList<T> S;                        // create linked list object to call linked list functions
        int n;                                  // keep track of capacity
    public:
        LinkedStack(){                         // constructor
            n = 0;
        }
        T size() const{                         // size function that returns the size of stack
            return n;
        }
        bool empty() const{                     // checks if stack is empty
            return (n==0);
        }
        void top() const{                       // returns top of stack by calling linked list function removeFront
            if (empty() == 1){                  // checks if stack is empty
                cout << "The stack is empty" << endl;
            }
            else{
                cout << "-----------------------------------------------" << endl;
                S.front();
                cout << "-----------------------------------------------" << endl;
            }
        }
        void push(){                            // function to push CD/DVD to front of list
            int answer;
            
            cout << "Adding a CD(0) or DVD(1)?";    // use 0 or 1 for switch cases
        
            cin >> answer;
            if (cin.fail()){
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Error! Enter '1' or '0' next time."<<endl;
                return;
            }

            switch(answer){
                case 0: {                           // if "0", then ask user for information about the CD
                    cout << "Name of Artist: ";
                    cin.ignore();
                    string a;       // arist
                    getline(cin,a);
                    cout << "Length of album (00:00:00): ";
                    string b;       // length
                    getline(cin,b);
                    cout << "Genre: ";
                    string c;       // genre
                    getline(cin,c);
                    cout << "Album Name: ";
                    string d;           // album name
                    getline(cin,d);
                    cout << "Number of Songs: ";
                    string e;          // number of songs
                    getline(cin,e);
                    CD *nodeElem = new CD(a, b, c, d, e);       // create class pointer
                    n++;                                        // increase size
                    S.addNode(nodeElem);                        // use class pointer to add new node to stack linked list
                    break;
                }
                case 1: {                                       // if "1", then ask user for information about the DVD
                    cout << "Name of Director: ";
                    cin.ignore();
                    string a;       // arist
                    getline(cin,a);
                    cout << "Length of Movie (00:00:00): ";
                    string b;       // length
                    getline(cin,b);
                    cout << "Genre: ";
                    string c;       // genre
                    getline(cin,c);
                    cout << "Movie Name: ";
                    string f;       // movie
                    getline(cin,f);
                    cout << "Cast: ";
                    string g;       // cast
                    getline(cin,g);
                    DVD *nodeElem = new DVD(a, b, c, f, g);         // create class pointer
                    n++;                                            // increase size
                    S.addNode(nodeElem);                            // use class pointer to add new node to stack linked list
                    break;
                }           
                default:{                                           // if 1 or 0 isn't chosen then ask user to choose right options and return to main menu
                    cout << "Error! Enter '1' or '0' next time.";
                    return;
                }
            }
        }
        void pop(){                                     // function to delete top of stack
            if (empty()){                               // checks if stack is empty
                cout << "The stack is empty" << endl;
                return;
            }
            S.removeFront();                            // calls removeFront from LinkedList
            n--;                                        // decrease size
            cout << "Item successfully POPPED!" << endl;
        }
        void print(){                                   // print function
            S.print();
        }
    friend class CD;
    friend class DVD;
    friend class Entertainment;
};

int main(){
    LinkedStack<Entertainment*> e;          // create class pointer 
    
    // User Interface
    cout << "Hey! Operation Code: a for pushing new item to list, p for printing the list"
	  ", d for popping item fromqq the list, t for calling top of list; q for quit. If you input multiple letters, only the first letter will be considered.\n";
    char c;
    while (true) {
        cout << "Enter operational code: ";
        cin >> c;
        switch (c) {
        case 'a': e.push();
                    continue;
        case 'p': e.print();
                    break;
        case 'd': e.pop();
                    break;
        case 't': e.top();
                    break;
        case 'q':
            return 0;
        default:  cout << "Illegal code\n";
        }
        cout << "\n";
        cin.ignore(10000, '\n');
	}
}
