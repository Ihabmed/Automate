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

void display (struct state *s)
{
    if (s == NULL)
    {
        cout << "automate vide";
    }
    else
    {
        cout << s->num;
        int i = s->arcs.size();
        while (i != 0)
        {
            cout << "_____" << s->arcs[--i]->symbol << "_____";

            display(s->arcs[i]->dest);
            if (i > 0)
            {
                cout << endl;
                cout << "             ";
            }
        }
    }
}

int main()
{
    struct state *s0 = new struct state;
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
    s1->arcs.push_back(a2);
    display(s0);
    return 0;
}
