Lớp Process
🧾 Thuộc tính (biến thành viên):
-int id: ID (mã định danh) của tiến trình.
-int at: Arrival Time – thời điểm tiến trình đến.
-int bt: Burst Time – thời gian CPU cần để xử lý tiến trình (tổng thời gian).
-int rt: Remaining Time – thời gian còn lại để tiến trình hoàn thành (ban đầu bằng bt, giảm dần).
-int ct: Completion Time – thời điểm tiến trình kết thúc.
-int wt: Waiting Time – thời gian chờ của tiến trình.
-int tat: Turnaround Time – thời gian hoàn thành (TAT = CT - AT).

🧾 Phương thức:
Process(): Hàm khởi tạo mặc định, gán các giá trị ban đầu bằng 0.
void nhapTuBanPhim(): Nhập dữ liệu tiến trình từ bàn phím.
void nhapTuTep(ifstream& fin): Nhập dữ liệu tiến trình từ tệp.
int getID(), getAT(), getBT(), getRT(), getCT(): Các hàm truy xuất giá trị thuộc tính tương ứng.
void giamRT(): Giảm thời gian xử lý còn lại đi 1 đơn vị.
void setCT(int c): Gán giá trị ct (thời điểm hoàn thành).
void tinhWT_TAT(): Tính wt và tat dựa trên ct, at và bt.
void xuat(): In thông tin tiến trình sau khi xử lý xong.

src:chứa code.
SJFP.exe để chạy.
