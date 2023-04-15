#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED
#include <iostream>

using namespace std;

class Cell: public Genome{
public:
    vector <Genome> chromosome_l;
    void save_chromosome_data(){
        int a;
        cout << "enter the number of chromosomes\n";
        cin >> a;
        for(int i = 0; i < a; i++){
            Genome chromosome;
            cout << "enter dna1(dna at index 0)\n";
            cin >> chromosome.dna[0];
            cout << "enter dna2(dna at index 1)\n";
            cin >> chromosome.dna[1];
            cout << endl;
            chromosome.rna = "";
            chromosome_l.push_back(chromosome);
        }
    }
    void cell_death(Cell &cell){
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for(int i = 0; i < chromosome_l.size(); i++){
            for(int j = 0; j < chromosome_l[i].dna[0].length(); i++){
                int x;
                if((cell.dna[0][j] == 'A' && cell.dna[1][j] == 'T') || (cell.dna[0][j] == 'T' && cell.dna[1][j] == 'A') || (cell.dna[0][j] == 'G' && cell.dna[1][j] == 'C') || (cell.dna[0][j] == 'C' && cell.dna[1][j] == 'G')){
                    continue;
                }else{
                    cnt1++;
                }
                if((cell.dna[0][j] == 'A' && cell.dna[1][j] == 'T') || (cell.dna[0][j] == 'T' && cell.dna[1][j] == 'A')){
                    cnt2++;
                }else if((cell.dna[0][j] == 'G' && cell.dna[1][j] == 'C') || (cell.dna[0][j] == 'C' && cell.dna[1][j] == 'G')){
                    cnt3++;
                }
        }}
        //cout << cnt1 << endl << cnt2 << endl << cnt3;
            if(cnt1 >= 5 || (cnt2 >= cnt3*3)){
                chromosome_l.clear();
            }
        }

            void big_mutation(string s1, int n, string s2, int m){
                int a, b, c, d;
                string e, f;
                if(chromosome_l[n].dna[0].find(s1) != string::npos || chromosome_l[n].dna[1].find(s1) != string::npos){
                    if(chromosome_l[n].dna[0].find(s1) < chromosome_l[n].dna[1].find(s1)){
                        a = chromosome_l[n].dna[0].find(s1);
                        c = 0;
                    }else{
                        a = chromosome_l[n].dna[1].find(s1);
                        c = 1;
                    }
                    for(int i = a; i < a + s1.length(); i++){
                        e += chromosome_l[n].dna[c][i];
                    }
                }else{
                    cout << "no match in chromosome n";
                }
                if(chromosome_l[m].dna[0].find(s2) != string::npos || chromosome_l[m].dna[1].find(s2) != string::npos){
                    if(chromosome_l[m].dna[0].find(s2) < chromosome_l[m].dna[1].find(s2)){
                        b = chromosome_l[m].dna[0].find(s2);
                        d = 0;
                    }else{
                        b = chromosome_l[m].dna[1].find(s2);
                        d = 1;
                    }
                    for(int i = b; i < b + s2.length(); i++){
                        f += chromosome_l[m].dna[d][i];
                    }
                }else{
                    cout << "no match in chromosome m";
                }
                cout << f << endl << e <<endl;
                for(int i = a; i < a + s1.length(); i++){
                    chromosome_l[n].dna[c][i] = f[i-a];
                }
                for(int i = b; i < b + s2.length(); i++){
                    chromosome_l[m].dna[d][i] = e[i-b];
                }
            }
            void small_mutation(char a, char b, int n, int m){
                int cnt = 0;
                for(int i = 0; i < chromosome_l[m].dna[0].length(); i++){
                    cout << cnt << endl;
                    if(cnt < n){
                        if(chromosome_l[m].dna[0][i] == a){
                            if(a == 'A' && chromosome_l[m].dna[0][i] == 'A'){
                                chromosome_l[m].dna[1][i] = 'T';
                            }else if(a == 'T' && chromosome_l[m].dna[0][i] == 'T'){
                                chromosome_l[m].dna[1][i] = 'A';
                            }else if(a == 'C' && chromosome_l[m].dna[0][i] == 'C'){
                                chromosome_l[m].dna[1][i] = 'G';
                            }else if(a == 'G' && chromosome_l[m].dna[0][i] == 'G'){
                                chromosome_l[m].dna[1][i] = 'C';
                            }
                            chromosome_l[m].dna[0][i] = b;
                            cnt++;
                    }else if(chromosome_l[m].dna[1][i] == a){
                            if(a == 'A' && chromosome_l[m].dna[1][i] == 'A'){
                                chromosome_l[m].dna[0][i] = 'T';
                            }else if(a == 'T' && chromosome_l[m].dna[1][i] == 'T'){
                                chromosome_l[m].dna[0][i] = 'A';
                            }else if(a == 'C' && chromosome_l[m].dna[1][i] == 'C'){
                                chromosome_l[m].dna[0][i] = 'G';
                            }else if(a == 'G' && chromosome_l[m].dna[1][i] == 'G'){
                                chromosome_l[m].dna[0][i] = 'C';
                            }
                            chromosome_l[m].dna[1][i] = b;
                            cnt++;
                        }
                    }
                }
            }
                void reverse_mutation(string s1, int n){
                    string s2, s3;
                    if(chromosome_l[n].dna[0].find(s1) < chromosome_l[n].dna[1].find(s1)){
                        if(chromosome_l[n].dna[0].find(s1) != string::npos){
                            int cnt = chromosome_l[n].dna[0].find(s1);
                            for(int i = cnt+s1.length()-1; i >= cnt; i--){
                                s2 += chromosome_l[n].dna[0][i];
                            }
                            for(int i = cnt; i < cnt+s1.length(); i++){
                                chromosome_l[n].dna[0] = s2[i-cnt];
                            }
                        }else{
                            cout << "no match in dna1";
                        }
                    }else{
                        if(chromosome_l[n].dna[1].find(s1) != string::npos){
                            int cnt = chromosome_l[n].dna[1].find(s1);
                            for(int i = cnt+s1.length()-1; i >= cnt; i--){
                                s3 += chromosome_l[n].dna[1][i];
                            }
                            for(int i = cnt; i < cnt+s1.length(); i++){
                                chromosome_l[n].dna[1][i] = s3[i-cnt];
                            }
                        }else{
                            cout << "no match in dna2";
                        }
                    }
                }
                void palindrome_finder(int a){
                    string s1, s2, s3, hold;
                    int cnt = 0;
                    s1 = chromosome_l[a].dna[0];
                    s2 = chromosome_l[a].dna[1];
                    for(int i = 0; i < s1.length(); i++){
                        for(int j = i; j < s1.length(); j++){
                            for(int k = i ;k < j; k++){
                                hold += s1[k];
                                //cout << endl << hold << endl << cnt;
                                if(hold[k-i] == 'A'){
                                    hold[k-i] = 'T';
                                }else if(hold[k] == 'C'){
                                    hold[k-i] = 'G';
                                }
                            }
                            //cout << endl << hold;
                                for(int l = 0; l < hold.length()/2; l++){
                                    if(hold[l] == hold[hold.length()-1-l]){
                                        continue;
                                }else{
                                    cnt++;
                                }
                                if(cnt = 0 && hold.length() > 1){
                                    cout << endl << hold;
                                }
                                cnt = 0;
                                hold = "";
                            }
                        }
                    }
                }

};

#endif CELL_H_INCLUDED
