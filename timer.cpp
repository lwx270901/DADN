#include "timer.h"

int timer2_counter = 10;
int timer2_flag = 1;

int TIMER_CYCLE = 10;



void setTimer2(int duration)
{
  timer2_counter = duration / TIMER_CYCLE;
  timer2_flag = 0;
}

void timer2_run()
{
  if( timer2_counter > 0)
  {
    timer2_counter --;
    if( timer2_counter == 0) timer2_flag = 1;
  }
  button_reading();
  void increase_timer();
}

ISR (TIMER2_OVF_vect) // Su dung cho nut nhan
{
  timer2_run();
  TCNT2 = 100;
}

void timer_init()
{
  cli(); //Tắt ngắt toàn cục
  TCCR2A = 0; //Reset Timer2
  TCCR2B = 0;      
  TIMSK2 = 0;
  //Setup Timer2 10ms
  TCCR2B |= (1 << CS22)|(1 << CS21)|(1 << CS20) ; //Chọn prescaler 1024 CS22=1,CS21=1, CS20=1 xem bảng phía trên
  TCNT2 = 100; //Giá trị tính toán phía trên
  TIMSK2 |= (1 << TOIE2); //Overflow interrupt enable
  sei(); //Cho phép ngắt toàn cục
}
