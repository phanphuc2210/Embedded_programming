Đây là bài thực hành lập trình arduino điều khiển 2 Motor thông qua IC L293D. Hai Motor sẽ chạy về phía trước với tốc độ tối
đa và sau 2 giây sẽ đổi hướng và sau 2 giây nữa sẽ ngừng, tiếp theo sau 1 giây hai motor sẽ tăng tốc từ 0 đến tốc độ tối đa,
và giảm tốc từ tối đa về 0, và lập lại tất cả hoạt động trên sau 1 giây(liên tục). Hai Motor được đấu vào các chân output của
L293D, Chân IN1 của L293D đấu với chân 10 của Arduino, chân IN2 của L293D đấu với chân 9 của Arduino, chân EN1 của L293D đấu 
với chân 8 của Arduino, và Chân IN3 của L293D đấu với chân 6 của Arduino, chân IN4 của L293D đấu với chân 5 của Arduino, chân 
EN2 của L293D đấu với chân 7 của Arduino