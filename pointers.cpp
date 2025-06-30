#include<iostream>
using namespace std;
struct furniture {
    char* name;
    int quantity;
};
struct room {
    int room_ID;
    char* room_name;
    int size;
    furniture* fur;
    int furniture_count;  
};
struct floor {
    int floor_ID;
    char* floor_name;
    room* r;
    int room_count;       
};
struct building {
    int building_ID;
    char* building_name;
    floor* f;
    int floor_count;      
};
void copystring(char* string,const char* temp){
    int i=0;
    while(temp[i]!='\0'){
        string[i]=temp[i];
        i++;
    }
    string[i]='\0';
}
int length(const char* temp){
    int i=0;
    while(temp[i]!='\0'){
        i++;
    }
    return i;
}
void add(building* b) {
    cout << "Enter ID for the building: ";
    cin >> b->building_ID;

    cout << "Enter the name of the building: ";
    cin.ignore();
    char temp[50];
    cin.getline(temp, 50);
    int len = length(temp);
    b->building_name = new char[len + 1];
    copystring(b->building_name, temp);

    cout << "How many floors you want to enter: ";
    int flo;
    cin >> flo;
    b->floor_count = flo;
    b->f = new floor[flo];

    for (int i = 0; i < flo; i++) {
        cout << "\n----- Enter details for floor " << i + 1 << " -----\n";
        cout << "Enter floor ID: ";
        cin >> b->f[i].floor_ID;
        cin.ignore();
        cout << "Enter the name of the floor: ";
        cin.getline(temp, 50);
        len = length(temp);
        b->f[i].floor_name = new char[len + 1];
        copystring(b->f[i].floor_name, temp);

        cout << "How many rooms in this floor: ";
        int roo;
        cin >> roo;
        b->f[i].room_count = roo;
        b->f[i].r = new room[roo];
        for (int j = 0; j < roo; j++) {
            cout<<"\n-----Enter details for Room "<<j+1<<"-----\n";
            cout << "Enter room ID: ";
            cin >> b->f[i].r[j].room_ID;
            cin.ignore();
            cout << "Enter room name: ";
            cin.getline(temp, 50);
            len = length(temp);
            b->f[i].r[j].room_name = new char[len + 1];
            copystring(b->f[i].r[j].room_name, temp);
            cout<<"Enter room size: ";
            cin>>b->f[i].r[j].size;
            cout << "How many furniture items in this room: ";
            int furnit;
            cin >> furnit;
            b->f[i].r[j].furniture_count = furnit;
            b->f[i].r[j].fur = new furniture[furnit];

            for (int k = 0; k < furnit; k++) {
                cout << "Enter furniture name: ";
                cin.ignore();
                cin.getline(temp, 50);
                len = length(temp);
                b->f[i].r[j].fur[k].name = new char[len + 1];
                copystring(b->f[i].r[j].fur[k].name, temp);

                cout << "Enter quantity: ";
                cin >> b->f[i].r[j].fur[k].quantity;
            }
        }
    }
}

void display(building* b) {
    cout<<"\n-------DISPLAYING DETAILS--------\n";
    cout << "The ID for the building: " << b->building_ID << endl;
    cout << "The name of the building: " << b->building_name << endl;
    cout << "The number of floors: " << b->floor_count << endl;
    for (int i = 0; i < b->floor_count; i++) {
        cout << "\n----- Floor " << i + 1 << " -----\n";
        cout << "Floor name: " << b->f[i].floor_name << endl;
        cout << "Number of rooms: " << b->f[i].room_count << endl;
        for (int j = 0; j < b->f[i].room_count; j++) {
            cout<<"\n----- Room "<<j+1<<" -----\n";
            cout << "Room name: " << b->f[i].r[j].room_name << "     Room size: "<<b->f[i].r[j].size<<endl;
            cout << "Number of furniture items: " << b->f[i].r[j].furniture_count << endl;
            for (int k = 0; k < b->f[i].r[j].furniture_count; k++) {
                cout << "Furniture name: " << b->f[i].r[j].fur[k].name << "     Quantity: " << b->f[i].r[j].fur[k].quantity << endl;
            }
        }
    }
}
void displaying_area(building* b){
    cout<<"\n--------DISPLAYING THE AREA--------\n";
    int size_of_building=0;
    for (int i = 0; i < b->floor_count; i++) {
        int sum_of_size=0;
        for (int j = 0; j < b->f[i].room_count; j++) {
            sum_of_size+=b->f[i].r[j].size;
            size_of_building+=b->f[i].r[j].size;
        }
        cout<<"the total area of floor "<<i+1<<": "<< sum_of_size<<" square meter"<<endl;
    }
    cout<<"the total area of building is: "<< size_of_building<<" square meter"<<endl;
}
void deleting_memory(building* b) {
    for (int i = 0; i < b->floor_count; i++) {
        for (int j = 0; j < b->f[i].room_count; j++) {
            for (int k = 0; k < b->f[i].r[j].furniture_count; k++) {
                delete[] b->f[i].r[j].fur[k].name; 
            }
            delete[] b->f[i].r[j].fur;             
            delete[] b->f[i].r[j].room_name;       
        }
        delete[] b->f[i].r;                       
        delete[] b->f[i].floor_name;             
    }
    delete[] b->f;                            
    delete[] b->building_name;               
    delete b;                                       
}
int main(){
    building* b=new building;
    add(b);
    display(b);
    displaying_area(b);
    deleting_memory(b);
    return 0;
}
