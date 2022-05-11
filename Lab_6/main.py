from math import log2
input_file = open("input.txt", "r")
# список из списков букв в каждой строке файла
text = list(map(lambda i: list(i.lower()), input_file))
letters = {}
symbol_num = 0
codes = {"5": "1100001011100",
         "#": "1100001011101",
         ")": "11000010110",
         '(': '110000101111',
         '1': '1100001010',
         'j': '110000100',
         'k': '11000011',
         'v': '1100000',
         '"': '1100110',
         ',': '000000',
         '.': '1100111',
         '\n': '000001',
         'p': '011100',
         'g': '011101',
         'b': '100000',
         'f': '100001',
         'y': '110001',
         'w': '110010',
         'm': '110110',
         'c': '110111',
         'u': '00001',
         'l': '01111',
         'd': '10001',
         'r': '11010',
         'h': '0001',
         'n': '0100',
         's': '0101',
         'i': '0110',
         'o': '1001',
         'a': '1010',
         't': '1011',
         'e': '001',
         ' ': '111'}

for i in text:  # находится количество каждой буквы в тексте
    for j in i:
        if j not in letters.keys() and len(letters.keys()) <= 64:
            letters[j] = 1
            symbol_num += 1
        elif j in letters.keys():
            letters[j] += 1
            symbol_num += 1

sorted_list = []  # данные из словаря переносятся в список, чтобы с ними можно было работать
for i in letters.keys():
    sorted_list.append([i, letters[i]])

for i in range(len(sorted_list) - 1):  # список отсортировывается
    for j in range(i, len(sorted_list)):
        if sorted_list[i][1] > sorted_list[j][1]:
            sorted_list[i], sorted_list[j] = sorted_list[j], sorted_list[i]

# добавляется частота
sorted_list = list(
    map(lambda i: [i[0], int(i[1]), i[1] / symbol_num], sorted_list))

for i in range(len(sorted_list)):
    print(sorted_list[i])

shannon = 0
for i in range(len(sorted_list)):
    shannon += (sorted_list[i][2] * log2(sorted_list[i][2]))
    sorted_list.append(codes[sorted_list[i][0]])

output_file = open("output.txt", "w")
new_symbol_num = 0
ones_num = 0
zeros_num = 0
for i in text:
    for j in i:
        new_symbol_num += len(codes[j])
        for k in codes[j]:
            if k == '1':
                ones_num += 1
            else:
                zeros_num += 1
        output_file.write(codes[j])
ones_chance = ones_num / new_symbol_num
zeros_chance = zeros_num / new_symbol_num
new_shannon = ones_chance * \
    log2(ones_chance) + zeros_chance * log2(zeros_chance)
print(f'Старый объём информации - {str(-shannon)}\nНовый объём информации - {str(-new_shannon)}\nCтарое количество бит - {str(symbol_num * 5)}\nНовое количество бит - {str(new_symbol_num)}')
output_file.close()

input_file.close()
