#include "node.cpp"

class DanhSachCanBo {
private:
    Node* head;
    int size;

public:
    DanhSachCanBo() {
        head = NULL;
        size = 0;
    }

    ~DanhSachCanBo() {
        Node* current = head;
        while(current != NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void nhapDS() {
        int ma;
        string ho, ten, pb, cv;
        float hsl;

        while(true) {
            cout << "Nhap ma can bo (0 de ket thuc): ";
            cin >> ma;
            if(ma <= 0) break;

            cout << "Nhap ho dem: ";
            cin.ignore();
            getline(cin, ho);
            cout << "Nhap ten: ";
            getline(cin, ten);
            cout << "Nhap phong ban: ";
            getline(cin, pb);
            cout << "Nhap chuc vu: ";
            getline(cin, cv);
            cout << "Nhap he so luong: ";
            cin >> hsl;

            Node* newNode = new Node(ma, ho, ten, pb, cv, hsl);
            newNode->next = head;
            head = newNode;
            size++;
        }
    }

    void xuatDS() {
        cout << left << setw(10) << "Ma CB" 
             << setw(20) << "Ho dem"
             << setw(15) << "Ten"
             << setw(20) << "Phong ban"
             << setw(20) << "Chuc vu"
             << setw(15) << "He so luong"
             << setw(15) << "Luong" << endl;

        Node* current = head;
        while(current != NULL) {
            cout << left << setw(10) << current->maCanBo 
                 << setw(20) << current->hoDem
                 << setw(15) << current->ten
                 << setw(20) << current->phongBan
                 << setw(20) << current->chucVu
                 << setw(15) << current->heSoLuong
                 << setw(15) << current->heSoLuong * 1350000 << endl;
            current = current->next;
        }
    }

    void themCanBo(int ma, string ho, string ten, string pb, string cv, float hsl, int pos) {
        Node* newNode = new Node(ma, ho, ten, pb, cv, hsl);

        if(pos <= 0 || head == NULL) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            int count = 0;
            while(count < pos-1 && current->next != NULL) {
                current = current->next;
                count++;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        size++;
    }

    void inCanBoHeSoLuongCao() {
        Node* current = head;
        while(current != NULL) {
            if(current->heSoLuong >= 4.4) {
                cout << left << setw(10) << current->maCanBo 
                     << setw(20) << current->hoDem
                     << setw(15) << current->ten
                     << setw(20) << current->phongBan
                     << setw(20) << current->chucVu
                     << setw(15) << current->heSoLuong
                     << setw(15) << current->heSoLuong * 1350000 << endl;
            }
            current = current->next;
        }
    }

    void timTheoChucVu(string cv) {
        Node* current = head;
        while(current != NULL) {
            if(current->chucVu == cv) {
                cout << left << setw(10) << current->maCanBo 
                     << setw(20) << current->hoDem
                     << setw(15) << current->ten
                     << setw(20) << current->phongBan
                     << setw(20) << current->chucVu
                     << setw(15) << current->heSoLuong
                     << setw(15) << current->heSoLuong * 1350000 << endl;
            }
            current = current->next;
        }
    }

    void timTheoHeSoLuongVaPhongBan(float hsl, string pb) {
        Node* current = head;
        while(current != NULL) {
            if(current->heSoLuong == hsl && current->phongBan == pb) {
                cout << left << setw(10) << current->maCanBo 
                     << setw(20) << current->hoDem
                     << setw(15) << current->ten
                     << setw(20) << current->phongBan
                     << setw(20) << current->chucVu
                     << setw(15) << current->heSoLuong
                     << setw(15) << current->heSoLuong * 1350000 << endl;
            }
            current = current->next;
        }
    }
    
    void thongKeTheoPhongBan() {
    string pb;
    float hsl;
    bool found = false;
    
    cout << "Nhap phong ban can thong ke: ";
    cin.ignore();
    getline(cin, pb);
    cout << "Nhap he so luong: ";
    cin >> hsl;
    
    cout << "\nDanh sach can bo thuoc phong ban " << pb << " va co he so luong " << hsl << ":\n";
    cout << left << setw(10) << "Ma CB" 
         << setw(20) << "Ho dem"
         << setw(15) << "Ten"
         << setw(20) << "Phong ban"
         << setw(20) << "Chuc vu"
         << setw(15) << "He so luong"
         << setw(15) << "Luong" << endl;
         
    Node* current = head;
    while(current != NULL) {
        if(current->phongBan == pb && current->heSoLuong == hsl) {
            cout << left << setw(10) << current->maCanBo 
                 << setw(20) << current->hoDem
                 << setw(15) << current->ten
                 << setw(20) << current->phongBan
                 << setw(20) << current->chucVu
                 << setw(15) << current->heSoLuong
                 << setw(15) << current->heSoLuong * 1350000 << endl;
            found = true;
        }
        current = current->next;
    }
    
    if(!found) {
        cout << "\nKhong tim thay can bo nao thoa man dieu kien!\n";
    }
}

    void sapXepTheoTen() {
        if(head == NULL || head->next == NULL) return;

        bool swapped;
        Node* ptr1;
        Node* lptr = NULL;

        do {
            swapped = false;
            ptr1 = head;

            while(ptr1->next != lptr) {
                if(ptr1->ten > ptr1->next->ten) {
                    swap(ptr1->maCanBo, ptr1->next->maCanBo);
                    swap(ptr1->hoDem, ptr1->next->hoDem);
                    swap(ptr1->ten, ptr1->next->ten);
                    swap(ptr1->phongBan, ptr1->next->phongBan);
                    swap(ptr1->chucVu, ptr1->next->chucVu);
                    swap(ptr1->heSoLuong, ptr1->next->heSoLuong);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while(swapped);
    }
};
