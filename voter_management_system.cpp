#include <iostream>
#include <cmath>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;
#define MAX_VOTERS 1000
#define MAX_CANDIDATES 5
struct Voter{
    int id;
    string name;
    int age;
    bool has_voted;
    string vote;
};
struct Candidate{
    int id;
    string name;
    int votes;
};

void load_voters(Voter* s[], const string& filename){
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Could not open the file!" << endl;
        return;
    }

    int i = 0;
    while (i < MAX_VOTERS) {
        s[i] = new Voter;
        file >> s[i]->id;
        if (file.fail()) {
            delete s[i];
            s[i] = nullptr;
            break;
        }
        file.ignore();
        getline(file, s[i]->name);
        file >> s[i]->age;
        file >>s[i]->has_voted;
        if(s[i]->has_voted)
            file>>s[i]->vote;
        file.ignore();
        i++;
    }
    file.close();
}
void load_candidates(Candidate* s[], const string& filename){
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Could not open the file!" << endl;
        return;
    }

    int i = 0;
    while (i < MAX_CANDIDATES) {
        s[i] = new Candidate;
        file >> s[i]->id;
        if (file.fail()) {
            delete s[i];
            s[i] = nullptr;
            break;
        }
        file.ignore();
        getline(file, s[i]->name);
        file>>s[i]->votes;
        file.ignore();
        i++;
    }
    file.close();
}

void save_candidates(Candidate* s[], const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Could not open the file!" << endl;
        return;
    }

    for (int i = 0; i < MAX_CANDIDATES; i++) {
         if (s[i] != nullptr && s[i]->id != -1){
            file << s[i]->id << endl;
            file << s[i]->name << endl;
            file << s[i]->votes <<endl;

        }
    }
    file.close();
}
void save_voters(Voter* s[], const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Could not open the file!" << endl;
        return;
    }

    for (int i = 0; i < MAX_VOTERS; i++) {
         if (s[i] != nullptr && s[i]->id != -1){
            file << s[i]->id << endl;
            file << s[i]->name << endl;
            file << s[i]->age << endl;
            file << s[i]->has_voted <<endl;
            if(s[i]->has_voted)
                file << s[i]->vote <<endl;

        }
    }
    file.close();
}
bool register_voter(Voter*v[],const string filename){
    for(int i=0;i<MAX_VOTERS;i++)
        if(v[i]==nullptr){
            v[i]=new Voter;
            v[i]->id=i+1;
            cout<<"Enter voter's name : ";
            cin.ignore();
            getline(cin,v[i]->name);
            cout<<"Enter voter's age : ";
            cin>>v[i]->age;
            while(v[i]->age<18){
                cout<<"Enter valid voter's age (above 18): ";
                cin>>v[i]->age;
            }
            v[i]->has_voted=false;
            v[i]->vote=" ";
            cout<<"<-----------voter registered successfully----------------->\n";
            save_voters(v,filename);
            return true;
        }
    cout<<"<------------no vacant space for voters------------->\n";   
    return false; 
}

