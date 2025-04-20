#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
using namespace std;

// === Khai báo lớp Process ===
class Process {
private:
    int id, at, bt, rt, ct, wt, tat;

public:
    Process() : id(0), at(0), bt(0), rt(0), ct(0), wt(0), tat(0) {}

    void nhapTuBanPhim() {
        cout << "ID: "; cin >> id;
        cout << "Arrival Time: "; cin >> at;
        cout << "Burst Time: "; cin >> bt;
        rt = bt;
    }

    void nhapTuTep(ifstream& fin) {
        fin >> id >> at >> bt;
        rt = bt;
    }

    int getID() const { return id; }
    int getAT() const { return at; }
    int getBT() const { return bt; }
    int getRT() const { return rt; }
    int getCT() const { return ct; }

    void giamRT() { rt--; }
    void setCT(int c) { ct = c; }
    void tinhWT_TAT() {
        tat = ct - at;
        wt = tat - bt;
    }

    void xuat() const {
        cout << setw(5) << id << setw(10) << at << setw(10) << bt
             << setw(10) << wt << setw(10) << tat << endl;
    }
};

// === Chương trình chính ===
int main() {
    Process p[100];
    int ganttTime[1000];  // Mảng lưu ID tiến trình theo thời gian
    int ganttLen = 0;
    int n;
    char choice;

    cout<< "Chuong trinh mo ta thuat toan SJF co uu tien bang C++.\n";
    cout << "Ban muon nhap du lieu tu tep khong ? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        char filename[100];
        cout << "Nhap ten tep: ";
        cin >> filename;
        ifstream fin(filename);

        if (!fin) {
            cout << "Khong the mo tep!\n";
            return 1;
        }

        fin >> n;
        for (int i = 0; i < n; i++) {
            p[i].nhapTuTep(fin);
        }

        fin.close();
    } else {
        cout << "Nhap so tien trinh: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Tien trinh " << i + 1 << ":\n";
            p[i].nhapTuBanPhim();
        }
    }

    int completed = 0, time = 0, minIndex;
    bool found;

    while (completed < n) {
        int minBT = 1e9;
        found = false;

        for (int i = 0; i < n; i++) {
            if (p[i].getAT() <= time && p[i].getRT() > 0 && p[i].getRT() < minBT) {
                minBT = p[i].getRT();
                minIndex = i;
                found = true;
            }
        }

        if (!found) {
            time++;
            continue;
        }

        // Lưu ID tiến trình vào biểu đồ Gantt
        ganttTime[ganttLen++] = p[minIndex].getID();

        p[minIndex].giamRT();
        time++;

        if (p[minIndex].getRT() == 0) {
            p[minIndex].setCT(time);
            p[minIndex].tinhWT_TAT();
            completed++;
        }
    }

    // In kết quả
    cout << "\nMo phong thuat toan SJF Preemptive:\n";
    cout << setw(5) << "ID" << setw(10) << "Arrival" << setw(10) << "Burst"
         << setw(10) << "Wait" << setw(10) << "TAT" << endl;

    int tongWT = 0, tongTAT = 0;
    for (int i = 0; i < n; i++) {
        p[i].xuat();
        tongWT += p[i].getCT() - p[i].getAT() - p[i].getBT(); // WT = CT - AT - BT
        tongTAT += p[i].getCT() - p[i].getAT(); // TAT = CT - AT
    }

    cout << fixed << setprecision(2);

    // === In biểu đồ Gantt đơn giản ===
    cout << "\nBieu do Gantt:\n|";
    for (int i = 0; i < ganttLen; i++) {
        cout << "P" << ganttTime[i] << "|";
    }
    cout << "\n0";
    for (int i = 1; i <= ganttLen; i++) {
        cout << setw(3) << i;
    }

    cout << "\nThoi gian cho TB: " << (float)tongWT / n << endl;
    cout << "Thoi gian hoan thanh TB: " << (float)tongTAT / n << endl;

    cout << endl;
    system("pause");

    return 0;
}
