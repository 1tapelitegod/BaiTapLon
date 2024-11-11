#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Node {
    int maCanBo;
    string hoDem;
    string ten;
    string phongBan;
    string chucVu;
    float heSoLuong;
    Node* next;
    
    Node(int ma = 0, string ho = "", string t = "", string pb = "", 
         string cv = "", float hsl = 0) {
        maCanBo = ma;
        hoDem = ho;
        ten = t;
        phongBan = pb;
        chucVu = cv; 
        heSoLuong = hsl;
        next = NULL;
    }
};
