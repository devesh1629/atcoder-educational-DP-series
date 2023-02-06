#include<bits/stdc++.h> 
using namespace std;

#define ll long long
#define pii pair<int, int>
#define ff first
#define ss second
#define N 200009

ll gcd(ll a, ll b) {
    if(b==0)    
        return a;
    return gcd(b, a%b);
}

struct Slot {
    int startTime;
    int endTime;
    string name;
};
map<pair<int, int>, set<string>> solve(vector<Slot> ar) 
{    
    set<int> endPoints;
    map<int, vector<string>> add;
    map<int, vector<string>> del;
    for(Slot it : ar) 
    {
        endPoints.insert(it.startTime);
        add[it.startTime].push_back(it.name);
        endPoints.insert(it.endTime);
        del[it.endTime].push_back(it.name);
    }

    map<pair<int, int>, set<string>> res;
    for(auto it = endPoints.begin(); it != endPoints.end(); it++) {
        auto st = it, end = it;
        ++end;
        if(end == endPoints.end())
            break;
        res[{*st, *end}].insert({});
    }
    set<string> curr;
    for(auto it : res) {
        int st = it.first.first;
        int end = it.first.second;
        if(add.count(st)) {
            for(auto name : add[st]) {
                curr.insert(name);
            }
        }
        if(del.count(st)) {
            for(auto name : del[st])
                curr.erase(name);
        }
        res[{st, end}] = curr;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<Slot> ar(n);
    for(int i=0; i<n; i++) {
        cin >> ar[i].name >> ar[i].startTime >> ar[i].endTime;
    }
    map<pair<int, int>,set<string>> res = solve(ar);
    for(auto it : res) {
        set<string> names = it.second;
        cout<<it.first.first << " " << it.first.second << " ";
        for(auto name : names)
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

=====
Used: 0 ms, 144 KB
*/