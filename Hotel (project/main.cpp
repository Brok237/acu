#include <iostream>

using namespace std;
int total=0;

// making a new data type as  a room
struct node{
int rn=NULL;
string name;;
int days;
char type;
node*next;
};
node*master=NULL;

//to declare number of rooms in hotel making the linked list limited
// it will take   int n (the number of rooms), char type(single or double) , int x( needed to continue counting rooms in double after single rooms)
void rooms(int n,char type,int x){//like create rooms
    node*temp=master;

    if (type=='s'){
for (int i = 0; i <= n-1; i++) {
        x=0;
        node* newRoom = new node;
        newRoom->rn = i;
        newRoom->name = "NULL";
        newRoom->days = 0;
        newRoom->type='s';
        newRoom->next = NULL;

        if (master == NULL) {
            master = newRoom;
        } else {
            node* temp = master;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newRoom;
        }

    }

}
else if (type=='d'){

        for (int i = x; i <=(x+n-1) ; i++) {
        node* newRoom = new node;
        newRoom->rn = i;
        newRoom->name = "NULL";
        newRoom->days = 0;
        newRoom->type='d';
        newRoom->next = NULL;

        if (master == NULL) {
            master = newRoom;
        } else {
            node* temp = master;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newRoom;
        }
    }

}}


//check if rooms are fully booked or not( in the case of single or double rooms)


bool isfull(char type) {
    cout<<endl;
    node* temp = master;
    if (type=='s'){
    while (temp != NULL&&temp->type=='s') {
        if (temp->name == "NULL" || temp->days == 0) {
            return false;
        }
        temp = temp->next;
    }}
    else if (type=='d'){

    node* temp = master;
    while(temp!=NULL&&temp->type=='s'){
        temp=temp->next;
    }
    while (temp != NULL&&temp->type=='d') {
        if (temp->name == "NULL" || temp->days == 0) {
            return false;
        }
        temp = temp->next;
    }}
    return true;
}


// check in (reserve rooms) as the bill of the rooms differs  between single or double
// it take  string name( name of guest) , int days( number of dayes guest is going to stay) , char type( single or double)


void check_in(string name, int days, char type) {

    char t = type;
    node* temp = master;  // Declare temp before the switch statement

        switch (t) {
        case 's':
            while (temp != NULL) {
                if (temp->name == "NULL" && temp->type == 's') {
                    temp->name = name;
                    temp->days = days;
                    break;
                } else
                    temp = temp->next;
            }
            break;
        case 'd':
            while (temp != NULL) {
                if (temp->name == "NULL" && temp->type == 'd') {
                    temp->name = name;
                    temp->days = days;
                    break;
                } else
                    temp = temp->next;
            }
            break;
        }
        cout<<endl;

}
// find rooms data by room name ( if more than one room have the same  name all will be displayed)
void find_guest(int x){
node*temp=master;
bool found =false;
while(temp!=NULL){
    if (temp->rn==x){
    cout<<endl<<"room number : "<<temp->rn<<endl;
    cout<<" Name : "<<temp->name<<endl;
    cout<<" number of days: "<<temp->days<<endl;
    cout<<" Room type : "<<temp->type<<endl;
    found= true;

    }
     temp=temp->next;
}
if (!found){
    cout<<" no room with this number "<<endl;
}
}
// find room data by the room number
void find_guest(string x){
node*temp=master;
bool found =false;
while(temp!=NULL){
    if (temp->name==x ){
    cout<<endl<<"room number : "<<temp->rn<<endl;;
    cout<<" Name : "<<temp->name<<endl;
    cout<<" number of days: "<<temp->days<<endl;
    cout<<" Room type : "<<temp->type<<endl;
    found= true;

    }
    temp=temp->next;
}
if (!found){
    cout<<" no  guest with this name"<<endl;
}
}

void checkout(int x){
    cout<<endl;
    int bill;
    bool found=false;
node*temp=master;
while(temp!=NULL){
    if(temp->rn==x){
        temp->name="NULL";
        if(temp->type=='s'){
        bill=100*temp->days;
        total+=bill;
        }
        else if(temp->type=='d'){
            bill =200*temp->days;
        total+=bill;
        }
        temp->days=0;
        found=true;
        break;

    }

    temp=temp->next;
}
if(!found){
    cout<<"room not found"<<endl;
}
cout<<"total bill = "<<bill<<" Egp"<<endl;


}


//check out ( empty a room & output the bill and adding the bill to the total income)

void checkout(string x){
    cout<<endl;
    int bill,rooms=0;
    int r;
    bool found= false;
node*temp=master;
while(temp!=NULL){
    if(temp->name==x){
            rooms++;
            found=true;

    }
    temp=temp->next;
}
if (!found) {
    cout << "There is no guest with this name here." << endl;
} else {
    if (rooms == 1) {
        node* temp = master;
        while (temp != NULL) {
            if (temp->name == x) {
                temp->name = "NULL";
                if (temp->type == 's') {
                    bill = 100 * temp->days;
                    total += bill;
                } else if (temp->type == 'd') {
                    bill = 200 * temp->days;
                    total += bill;
                }
                temp->days = 0;
                cout << "Total bill = " << bill << " Egp" << endl;
                break;
            }
            temp = temp->next;
        }
    } else if (rooms > 1) {
        while (true) {
            find_guest(x);
            cout << "Please select which room (enter -1 to exit): ";
            cin >> r;

            if (r == -1) {
                break;
            }

            checkout(r);
        }
    }
}}



// function to count number of empty rooms of single & double types

void countEmptyRooms() {
    int emptySingleRooms = 0;
    int emptyDoubleRooms = 0;

    node* temp = master;

    while (temp != NULL) {
        if (temp->type == 's' && temp->name == "NULL") {
            emptySingleRooms++;
        } else if (temp->type == 'd' && temp->name == "NULL") {
            emptyDoubleRooms++;
        }
        temp = temp->next;
    }

    cout << "Empty Single Rooms: " << emptySingleRooms << endl;
    cout << "Empty Double Rooms: " << emptyDoubleRooms << endl;
}

// function to count number of reserved rooms of single and double types
void countReservedRooms() {
    int reservedSingleRooms = 0;
    int reservedDoubleRooms = 0;

    node* temp = master;

     while (temp != NULL) {
        if (temp->type == 's' && temp->name != "NULL") {
            reservedSingleRooms++;
        } else if (temp->type == 'd' && temp->name != "NULL") {
            reservedDoubleRooms++;
        }
        temp = temp->next;
    }
    cout << "Reserved Single Rooms: " << reservedSingleRooms << endl;
    cout << "Reserved Double Rooms: " << reservedDoubleRooms << endl;
}





//function to display the rooms including the name of guest,number of days he is staying and the type of room

void display_rooms(){

node*temp=master;
while(temp!=NULL){
    cout<<endl<<"room number : "<<temp->rn<<endl;;
    cout<<" Name : "<<temp->name<<endl;
    cout<<" number of days: "<<temp->days<<endl;
    cout<<" Room type : "<<temp->type<<endl;
    cout<<"************************************************************************************************************************"<<endl;
    temp=temp->next;
}
cout<<endl;
}

int main()
{
    int n,N,days,room;
    char type,op,k;
    string name;
    string x;
    bool loop=true;
    cout<<"**************************************************  welcome to Hotel  **************************************************"<<endl;


    cout<<"please enter number of single rooms rooms : ";
    cin>>n;
    rooms(n,'s',0);
    N=n;
    cout<<"please enter number of double rooms rooms rooms : ";
    cin>>n;
    rooms(n,'d',N);

    while(loop){
        cout<<"check-in(i),check-out(o),display rooms(d),total income(t),NO.of reserved rooms(r),NO.of empty rooms(e),find(f)or quit(q) "<<endl;
    cin>>op;
    switch (op){
    case 'i':
        cout<<"single (s) or double (d)"<<endl;

    cin>>type;
    if(type=='s'){
            if(isfull(type)){cout<<"sorry single rooms are fully booked ."<<endl;}
            else{
    cout<<"please enter your name and number of days you are staying"<<endl;
    cout<<"Name: ";cin>>name;
    cout<<"days: ";cin>>days;
    check_in(name,days,'s');}}
    else if(type=='d'){
            if(isfull(type)){cout<<"sorry double rooms are fully booked ."<<endl;}
            else{
    cout<<"please enter your name and number of days you are staying"<<endl;
      cout<<"Name: ";cin>>name;
    cout<<"days: ";cin>>days;
    check_in(name,days,'d');}}
    else {
        cout<<" wrong room type"<<endl;
    }
    break;

    case 'o':
        cout<<" by room number(r) or guest name(n)?"<<endl;
        cin>>k;
        switch(k){
        case 'n':
        cout<<"please enter the guest name for checkout??"<<endl;
        cin>>name;
        checkout(name);
        break;
        case 'r':
            cout<<"enter room number : ";
            cin>>room;
            checkout(room);
            break;
        default:
            cout<<"incorrect input";
            break;}
            break;
    case 'd' :
        display_rooms();
        break;

    case 't':
        cout<<" todays total income = "<<total<<endl;
        break;
    case 'r':
        countReservedRooms();
        break;
    case 'e':
        countEmptyRooms();
        break;
    case 'f':
        cout<<"do you know the room number(r) or the guest name(n)?"<<endl;
        cin >>k;
        switch (k){
        case 'r':
            cout<< " room number: ";
            cin>>room;
            find_guest(room);
            break;
        case 'n':
            cout<<"guest name : ";
            cin>>name;
            find_guest(name);
            break;
        default:
        cout << "Incorrect input. Please enter a valid option." << endl;
        break;
        }
        break;

    case 'q':
        cout<<"thank you";
        loop=false;
        break;

    default:
        cout << "Incorrect input. Please enter a valid option." << endl;
        break;}
    }



   return 0;

}
