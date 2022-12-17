void merge(vector<int> vec, int l, int m, int r) {
  int n1 = m - l + 1, n2 = r - m;
  int left[n1], right[n2];
  for (int i = 0; i < n1; i++)
    left[i] = vec[l + i];
  for (int j = 0; j < n2; j++)
    right[j] = vec[m + 1 + j];
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (left[i] <= right[j]) {
      vec[k] = left[i];
      i++;
    } else {
      vec[k] = right[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    vec[k] = left[i];
    i++;
    k++;
  }
  while (j < n2) {
    vec[k] = right[j];
    j++;
    k++;
  }
}
void merge_sort(vector<int> vec, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    merge_sort(vec, l, m);
    merge_sort(vec, m + 1, r);
    merge(vec, l, m, r);
  }
}