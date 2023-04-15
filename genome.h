#ifndef GENOME_H_INCLUDED
#define GENOME_H_INCLUDED
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

string to_upper(string a){
    string b;
    for(int i = 0; i < a.length(); i++){
        b += " ";
        b[i] = toupper(a[i]);
    }
    return b;
}

class Genome{
public:
    string rna;
    string dna[2];
    void set_rna(string a){
        rna = to_upper(a);
    }
    void set_dna(string a, string b){
        dna[0] = to_upper(a);
        dna[1] = to_upper(b);
    }
    void dna_built_by_rna(){
        string b;
        int m = 0;
        for(int i = 0; i < rna.length(); i++){
            if(rna[i] == 'A'){
                b += 'T';
            }else if(rna[i] == 'T'){
                b += 'A';
            }else if(rna[i] == 'C'){
                b += 'G';
            }else if(rna[i] == 'G'){
                b += 'C';
            }else{
                m++;
            }
        }
        if(m > 0){
            cout << "invalid rna" << endl;
        }else{
            cout << b << endl;
        }
    }
    string small_mutation(char a, char b, int n){
        a = toupper(a);
        b = toupper(b);
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < rna.length(); i++){
            if(cnt1 < n){
                if(rna[i] == a){
                    rna[i] = b;
                    cnt1++;
                }
            }
        }
        for(int i = 0; i < dna[0].length(); i++){
            if(cnt2 < n){
                if(dna[0][i] == a){
                    dna[0][i] = b;
                    if(a == 'A' && dna[1][i] == 'A'){
                        dna[1][i] = 'T';
                    }else if(a == 'T' && dna[1][i] == 'T'){
                        dna[1][i] = 'A';
                    }else if(a == 'C' && dna[1][i] == 'C'){
                        dna[1][i] = 'G';
                    }else if(a == 'G' && dna[1][i] == 'G'){
                        dna[1][i] = 'C';
                    }
                    cnt2++;
                }
            }
            if(cnt2 < n){
                if(dna[1][i] == a){
                    dna[1][i] = b;
                    if(a == 'A' && dna[0][i] == 'A'){
                        dna[0][i] = 'T';
                    }else if(a == 'T' && dna[0][i] == 'T'){
                        dna[0][i] = 'A';
                    }else if(a == 'C' && dna[0][i] == 'C'){
                        dna[0][i] = 'G';
                    }else if(a == 'G' && dna[0][i] == 'G'){
                        dna[0][i] = 'C';
                    }
                        cnt2++;
                }
            }
        }
    }
    void big_mutation(string s1, string s2){
        s1 = to_upper(s1);
        s2 = to_upper(s2);
        string s3, s4;
        int cnt = 0;
        int* keep = &cnt;
        if(rna.find(s1) != string::npos){
            *keep = rna.find(s1);
            for(int i = rna.find(s1); i < rna.find(s1)+s1.length(); i++){
                rna.erase(i);
            }
            for(int i = cnt; i < cnt+s2.length(); i++){
                rna[i] += s2[i-cnt];
            }
        }else{
            cout << "no match in rna" << endl;
        }
        if(dna[0].find(s1) < dna[1].find(s1)){
            if(dna[0].find(s1) != string::npos){
                *keep = dna[0].find(s1);
                for(int i = cnt; i < cnt+s2.length(); i++){
                    dna[0][i] = s2[i-cnt];
                }
                for(int i = 0; i < s2.length(); i++){
                    if(s2[i] == 'A'){
                        s3 += 'T';
                    }else if(s2[i] == 'T'){
                        s3 += 'A';
                    }else if(s2[i] == 'C'){
                        s3 += 'G';
                    }else if(s2[i] == 'G'){
                        s3 += 'C';
                    }
                }
                for(int i = cnt; i < cnt+s2.length(); i++){
                    dna[1][i] = s3[i-cnt];
                }
                cout << dna[0] << endl << dna[1];
            }else{
                cout << "no match in dna1";
            }
        }else{
            if(dna[1].find(s1) != string::npos){
                *keep = dna[1].find(s1);
                cout << dna[1] << endl;
                //  baraye maghadir nabarabar ham dorost kon
                for(int i = cnt; i < cnt+s2.length(); i++){
                    dna[1][i] = s2[i-cnt];
                    cout << s2[i-cnt] << endl << dna[1] << endl;
                }
                for(int i = 0; i < s2.length(); i++){
                    if(s2[i] == 'A'){
                        s4 += 'T';
                    }else if(s2[i] == 'T'){
                        s4 += 'A';
                    }else if(s2[i] == 'C'){
                        s4 += 'G';
                    }else if(s2[i] == 'G'){
                        s4 += 'C';
                    }
                }
                for(int i = cnt; i < cnt+s2.length(); i++){
                    dna[0][i] = s4[i-cnt];
                }
                cout << endl << dna[0];
            }else{
                cout << "no match in dna2";
            }
        }
    }
    string reverse_mutation(string s1){
        s1 = to_upper(s1);
        int cnt = 0;
        int* keep = &cnt;
        string s2, s3, s4;
        if(rna.find(s1) != string::npos){
            *keep = rna.find(s1);
            for(int i = cnt+s1.length()-1; i >= cnt; i--){
                s2 += rna[i];
                rna.erase(i);
            }
            for(int i = cnt; i < cnt+s2.length(); i++){
                    rna[i] += s2[i-cnt];
                }
        }else{
            cout << "no match in rna" << endl;
        }
        if(dna[0].find(s1) < dna[1].find(s1)){
            if(dna[0].find(s1) != string::npos){
                *keep = dna[0].find(s1);
                for(int i = cnt+s1.length()-1; i >= cnt; i--){
                    s3 += dna[0][i];
                }
                for(int i = cnt; i < cnt+s1.length(); i++){
                    dna[0][i] = s3[i-cnt];
                }
                cout << dna[0];
            }else{
                cout << "no match in dna1";
            }
        }else{
            if(dna[1].find(s1) != string::npos){
                *keep = dna[1].find(s1);
                for(int i = cnt+s1.length()-1; i >= cnt; i--){
                    s4 += dna[1][i];
                }
                for(int i = cnt; i < cnt+s1.length(); i++){
                    dna[1][i] = s4[i-cnt];
                }
                cout << dna[1];
            }else{
                cout << "no match in dna2";
            }
        }
    }
};


#endif GENOME_H_INCLUDED
