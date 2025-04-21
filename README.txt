Thành viên nhóm:
1.Nguyễn Văn Định-687582.Nhiệm vụ: Kiểm thử, viết testcase.
2.Đỗ Viết Đức-687585.Nhiệm vụ: Kiểm thử, viết testcase.
3.Hoàng Gia Đức Tâm-687795.Nhiệm vụ: Phân tích thiết kế, xây dựng biểu đồ class.
4.Nguyễn Duy Tân-687797.Nhiệm vụ: Phân tích thiết kế, xây dựng biểu đồ class.
5.Vương Nhật Thành(Nhóm trưởng)-680373.Nhiêm vụ: Lập trình, tổng hợp thông tin và chỉnh sửa từng phần.

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
