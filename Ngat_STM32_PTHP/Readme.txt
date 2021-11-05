Đây là bài thực hành lập trình trên board mạch STM32, trong bài này sẽ thực hiện lập trình ngắt. Tiến trình chính sẽ liên tục
nhấp nháy 4 Led. Còn trong tiến trình phụ, khi nhấn và thả nút bấm thì sẽ làm cho 1 Led và Motor hoạt động, và nhấn thả nút
thêm lần nữa thì sẽ làm Led và Motor đó ngừng hoạt động. 4 Led của tiến trình chính được đấu vào chân PD0 - PD3 của STM32,
ở tiến trình phụ: nút bấm được đấu vào chân PA0, Led đấu vào chân PA12, và Motor được đấu vào chân PA13 của board mạch STM32.