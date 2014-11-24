/*
 n mm 進む。
*/
void step(int n) {
  // 内容省略。以前の資料を見るべし。
}

/*
 みんなが完成させたライントレースプログラム。
 ただし、黒黒を見たとき、プログラム終了しない。
 5mm 進みながらライントレースするように直しとけ。
*/
void line_trace(void) {
  while (true) {
    if (left_is_white() && right_is_white()) {
      step(5);
    } else if (left_is_black() && right_is_black()) {
      break;
    } else if (left_is_black()) {
      turn_left();
    } else if (right_is_black()) {
      turn_right();
    }
    return;
}

int main(void) {
  // 部分省略。いつもと一緒のやつ。

  int n;
  while (true) {
    line_trace();
    
}

  
  
