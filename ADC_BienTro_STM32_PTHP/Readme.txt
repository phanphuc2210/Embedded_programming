Đây là bài thực hành lập trình board mạch STM32, bài này sẽ điều khiển động cơ DC thông qua biến trở(chiết áp), khi điều chỉnh 
biến trở và board mạch thu được giá trị(0 - 4095) từ 2049 trở lên thì động cơ sẽ quay, ngược lại sẽ không quay. Biến trở được 
đấu vào chân PA0 và động cơ DC sẽ được đấu vào chân PD0 của STM32.