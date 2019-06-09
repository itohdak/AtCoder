if __name__ == '__main__':
    n = int(raw_input())
    v = map(int, raw_input().split(' '))
    print v
    vo = {-1: 0}
    ve = {-1: 0}
    for i in range(n):
        if i % 2 == 0:
            if not vo.has_key(v[i]):
                vo[i] = 1
            else:
                vo[i] += 1
        else:
            if not ve.has_key(v[i]):
                ve[i] = 1
            else:
                ve[i] += 1
        print vo, ve
    sorted(vo.items(), key=lambda x: x[1])
    sorted(ve.items(), key=lambda x: x[1])
    if vo.items()[0][0] == ve.items()[0][0]:
        print("{}".format(min(n-vo.items()[0][1]-ve.items()[1][1],\
                              n-vo.items()[1][1]-ve.items()[0][1])))
    else:
        print("{}".format(n-vo.items()[0][1]-ve.items()[0][1]))



