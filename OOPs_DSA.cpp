#include<bits/stdc++.h> 
using namespace std;

#define ll long long
#define pii pair<int, int>
#define ff first
#define ss second

class Slot {
    public:
    int startTime;
    int endTime;
    vector<string> names;

    void addName(string name) {
        names.push_back(name);
    }
};

vector<Slot> solve(vector<Slot> ar) 
{    
    set<int> endPoints;
    map<int, unordered_set<string>> add;
    map<int, unordered_set<string>> del;
    for(Slot slot : ar) 
    {
        endPoints.insert(slot.startTime);
        add[slot.startTime].insert(slot.names[0]);
        endPoints.insert(slot.endTime);
        del[slot.endTime].insert(slot.names[0]);
    }
    int i=0, n = endPoints.size();
    set<string> curr;
    vector<Slot> res(n-1);
    for(auto it = endPoints.begin(); it != endPoints.end(); it++) {
        auto st = it, end = it;
        ++end;
        if(end == endPoints.end())
            break;
        res[i].startTime = *st;
        res[i].endTime = *end;
        
        if(add.count(*st)) {
            for(auto name : add[*st])
                curr.insert(name);
        }
        if(del.count(*st)) {
            for(auto name : del[*st])
                curr.erase(name);
        }
        for(auto it : curr)
            res[i].addName(it);
        i++;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<Slot> ar(n);
    for(int i=0; i<n; i++) {
        string name;
        cin >> name >> ar[i].startTime >> ar[i].endTime;
        ar[i].addName(name);
    }
    vector<Slot> res = solve(ar);
    for(Slot slot : res) {
       cout<<slot.startTime << " " << slot.endTime << " ";
       for(auto name : slot.names)
            cout << name << " ";
       cout<<"\n";
    }
    return 0;
}

/*
7
Amanda	10	100
Alex	30	40
Frank	50	120
George	70	90
Thomas	80	110
Henry	100	110
Susan	120	140

10 30 Amanda 
30 40 Alex Amanda 
40 50 Amanda 
50 70 Amanda Frank 
70 80 Amanda Frank George 
80 90 Amanda Frank George Thomas 
90 100 Amanda Frank Thomas 
100 110 Frank Henry Thomas 
110 120 Frank 
120 140 Susan 

*/