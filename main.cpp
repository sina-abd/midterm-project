#include <iostream>
#include "genome.h"
#include "cell.h"
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    Genome genome;
    Cell cell;
    cout << "welcome to the mid-term projct\n";
    int a;
    cout << "enter 1 to use Genome class, enter 2 to use Cell class, enter 3 to use Animal class, enter 4 to use Virus class\n";
    cin >> a;
    if(a == 1){
        cout << "Genome class\n";
        cout << "enter rna\n";
        cin >> genome.rna;
        cout << "enter dna1(dna at index 0)\n";
        cin >> genome.dna[0];
        cout << "enter dna2(dna at index 1)\n";
        cin >> genome.dna[1];
        cout << "type 1 to use dna_built_by_rna, type 2 to use small_mutation, type 3 to use big_mutation, type 4 to use reverse_mutation\n";
        int b;
        cin >> b;
        if(b == 1){
            genome.dna_built_by_rna();
            cout << endl;
        }else if(b == 2){
            cout << "enter first letter\n";
            char c;
            cin >> c;
            cout << "enter second letter\n";
            char d;
            cin >> d;
            cout << "enter the times you want to raplace\n";
            int e;
            cin >> e;
            genome.small_mutation(c, d, e);
            cout << endl;
        }else if(b == 3){
            cout << "enter first string\n";
            string f;
            cin >> f;
            cout << "enter second string\n";
            string g;
            cin >> g;
            genome.big_mutation(f, g);
            cout << endl;
        }else if(b == 4){
            cout << "enter first string\n";
            string h;
            cin >> h;
            genome.reverse_mutation(h);
            cout << endl;
        }
    }else if(a == 2){
        cout << "Cell class\n";
        cout << "enter data\n";
        cell.save_chromosome_data();
        cout << "type 1 to use cell_death, type 2 to use big_mutation, type 3 to use small_mutation, type 4 to use reverse_mutation and type 5 to use palindrome_finder\n";
        int i;
        cin >> i;
        if(i == 1){
            cell.cell_death(cell);
            cout << "cell deleted\n";
        }else if(i == 2){
            string g, l;
            int k, m;
            cout << "enter first string\n";
            cin >> g;
            cout << "enter first int\n";
            cin >> k;
            cout << "enter second string\n";
            cin >> l;
            cout << "enter seccond int\n";
            cin >> m;
            cell.big_mutation(g, k, l, m);
            cout << endl;
        }else if(i == 3){
            char n, o;
            int p, q;
            cout << "enter first char\n";
            cin >> n;
            cout << "enter second char\n";
            cin >> o;
            cout << "enter times you want to find\n";
            cin >> p;
            cout << "enter the number of chromosome you want\n";
            cin >> q;
            cell.small_mutation(n, o, p, q);
            cout << endl;
        }else if(i == 4){
            string r;
            int s;
            cout << "enter the substring you want to reverse\n";
            cin >> r;
            cout << "enter the number of chromosome you want\n";
            cin >> s;
            cell.reverse_mutation(r, s);
            cout << endl;
        }else if(i == 5){
            int t;
            cout << "enter the number of chromosome you want\n";
            cin >> t;
            cell.palindrome_finder(t);
            cout << endl;
        }
    }else if(a == 3){

    }else if(a == 4){

    }

    return 0;
}