bool add_candidate(Candidate*c[],const string filename){
    for(int i=0;i<MAX_CANDIDATES;i++)
        if(c[i]==nullptr){
            c[i]=new Candidate;
            cout<<"Enter candidate's name : ";
            cin.ignore();
            getline(cin,c[i]->name);
            c[i]->id=i+1;
            c[i]->votes=0;
            cout<<"<-----------candidate registered successfully----------------->\n";
            save_candidates(c,filename);
            return true;
        }
    cout<<"<------------no vacant space for candidates------------->\n";
    return false;
}
void display_voters(Voter* v[]){
    for(int i=0;i<MAX_VOTERS;i++){
        if(v[i]!=nullptr){
            cout<<"<--------------------------->"<<endl;
            cout<<"Voter ID :      "<<v[i]->id<<endl;
            cout<<"Voter Name :    "<<v[i]->name<<endl;
            cout<<"voter Age :     "<<v[i]->age<<endl;
            if(v[i]->has_voted)
                cout<<"voter voted for : "<<v[i]->vote<<endl;
            else    
                cout<<"voter hasn't voted yet....  "<<endl;
            cout<<"<--------------------------->"<<endl;
        }
    }
}
void display_candidates(Candidate* v[]){
    for(int i=0;i<MAX_CANDIDATES;i++){
        if(v[i]!=nullptr){
            cout<<"<--------------------------->"<<endl;
            cout<<"Candidate ID :    "<<v[i]->id<<endl;
            cout<<"Candidate Name :  "<<v[i]->name<<endl;
            cout<<"Candidate votes : "<<v[i]->votes<<endl;
            cout<<"<--------------------------->"<<endl;
        }
    }
}
bool cast_vote(Voter*v[],Candidate*c[],int id,const string filename1,const string filename2){
    for(int i=0;i<MAX_VOTERS;i++){
        if(v[i]!=nullptr && v[i]->id==id)
            if(!v[i]->has_voted){
                cout<<"Enter candidate id you want to vote from the list below : "<<endl;
                for(int j=0;j<MAX_CANDIDATES;j++){
                    if(c[j]!=nullptr){
                        cout<<c[j]->id<<" "<<c[j]->name<<endl;
                    }
                }
                int _id;
                cout<<"candidate ID : ";
                cin>>_id;
                while(_id<=0 || _id>MAX_CANDIDATES){
                    cout<<"invalid candidate ID"<<endl;
                    cout<<"Enter valid candidate ID : ";
                    cin>>_id;
                }
                int j;
                for(j=0;j<MAX_CANDIDATES;j++){
                    if(c[j]!=nullptr && c[j]->id==_id){
                        c[j]->votes++;
                        v[i]->has_voted=true;
                        v[i]->vote=c[j]->name;
                    }
                }
                if(!v[i]->has_voted){
                    while(_id>j){
                        cout<<"invalid candidate ID"<<endl;
                        cout<<"Enter valid candidate ID : ";
                        cin>>_id;
                    }
                    for(j=0;j<MAX_CANDIDATES;j++){
                        if(c[j]!=nullptr && c[j]->id==_id){
                            c[j]->votes++;
                            v[i]->has_voted=true;
                            v[i]->vote=c[j]->name;
                        }
                    }
                }
                cout<<"Vote has been casted successfully......"<<endl;
                save_candidates(c,filename2);
                save_voters(v,filename1);

                return true;
            }
            else{
                cout<<"You have already voted........"<<endl;
                return false;
            }

    }
    cout<<"voter not found........"<<endl;
    return false;
}

void display_result(Candidate*c[]){
    int max=0;
    for(int i=0;i<MAX_CANDIDATES;i++){
        if(c[i]!=nullptr && c[i]->votes>=max){
           max=c[i]->votes;
        }
    }
    display_candidates(c);
    for(int i=0;i<MAX_CANDIDATES;i++){
        if(c[i]!=nullptr&&c[i]->votes==max){
            cout<<c[i]->name<<" has won the election"<<endl;
        }
    }
}




int main(){
    Voter* v[MAX_VOTERS];

    Candidate* c[MAX_CANDIDATES];
    for(int i=0;i<MAX_VOTERS;i++){
        v[i]=nullptr;
        if(i<MAX_CANDIDATES)
            c[i]=nullptr;
    }

    const string filename1="voters.txt";
    const string filename2="candidates.txt";
    load_voters(v,filename1);
    load_candidates(c,filename2);
    cout<<"<------------------------------------- Menu --------------------------------------------->"<<endl<<endl;
    cout<<"To add candidate:      1"<<endl;
    cout<<"To register voter:     2"<<endl;
    cout<<"To display voters:     3"<<endl;
    cout<<"To cast vote:          4"<<endl;
    cout<<"To display candidates: 5"<<endl;
    cout<<"To display results:    6"<<endl;
    cout<<"<---------------------------------------------------------------------------------------->"<<endl<<endl;
    cout<<"Enter the total number of operations you want to perform :";
    int op;
    cin>>op;
    while(op--){
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                add_candidate(c,filename2);
                break;
            case 2:
                register_voter(v,filename1);
                break;
            case 3:
                display_voters(v);
                break;
            case 4:
                cout<<"Enter voter ID :";
                int id;
                cin>>id;
                cast_vote(v,c,id,filename1,filename2);
                break;
            case 5:
                display_candidates(c);
                break;
            case 6:
                display_result(c);
                break;
            default:
                cout<<"Invalid choice"<<endl;


        }
    }


    for(int i=0;i<MAX_VOTERS;i++){
        if(v[i]!=nullptr)
            delete v[i];
        if(c[i]!=nullptr && i<MAX_CANDIDATES)
            delete c[i];
    }
}