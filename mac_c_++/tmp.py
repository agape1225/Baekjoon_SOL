
#nunber를 L과 R로 바꿔줌
def get_dir(number, hand):
    get_dir_num()
    pass


def solution(numbers, hand):
    answer = ''
    for number in numbers:
        answer += get_dir(number, hand)

    return answer