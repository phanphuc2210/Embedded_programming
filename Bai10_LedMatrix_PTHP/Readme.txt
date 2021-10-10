Đây là bài thực hành lập trình arduino điều khiển Led matrix sáng lên hình "mặt cười" sử dụng hai con IC 74HC595. Led sẽ 
sáng từ trên xuống dưới và từ trái sang phải. Chân 11(clock) của IC thứ 1 đấu với chân 1 của Arduino, chân 14(input) của IC
thứ 1 đấu với chân 2 của Arduino,và chân 12(latch) của IC thứ 1 đấu với chân 0 của Arduino, IC thứ 1 này dùng để điều khiển 
hàng của LED MATRIX. Còn, Chân 11(clock) của IC 2 đấu với chân 9 của Arduino, chân 14(input) của IC 2 đấu với chân 10 của 
Arduino,và chân 12(latch) của IC thứ 2 đấu với chân 8 của Arduino, IC thứ 2 này dùng để điều khiển cột của LED MATRIX.

