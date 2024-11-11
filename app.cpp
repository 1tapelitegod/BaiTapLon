#include "danhsachcanbo.cpp"
#include <conio.h>
#include <windows.h>

class QuanLyCanBo {
private:
    DanhSachCanBo ds;
    
    void clearScreen() {
        system("cls");
    }
    
    void waitKey() {
        cout << "\nNhan phim bat ky de tiep tuc...";
        _getch();
    }

    void printHeader() {
        cout << "\n============================================\n";
        cout << "     CHUONG TRINH QUAN LY CAN BO           \n";
        cout << "============================================\n";
    }

    void printMenu() {
        cout << "\n=== MENU CHUC NANG ===\n";
        cout << "1. Nhap danh sach can bo\n";
        cout << "2. Xuat danh sach can bo\n";
        cout << "3. Them can bo moi\n";
        cout << "4. Tim kiem can bo\n";
        cout << "5. Thong ke bao cao\n";
        cout << "6. Sap xep danh sach\n";
        cout << "0. Thoat chuong trinh\n";
    }

    void subMenuTimKiem() {
        int choice;
        do {
            clearScreen();
            cout << "\n=== MENU TIM KIEM ===\n";
            cout << "1. Tim theo chuc vu\n";
            cout << "2. Tim theo he so luong va phong ban\n";
            cout << "0. Quay lai menu chinh\n";
            cout << "Nhap lua chon: ";
            cin >> choice;

            switch(choice) {
                case 1: {
                    string cv;
                    cout << "Nhap chuc vu can tim: ";
                    cin.ignore();
                    getline(cin, cv);
                    ds.timTheoChucVu(cv);
                    waitKey();
                    break;
                }
                case 2: {
                    float hsl;
                    string pb;
                    cout << "Nhap he so luong: ";
                    cin >> hsl;
                    cout << "Nhap phong ban: ";
                    cin.ignore();
                    getline(cin, pb);
                    ds.timTheoHeSoLuongVaPhongBan(hsl, pb);
                    waitKey();
                    break;
                }
            }
        } while(choice != 0);
    }

    void subMenuThongKe() {
        int choice;
        do {
            clearScreen();
            cout << "\n=== MENU THONG KE ===\n";
            cout << "1. Danh sach can bo co he so luong >= 4.4\n";
            cout << "2. Thong ke theo phong ban\n";
            cout << "0. Quay lai menu chinh\n";
            cout << "Nhap lua chon: ";
            cin >> choice;

            switch(choice) {
                case 1:
                    ds.inCanBoHeSoLuongCao();
                    waitKey();
                    break;
                case 2:
                    thongKeTheoPhongBan();
                    waitKey();
                    break;
            }
        } while(choice != 0);
    }

    void thongKeTheoPhongBan() {
    	ds.thongKeTheoPhongBan();
	}

    void subMenuSapXep() {
        int choice;
        do {
            clearScreen();
            cout << "\n=== MENU SAP XEP ===\n";
            cout << "1. Sap xep theo ten\n";
            cout << "2. Sap xep theo he so luong\n";
            cout << "0. Quay lai menu chinh\n";
            cout << "Nhap lua chon: ";
            cin >> choice;

            switch(choice) {
                case 1:
                    ds.sapXepTheoTen();
                    cout << "Da sap xep xong!\n";
                    waitKey();
                    break;
                case 2:
                    cout << "Chuc nang dang phat trien...\n";
                    waitKey();
                    break;
            }
        } while(choice != 0);
    }

public:
    void run() {
        int choice;
        do {
            clearScreen();
            printHeader();
            printMenu();
            cout << "\nNhap lua chon cua ban: ";
            cin >> choice;

            switch(choice) {
                case 1:
                    clearScreen();
                    cout << "=== NHAP DANH SACH CAN BO ===\n";
                    ds.nhapDS();
                    break;
                
                case 2:
                    clearScreen();
                    cout << "=== DANH SACH CAN BO ===\n";
                    ds.xuatDS();
                    waitKey();
                    break;
                
                case 3: {
                    clearScreen();
                    cout << "=== THEM CAN BO MOI ===\n";
                    int ma, pos;
                    string ho, ten, pb, cv;
                    float hsl;
                    
                    cout << "Nhap ma can bo: ";
                    cin >> ma;
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
                    cout << "Nhap vi tri muon them: ";
                    cin >> pos;
                    
                    ds.themCanBo(ma, ho, ten, pb, cv, hsl, pos);
                    cout << "Them can bo thanh cong!\n";
                    waitKey();
                    break;
                }
                
                case 4:
                    subMenuTimKiem();
                    break;
                
                case 5:
                    subMenuThongKe();
                    break;
                
                case 6:
                    subMenuSapXep();
                    break;
            }
        } while(choice != 0);

        cout << "\nCam on ban da su dung chuong trinh!\n";
    }
};
