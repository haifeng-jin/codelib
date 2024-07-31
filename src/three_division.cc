int three_division(int s, int e) {
  int l = s;
  int r = e;
  while (l < r) {
    int len = r - l;
    int lmid = l + len / 3;
    int rmid = r - len / 3;
    if (cal(lmid) > cal(rmid)) {
      r = rmid - 1;
    } else {
      l = lmid + 1;
    }
  }
  return cal(l);
}
