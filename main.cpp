#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct state
{
    int num;
    bool isfinal;
    vector<struct Arc> arcs;
};

struct Arc
{
    char symbol;
    struct state dest;
};



vector<struct state> creation_states ();
void creation_arcs(vector<struct state>);
void display (struct state);


int main()
{
    vector<struct state> Automate = creation_states();
    display(Automate[0]);
    return 0;
}


vector<struct state> creation_states()
{
    vector<struct state> states;
    string ans;
    cout << "voulez vous créer une etat ? (y/n) ";
    cin >> ans;
    while (ans == "y")
    {
        struct state x;
        cout << "donnez le numero d'etat : ";
        cin >> x.num;
        x.isfinal = false;
        states.push_back(x);
        cout << "voulez vous créer une etat ? (y/n) ";
        cin >> ans;
    }
    cout << "donnez les etats finals : ";
    cin >> ans;
    for (int i = 0; i < ans.length(); i += 2)
    {
        for (int j = 0; j < states.size(); j++)
        {
            if ((ans[i] - 48) == states[j].num)
            {
                states[j].isfinal = true;
            }
        }
    }
    creation_arcs(states);
    return states;
}


void creation_arcs (vector<struct state> states)
{
    string ans;
    cout << "voulez vous créer un arc ? (y/n) ";
    cin >> ans;
    while (ans == "y")
    {
        int n;
        cout << "donnez le numero de source d'arc ";
        cin >> n;
        for (int i = 0; i < states.size(); i++)
        {
            if (states[i].num == n)
            {
                int m;
                cout << "donnez le numero de destination d'arc ";
                cin >> m;
                for (int j = 0; j < states.size(); j++)
                {
                    if (states[j].num == m)
                    {
                        struct Arc arc;
                        arc.dest = states[j];
                        cout << "donnez le symbol d'arc : ";
                        cin >> arc.symbol;
                        states[i].arcs.push_back(arc);
                        break;
                    } 
                }
                break;
            }
        }
        cout << "voulez vous créer un arc ? (y/n) ";
        cin >> ans;
    }
}


void display (struct state states)
{
    if (states.isfinal == true)
    {
        return;
    }
    else
    {
        cout << states.num;
        int i = states.arcs.size();
        while (i != 0)
        {
            cout << "_____" << states.arcs[--i].symbol << "_____";
            display(states.arcs[i].dest);
            if (i > 0)
            {
                cout << endl;
                cout << "             ";
            }
        }
    }
}