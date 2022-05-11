def recurrent(digit):
    if digit < 1:
        return 1
    elif digit == 1:
        return -7
    else:
        return int(5*recurrent(digit-1) + 6*recurrent(digit-2))


def solution(digit):
    return int((13*(-1)**digit-6**(digit+1))/7)


value = input('Введите номер элемента: ')
print('Общее решение: ', solution(int(value)))
print('Рекуррентная формула: ', recurrent(int(value)))
