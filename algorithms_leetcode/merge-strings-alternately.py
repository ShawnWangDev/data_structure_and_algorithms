from itertools import zip_longest


def mergeAlternately(word1: str, word2: str) -> str:
    ans = []
    for x, y in zip_longest(word1, word2):
        if x: ans.append(x)
        if y: ans.append(y)
    return ''.join(ans)


def mergeAlternatelyOneLine(word1: str, word2: str) -> str:
    return ''.join([x + y for x, y in zip_longest(word1, word2, fillvalue='')])


if __name__ == '__main__':
    test_cases = [['abc', 'xyz'], ['12345', 'ab'], ['abcdefghijk', '12345']]
    print('--- mergeAlternately ---')
    for test_case in test_cases:
        print(mergeAlternately(*test_case))
    print('\n--- mergeAlternatelyOneLine ---')
    for test_case in test_cases:
        print(mergeAlternatelyOneLine(*test_case))
