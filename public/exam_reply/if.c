while (1) {
  if (is_left_black() && is_right_black()) {
    break;
  } else {
    ;
  }
  if (is_left_whilte() && is_right_white()) {
    go_straight();
  } else {
    ;
  }
  if (is_left_black()) {
    turn_left();
  } else {
    ;
  }
  if (is_right_black()) {
    turn_right();
  } else {
    ;
  }
}

while (1) {
  if (is_left_black() && is_right_black()) {
    break;
  } else if (is_left_whilte() && is_right_white()) {
    go_straight();
  } else if (is_left_black()) {
    turn_left();
  } else  if (is_right_black()) {
    turn_right();
  } else {
    ;
  }
}
