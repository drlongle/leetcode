int removeElement(int a[], int n, int elem) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] != elem) {
                a[count++] = a[i];
            }
        }
        return count;
    }

