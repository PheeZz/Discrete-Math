array = list('комбинаторика')
nn = len(array)
j, k, l, m, n = 0, 0, 0, 0, 0
words = []
for i in range(nn):
    while j < nn:
        while k < nn:
            while l < nn:
                while m < nn:
                    while n < nn:
                        words.append(array[i]+array[j] +
                                     array[k]+array[l]+array[m]+array[n])
                        n += 1
                    n = 0
                    m += 1
                m = 0
                l += 1
            l = 0
            k += 1
        k = 0
        j += 1
    j = 0
print(words)
print('Количество слов: ', len(words))
