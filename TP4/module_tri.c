void tri_insertion (double* t, int n) {
  int i,j;
  double element;

  for (i = 1; i < n; i++) {
    element = t[i];
    for (j = i; j > 0 && t[j - 1] > element; j--) {
      t[j] = t[j - 1];
    }
    t[j] element;
  }
}
