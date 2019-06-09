if __name__ == '__main__':
    n = str(raw_input())
    ans = ''
    for ch in n:
        if ch == '1':
            ans += '9'
        else:
            ans += '1'
    print ans
