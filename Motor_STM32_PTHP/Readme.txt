Đây là bài thực hành lập trình trên board mạch STM32 điều khiển 2 Motor thông qua IC L239D. Hai Motor sẽ chạy về phía trước 
với tốc độ tối đa và sau 2 giây sẽ đổi hướng và sau 2 giây nữa sẽ ngừng, tiếp theo sau 1 giây hai motor sẽ tăng tốc từ 0 đến 
tốc độ tối đa, và giảm tốc từ tối đa về 0, và lập lại tất cả hoạt động trên sau 1 giây(liên tục). Hai Motor được đấu vào các 
chân output của L239D, Chân IN1 của L239D đấu với chân PD10 của STM32, chân IN2 của L239D đấu với chân PD11 của STM32, chân 
EN1 của L239D đấu với chân PD12 của STM32, và Chân IN3 của L239D đấu với chân PD14 của STM32, chân IN4 của L239D đấu với chân 
PD15 của STM32, chân EN2 của L239D đấu với chân PD13 của STM32.