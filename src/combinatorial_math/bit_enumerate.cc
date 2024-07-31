void enumerate(int bit_num) {
  for (int i = 1; i < (1 << bit_num); i++) {
    // i is the 01-bits sequence
    for (int j = 0; (i >> j) > 0; j++) {
      if ((i >> j) & 1) {
        // the j-th bit is 1
      }
    }
  }
}
