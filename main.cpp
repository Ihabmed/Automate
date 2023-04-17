#include <iostream>
#include <vector>

using namespace std;

struct Arc
{
    char symbol;
    struct state *dest;
};

struct state
{
    int num;
    bool isfinal;
    vector<struct Arc*> arcs;
};

struct automate
{
    struct etate** auto;
    int n;
};

struct automate creation_etats();
void creation_arcs(struct automate);
void display (struct state*);


int main()
{
    /*struct state *s0 = new struct state;
    struct state *s1 = new struct state;
    struct state *s2 = new struct state;
    struct state *s3 = new struct state;
    struct Arc *a0 = new struct Arc;
    struct Arc *a1 = new struct Arc;
    struct Arc *a2 = new struct Arc;
    s0->num = 0;
    s1->num = 1;
    s2->num = 2;
    s3->num = 3;
    s0->isfinal = false;
    s1->isfinal = false;
    s2->isfinal = true;
    s3->isfinal = true;
    a0->symbol = 'a';
    a1->symbol = 'b';
    a2->symbol = 'c';
    a0->dest = s1;
    a1->dest = s2;
    a2->dest = s3;
    s0->arcs.push_back(a0);
    s1->arcs.push_back(a1);
    s1->arcs.push_back(a2);*/
    struct automate input = creation_etats();
    display(input);
    return 0;
}


void display (struct automate s)
{
    if (s[j].auto == NULL)
    {
        cout << "automate vide";
    }
    else
    {
        cout << s[j]->auto->num;
        int i = s[j]->auto->arcs.size();
        while (i != 0)
        {
            cout << "_____" << s[j]->auto->arcs[--i]->symbol << "_____";
            display(s[j]->auto->arcs[i]->dest);
            if (i > 0)
            {
                cout << endl;
                cout << "             ";
            }
        }
    }
}


struct automate creation_etats()
{
    int n;
    cout << "donnez le nombre d'etate dans l'automate : ";
    cin >> n;
    struct state *etats[n];
    for (int i = 0; i < n; i++)
    {
        cout << "donnez le numero d'etate " + (i + 1) + " : ";
        cin >> etats[i]->num;
        etats[i]->isfinal = false;
        char choix;
        cout << "est-ce-que l'etat " + (i + 1) + "est fini ? (y/n) ";
        cin >> choix;
        if (choix == 'y')
        {
            etats[i]->isfinal = true;
        }
    }
    struct automate output;
    output.auto = etats;
    output.n = n;
    return output;
}