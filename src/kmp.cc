
void kmp(char st[], int fail[]) {
  fail[0] = -1;
  if (st[0] == 0) return;
  for (int i = 0; st[i + 1]; i++) {
    int pre = fail[i];
    while (pre >= 0 && st[pre + 1] != st[i + 1]) {
      pre = fail[pre];
    }
    if (st[pre + 1] == st[i + 1])
      fail[i + 1] = pre + 1;
    else
      fail[i + 1] = -1;
  }
}
